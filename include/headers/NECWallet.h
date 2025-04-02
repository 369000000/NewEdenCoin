#pragma once
#include <string>

class NECWallet {
public:
    std::string address;
    double balance;

    NECWallet() {
        balance = 0.0;
    }
};