#include "../include/headers/NECP2P.h"
#include <iostream>
#include <string>
#include <vector>

class NECNode {
private:
    string nodeId;
    vector<string> peers;
    bool isRunning;

public:
    NECNode() {
        nodeId = generateNodeId();
        isRunning = false;
    }

    string generateNodeId() {
        return "NEC" + to_string(rand() % 1000000);
    }

    void start() {
        isRunning = true;
        cout << "Nó NEC iniciado. ID: " << nodeId << endl;
    }
};