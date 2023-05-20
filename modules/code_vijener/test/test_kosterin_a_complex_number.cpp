// Copyright 2023 Kosterin Alexey

#include <gtest/gtest.h>
#include <include/code_vijener.h>

TEST(kosterin_a_CodeVijenerTest, Can_Create_Code_vijener) {
    ASSERT_NO_THROW(Code_vijener code("test", "test2"));
}

TEST(kosterin_a_CodeVijenerTest, True_key_and_code_str_String) {
    Code_vijener code("str", "key");
    EXPECT_EQ(code.GetCodeStr(), "STR");
    EXPECT_EQ(code.GetKey(), "KEY");
}
TEST(kosterin_a_CodeVijenerTest, Test_SetKey_and_SetCode_str_String) {
    Code_vijener code("w", "q");
    code.SetCodeStr("str");
    code.SetKey("key");
    EXPECT_EQ(code.GetCodeStr(), "STR");
    EXPECT_EQ(code.GetKey(), "KEY");
}

TEST(kosterin_a_CodeVijenerTest, Test_Default_Constructor) {
    ASSERT_NO_THROW(Code_vijener code);
}

TEST(kosterin_a_CodeVijenerTest, Test_Copie_Constructor) {
    Code_vijener code1("Str", "key");
    Code_vijener code2(code1);
    EXPECT_EQ(code1.GetCodeStr(), code2.GetCodeStr());
    EXPECT_EQ(code1.GetKey(), code2.GetKey());
}

TEST(kosterin_a_CodeVijenerTest, Test_Function_KeyCode) {
    Code_vijener code1;
    EXPECT_EQ(code1.KeyCode('D'), 3);
}

TEST(kosterin_a_CodeVijenerTest, Test_Function_Error_KeyCode) {
    Code_vijener code1;

    EXPECT_EQ(code1.KeyCode('@'), -1);
}
TEST(kosterin_a_CodeVijenerTest, Test_Function_Encoder) {
    Code_vijener code1("student", "cat");
    EXPECT_EQ(code1.Encoder(), "UTNFEGV");
}

TEST(kosterin_a_CodeVijenerTest, Test_Function_Decoder) {
    Code_vijener code1("UTNFEGV", "cat");
    EXPECT_EQ(code1.Decoder(), "STUDENT");
}
