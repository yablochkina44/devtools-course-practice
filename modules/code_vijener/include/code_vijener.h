// Copyright 2023 Kosterin Alexey

#ifndef MODULES_CODE_VIJENER_INCLUDE_CODE_VIJENER_H_
#define MODULES_CODE_VIJENER_INCLUDE_CODE_VIJENER_H_

#include <string>
#include <algorithm>

class Code_vijener {
 public:
  Code_vijener();
  Code_vijener(const std::string _code_str, const std::string _key);
  Code_vijener(const Code_vijener& buf);

  const std::string& GetKey();
  const std::string& GetCodeStr();

  void SetKey(const std::string _key);
  void SetCodeStr(const std::string _code_str);
  int KeyCode(char s);

  // ~Code_vijener();
  std::string Encoder();
  std::string Decoder();

 private:
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string code_str, key;
};



#endif  // MODULES_CODE_VIJENER_INCLUDE_CODE_VIJENER_H_
