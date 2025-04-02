#pragma once
#include "NECCore.h"

class NECMiner {
public:
    bool mining;
    double hashRate;
    int blocksFound;
    double totalNEC;

    NECMiner() {
        mining = false;
        hashRate = 0.0;
        blocksFound = 0;
        totalNEC = 0.0;
    }
};