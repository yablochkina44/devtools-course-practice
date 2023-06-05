// Copyright 2023 Shaposhnikova Ekaterina

#include <gtest/gtest.h>
#include "include/Comb_gen.h"

TEST(Shaposhnikova, test_constructor) {
  CombGen* c = new CombGen(4, 3);
  ASSERT_EQ(c->getN(), 4);
  ASSERT_EQ(c->getK(), 3);
}

TEST(Shaposhnikova, no_throw_comb_generate) {
  CombGen* c = new CombGen(4, 3);
  std::vector<int> vec = { 1, 2, 3, 4 };
  c->setVecIn(vec);

  ASSERT_NO_THROW(c->CombGenerate());
}

TEST(Shaposhnikova, count_VecOut_size) {
  CombGen* c = new CombGen(4, 3);
  std::vector<int> vec = { 1, 2, 3, 4 };
  c->setVecIn(vec);
  c->CombGenerate();
  int a = c->factorial(c->getN() + c->getK() - 1);
  int b = c->factorial(c->getK()) * c->factorial(c->getN() - 1);
  int vecSize =  a/b;

  ASSERT_EQ(vecSize, c->getCount());
}

TEST(Shaposhnikova, test_first_seq) {
  CombGen* c = new CombGen(4, 3);
  std::vector<int> vec = { 1, 2, 3, 4 };
  c->setVecIn(vec);
  c->CombGenerate();
  std::vector<int> vec1 = { 1, 1, 1 };

  ASSERT_EQ(vec1, c->VecOut[0]);
}

TEST(Shaposhnikova, test_last_seq) {
  CombGen* c = new CombGen(4, 3);
  std::vector<int> vec = { 1, 2, 3, 4 };
  c->setVecIn(vec);
  c->CombGenerate();
  std::vector<int> vec1 = { 4, 4, 4 };

  ASSERT_EQ(vec1, c->VecOut[c->VecOut.size()-1]);
}

TEST(Shaposhnikova, test_middle_seq) {
  CombGen* c = new CombGen(4, 3);
  std::vector<int> vec = { 1, 2, 3, 4 };
  c->setVecIn(vec);
  c->CombGenerate();
  std::vector<int> vec1 = { 1, 4, 4 };

  ASSERT_EQ(vec1, c->VecOut[9]);
}

TEST(Shaposhnikova, test_nextComb) {
  CombGen* c = new CombGen(4, 3);
  std::vector<int> comb = { 1, 2, 3};
  std::vector<int> combCompare = { 1, 3, 3 };

  ASSERT_EQ(combCompare, c->NextComb(comb));
}
