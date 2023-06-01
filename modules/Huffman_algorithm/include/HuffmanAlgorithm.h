//  Copyright 2023 Gosteeva Ekaterina

#ifndef MODULES_HUFFMAN_ALGORITHM_INCLUDE_HUFFMANALGORITHM_H_
#define MODULES_HUFFMAN_ALGORITHM_INCLUDE_HUFFMANALGORITHM_H_

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

struct HuffmanNode {
    char letter;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char letter, int frequency);
};

struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right);
};

class HuffmanCode {
 private:
    HuffmanNode* root;
    std::unordered_map<char, std::string> huffmanCodes;

    void buildHuffmanTree(std::string text);
    void buildHuffmanCodes(HuffmanNode* node, std::string code);
    void freeMemory(HuffmanNode* node);
    bool isLeaf(HuffmanNode* root);
 public:
    HuffmanCode();
    std::string encode(std::string text);
    std::string decode(std::string encodedText, HuffmanNode* root_code);

    HuffmanNode* getRoot();
    ~HuffmanCode();
};

#endif  //  MODULES_HUFFMAN_ALGORITHM_INCLUDE_HUFFMANALGORITHM_H_
