// Copyright 2023 Binko Alexandr

#ifndef MODULES_KONVERTERFR_INCLUDE_KONVERTERFR_APPLICATION_H_
#define MODULES_KONVERTERFR_INCLUDE_KONVERTERFR_APPLICATION_H_

#include <string>

class KonverterApplication {
 public:
  std::string operator()(int argc, const char **argv);

 private:
  std::string help();
  bool IsValid(int argc, const char **argv);
  std::string validatorMessage;
  const std::string allowedAlphabet = "MCDXLVI";
  const std::string allowedNumbers = "0123456789";
};

#endif  // MODULES_KONVERTERFR_INCLUDE_KONVERTERFR_APPLICATION_H_
