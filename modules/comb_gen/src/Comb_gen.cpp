// Copyright 2023 Shaposhnikova Ekaterina

#include "include/Comb_gen.h"

std::vector<int> CombGen::NextComb(std::vector<int> comb) {
  int i;
  std::vector<int> combErr;
  auto iter = combErr.cbegin();
  combErr.insert(iter, this->K, -1);
  for (i = this->K - 1; i > -1 && comb[i] >= this->N - 1;) {
    i--;
  }
  if (i == -1) {
    return combErr;
  }
  comb[i]++;
  for (int j = i + 1; j < this->K; j++) {
    comb[j] = comb[i];
  }
  return comb;
}

void CombGen::CombGenerate() {
  std::vector<int> comb(this->K);
  std::vector<int> combErr;
  auto iter = combErr.cbegin();
  combErr.insert(iter, this->K, -1);
  for (int i = 0; i < this->K; i++) {
    comb[i] = 0;
  }
  while (comb != combErr) {
    std::vector<int> combCopy;
    for (int i = 0; i < this->K; i++) {
      combCopy.push_back(VecIn[comb[i]]);
    }
    VecOut.push_back(combCopy);
    Count++;
    comb = NextComb(comb);
  }
}
