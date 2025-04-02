#include "../include/headers/NECCore.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class Block {
public:
    uint32_t nonce;
    uint32_t blockHeight;
    string previousHash;
    string hash;
    int64_t timestamp;
    double difficulty;

    Block(uint32_t heightIn, string prevHash) {
        blockHeight = heightIn;
        previousHash = prevHash;
        timestamp = time(nullptr);
        nonce = 0;
        difficulty = 1.0;
    }
};

class NECChain {
private:
    vector<Block> chain;
    double initialReward = 9.0;
    uint32_t blocksPerHalving = 2520000;

public:
    NECChain() {
        createGenesisBlock();
    }

    void createGenesisBlock() {
        Block genesis(0, "0");
        chain.push_back(genesis);
    }
};