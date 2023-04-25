const http = require('http');
const { Octokit } = require("@octokit/core");
const { createAppAuth } = require("@octokit/auth-app");

const port = process.env.PORT || 80;

const installationOctokit = new Octokit({
    authStrategy: createAppAuth,
    auth: {
      appId: 318270,
      privateKey: process.env.PRIVATE_KEY,
      installationId: 36435735,
    },
});

async function putLabNumber(pull_id) {
    const pullInfo = await installationOctokit.request("GET /repos/{owner}/{repo}/pulls/{pull_id}", {
        owner: "Teddy-Hackers",
        repo: "devtools-course-practice",
        pull_id: pull_id,
    });

    let task_id = pullInfo.data.title.match(/\d+/);
    if (!task_id)
        return;

    task_id = parseInt(task_id[0]);
    if (task_id < 1 || task_id > 3)
        return;

    const pullFiles = await installationOctokit.request("GET /repos/{owner}/{repo}/pulls/{pull_id}/files", {
        owner: "Teddy-Hackers",
        repo: "devtools-course-practice",
        pull_id: pull_id,
    });

    if (pullFiles.data.length == 0 ||
        pullFiles.data.length == 1 && pullFiles.data[0].filename == "lab-guide/topics.md") {
        return;
    }
    installationOctokit.request("POST /repos/{owner}/{repo}/issues/{pull_id}/labels", {
        owner: "Teddy-Hackers",
        repo: "devtools-course-practice",
        pull_id: pull_id,
        labels: ["lab " + task_id],
    });
}

async function checkReadiness(pull_id) {
    // Count number of unique approvers
    const result = await installationOctokit.request("GET /repos/{owner}/{repo}/pulls/{pull_id}/reviews", {
        owner: "Teddy-Hackers",
        repo: "devtools-course-practice",
        pull_id: pull_id,
    });

    let approvers = new Set();
    result.data.forEach(entry => {
        if (entry.state == 'APPROVED') {
            approvers.add(entry.user.login);
        }
    });

    if (approvers.size < 2)
        return;

    // Put a readiness label
    installationOctokit.request("POST /repos/{owner}/{repo}/issues/{pull_id}/labels", {
        owner: "Teddy-Hackers",
        repo: "devtools-course-practice",
        pull_id: pull_id,
        labels: ["Ready for merge"],
    });
}

// Put labels to existing pull requests
// installationOctokit.paginate(installationOctokit.rest.pulls.list, {
//     owner: "Teddy-Hackers",
//     repo: "devtools-course-practice",
//     state: "all",
//     sort: "created",
//     direction: "asc",
// })
// .then(pulls => {
//     pulls.forEach(pull => {
//         putLabNumber(pull.number);
//     });
// });

http.createServer(function (req, res) {
    // Get JSON data for POST request
    let body = '';
    req.on('data', chunk => {
        body += chunk.toString();
    });
    req.on('end', () => {
        try {
            body = JSON.parse(body);
            putLabNumber(body.pull_request.number);
            if (body.review.state == "approved") {
                checkReadiness(body.pull_request.number);
            }
        } catch(error) {
            console.log(body);
            console.log(error.message);
        }
        res.end();
    });
}).listen(port);
