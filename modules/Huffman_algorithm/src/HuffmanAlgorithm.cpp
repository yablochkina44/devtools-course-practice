//  Copyright 2023 Gosteeva Ekaterina

#include "include/HuffmanAlgorithm.h"

HuffmanNode::HuffmanNode(char letter, int frequency) {
    this->letter = letter;
    this->frequency = frequency;
    left = right = nullptr;
}

bool Compare::operator()(HuffmanNode* left, HuffmanNode* right) {
    return left->frequency > right->frequency;
}

void HuffmanCode::buildHuffmanTree(std::string text) {
    std::unordered_map<unsigned char, int> frequencyMap;
    for (unsigned char c : text)
        frequencyMap[c]++;

    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;
    for (auto pair : frequencyMap)
        pq.push(new HuffmanNode(pair.first, pair.second));

    while (pq.size() != 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        int sumFreq = left->frequency + right->frequency;
        HuffmanNode* newNode = new HuffmanNode('\0', sumFreq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    root = pq.top();

    std::string currentCode = "";
    buildHuffmanCodes(root, currentCode);
}

void HuffmanCode::buildHuffmanCodes(HuffmanNode* node, std::string code) {
    if (node == nullptr)
        return;

    if (isLeaf(node))
        huffmanCodes[node->letter] = code;

    buildHuffmanCodes(node->left, code + "0");
    buildHuffmanCodes(node->right, code + "1");
}

void HuffmanCode::freeMemory(HuffmanNode* node) {
    if (node == nullptr)
        return;

    freeMemory(node->left);
    freeMemory(node->right);
    delete node;
}

bool HuffmanCode::isLeaf(HuffmanNode* root) {
    return root->left == nullptr && root->right == nullptr;
}

HuffmanCode::HuffmanCode() {
    root = nullptr;
}

std::string HuffmanCode::encode(std::string text) {
    if (text == "") {
        throw std::string("The text can't be empty");
    }

    buildHuffmanTree(text);

    std::string encodedText;
    for (unsigned char ch : text) {
        encodedText += huffmanCodes[ch];
    }

    return encodedText;
}

std::string HuffmanCode::decode(std::string encodedText,
HuffmanNode* root_code) {
    if (encodedText == "") {
         throw std::string("The text can't be empty");
    }
    if (root_code == nullptr) {
        throw std::string("Root node can't be empty");
    }

    std::string decodedText = "";
    HuffmanNode* current = root_code;

    for (unsigned char bit : encodedText) {
        if (bit == '0') {
            if (current->left)
                current = current->left;
        } else {
            if (bit == '1') {
                if (current->right)
                    current = current->right;
            }
        }
        if (!current->left && !current->right) {
            decodedText += current->letter;
            current = root_code;
        }
    }

    return decodedText;
}

HuffmanNode* HuffmanCode::getRoot() {
    if (root == nullptr) {
        throw std::string("Can't return empty root");
    }
    return root;
}

HuffmanCode::~HuffmanCode() {
    freeMemory(root);
}
