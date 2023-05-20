// Copyright 2023 Kudryashov Nikita

#include "include/longest_common_subsequence.h"
#include "include/longest_common_subsequence_app.h"
#include<sstream>
#include<cstring>

LongestCommonSubsequenceApp::LongestCommonSubsequenceApp() : message_("") {}

void LongestCommonSubsequenceApp::help(const char* appname,
                                       const char* message) {
    message_ =
        std::string(message) +
        "This application finds the longest common" +
        "subsequence of two vectors.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <vec1_size><vec2_size> " +
        " <vec1_value_1>...<vec1_value_size> "+
        " <vec2_value_1>...<vec2_value_size>\n\n" +

        "Where all arguments are integer numbers.\n";
}

bool LongestCommonSubsequenceApp::validateNumberOfArguments(int argc,
                                                            const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 3) {
        help(argv[0], "ERROR: Shoud be at least 2 arguments\n\n");
        return false;
    } else if ((atoi(argv[1]) == 0 && strcmp(argv[1], "0"))
                || (atoi(argv[2]) == 0 && strcmp(argv[2], "0"))) {
        help(argv[0], "ERROR: Size is not a number!\n\n");
        return false;
    } else if (atoi(argv[1]) + atoi(argv[2]) != argc - 3) {
        help(argv[0], (std::string("ERROR: Should be ")
            + std::to_string(atoi(argv[1]) + atoi(argv[2]) + 2)
            + std::string(" arguments.\n\n")).c_str());
        return false;
    }
    return true;
}

int charToInt(const char* c, const char* appname) {
    int res = atoi(c);

    if (res == 0 && strcmp(c, "0")) {
        throw std::string("There is not a number among the elements");
    }

    return res;
}

std::string LongestCommonSubsequenceApp::operator()(int argc,
                                                    const char** argv) {
    std::vector<int> vec1;
    std::vector<int> vec2;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        for (int i = 3; i < atoi(argv[1]) + 3; i++) {
            int num = charToInt(argv[i], argv[0]);
            vec1.push_back(num);
        }
        for (int i = atoi(argv[1]) + 3;
            i < atoi(argv[1]) + 3 + atoi(argv[2]);
            i++) {
            int num = charToInt(argv[i], argv[0]);
            vec2.push_back(num);
        }
    }
    catch (std::string& str) {
        return str;
    }

    std::vector<int> res = get_longest_common_subsequence(vec1, vec2);

    std::ostringstream stream;

    for (size_t i = 0; i < res.size(); i++) {
        stream << res[i] << " ";
    }

    message_ = stream.str();

    return message_;
}
