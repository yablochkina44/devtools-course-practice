// Copyright 2023 Yurin Evgeny

#pragma once

#include <string>

class EncoderApplication {
 public:
    EncoderApplication() = default;

    EncoderApplication(const EncoderApplication &ca) = delete;

    EncoderApplication(EncoderApplication &&ca) = delete;

    std::string operator()(int argc,
                           const char **argv);

 private:
    void help(const char *appname);

    bool validateArguments(int argc,
                           const char **argv);

    std::string m_message;
};
