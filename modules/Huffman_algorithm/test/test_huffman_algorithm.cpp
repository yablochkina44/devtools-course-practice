//  Copyright 2023 Gosteeva Ekaterina

#include <gtest/gtest.h>
#include "include/HuffmanAlgorithm.h"

TEST(HuffCodeTest, Creat_HuffmanNode) {
    ASSERT_NO_THROW(HuffmanNode node('a', 3));
}

TEST(HuffCodeTest, Creat_HuffmanNode_Correct) {
    HuffmanNode node('a', 3);

    EXPECT_EQ('a', node.letter);
    EXPECT_EQ(3, node.frequency);
    EXPECT_EQ(nullptr, node.left);
    EXPECT_EQ(nullptr, node.right);
}

TEST(HuffCodeTest, Change_HuffmanNode_Correct) {
    HuffmanNode node('a', 3);

    node.letter = 'b';
    node.frequency = 1;

    EXPECT_EQ('b', node.letter);
    EXPECT_EQ(1, node.frequency);
}

TEST(HuffCodeTest, Add_Right_And_Left_Nodes) {
    HuffmanNode* node = new HuffmanNode('a', 3);
    HuffmanNode* right_node = new HuffmanNode('r', 1);
    HuffmanNode* left_node = new HuffmanNode('l', 2);

    node->left = left_node;
    node->right = right_node;

    EXPECT_EQ((*left_node).letter, (node->left)->letter);
    EXPECT_EQ((*right_node).letter, (node->right)->letter);
}

TEST(HuffCodeTest, Creat_HuffmanCode) {
    ASSERT_NO_THROW(HuffmanCode huffmanCode);
}

TEST(HuffCodeTest, Encode_Empty_Text) {
    HuffmanCode huffmanCode;
    std::string empty_text = "";
    ASSERT_ANY_THROW(huffmanCode.encode(empty_text));
}

TEST(HuffCodeTest, Decode_With_Empty_Text) {
    HuffmanCode huffmanCode;
    std::string text = "Hello!";
    text = huffmanCode.encode(text);
    std::string empty_text = "";
    ASSERT_ANY_THROW(huffmanCode.decode(empty_text, huffmanCode.getRoot()));
}

TEST(HuffCodeTest, Decode_With_Empty_Root) {
    HuffmanCode huffmanCode;
    std::string text = "error";
    ASSERT_ANY_THROW(huffmanCode.decode(text, nullptr));
}

TEST(HuffCodeTest, Encode_And_Decode_Text_Correct) {
    HuffmanCode huffmanCode;
    std::string text = "Hello!";
    std::string encoded_text = huffmanCode.encode(text);
    EXPECT_EQ(text, huffmanCode.decode(encoded_text, huffmanCode.getRoot()));
}

TEST(HuffCodeTest, Get_Empty_Root) {
    HuffmanCode huffmanCode;
    ASSERT_ANY_THROW(huffmanCode.getRoot());
}

TEST(HuffCodeTest, Get_NonEmpty_Root) {
    HuffmanCode huffmanCode;
    std::string text = "Hello!";
    std::string encoded_text = huffmanCode.encode(text);
    EXPECT_NE(nullptr, huffmanCode.getRoot());
}
