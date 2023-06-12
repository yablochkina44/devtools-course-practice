// Copyright Simeunovic Aleksandar 2023

#include"include/Comb_gen_app.h"
#include<vector>
#include<exception>

CombGenApp::CombGenApp():message("") {}

std::string CombGenApp::help(std::string add_message) {
    std::string out_message = add_message;
    if (out_message != "")out_message += "\n\n";
    out_message.append("This is combination generator application\n\n").
        append("Format of input:<number of elements of input vector(n)>,").
        append("<number of element in combination(k)>").
        append("<n numbers,elements of vector(VecIn)");
    return out_message;
}

bool CombGenApp::parseInput(int argc, const char** argv,
int* n, int* k, std::vector<int>* VecIn) {
    try {
        if (argc == 1)throw std::invalid_argument("No command line arguments!");
        *n = std::stoi(argv[1]);
        if (*n <= 0)throw std::invalid_argument("n must be positive number!");
        if (argc - 3 != *n)
        throw std::invalid_argument
        ("Number of elements in vector should be equal n!");
        *k = std::stoi(argv[2]);
        if (*k<1 || *k>*n)
        throw std::invalid_argument("K should be between 1 and N!");
        for (int i = 0; i < *n; i++) {
            int elem = std::stoi(argv[3 + i]);
            (*VecIn).push_back(elem);
        }
    }
    catch (std::invalid_argument& exc) {
        message = help(exc.what());
        return false;
    }
    return true;
}

std::string CombGenApp::operator()(int argc, const char** argv) {
    int n, k;
    std::vector<int>VecIn;
    if (!parseInput(argc, argv, &n, &k, &VecIn))return message;
    CombGen comb_gen(n, k);
    comb_gen.setVecIn(VecIn);
    comb_gen.CombGenerate();
    message += "Out:\n";
    std::vector<std::vector<int> >VecOut = comb_gen.getVecOut();
    for (auto vectors_it = VecOut.begin();
    vectors_it != VecOut.end(); vectors_it++) {
        for (auto it = (*vectors_it).begin(); it != (*vectors_it).end(); it++) {
            message+=std::to_string(*it)+" ";
        }
        message+="\n";
    }
    return message;
}
