// Copyright 2023 Lebedinskiy Ilya

#include <exception>
#include <iostream>
#include <stack>
#include <string>

#include "include/lex.h"
#include "include/pol_not.h"
#include "include/rev_pol_app.h"
#include "include/stack.h"

std::string Application::operator()(int argc, const char* argv[]) {
    if (argc == 1 || argc > 2) {
        return this->help(argv[0]);
    }
    std::string output{};
    PolNot l1;
    TQueue<Lex*>* lex = new TQueue<Lex*>;
    std::string str;
    if (argc == 2) {
        str = argv[1];
        lex = l1.sEOL(str);
        output = l1.revPolNot(lex);
    }
    delete lex;
    return output;
}

std::string Application::help(const char* appname) {
    return std::string { "Revers Polish notation\nUsage: " }
        + std::string { appname }
    + std::string { " Enter problem <problem>\n        No limits" };
}
