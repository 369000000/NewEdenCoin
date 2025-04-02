#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
#include <fstream>

using namespace std;

class NECMiner {
private:
    bool mining;
    int threads;
    double hashRate;
    int blocksFound;
    double totalNEC;
    double cpuTemp;
    HANDLE hConsole;
    
    void saveLog(string msg) {
        ofstream log("mineracao.txt", ios::app);
        log << msg << endl;
        log.close();
    }
    
public:
    NECMiner() {
        mining = false;
        threads = 8;
        hashRate = 0.0;
        blocksFound = 0;
        totalNEC = 0.0;
        cpuTemp = 45.0;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        saveLog("=== Minerador NEC Iniciado ===");
    }

    void startMining() {
        mining = true;
        SetConsoleTextAttribute(hConsole, 10); // Verde
        cout << "\nIniciando mineracao com " << threads << " threads\n" << endl;
        SetConsoleTextAttribute(hConsole, 7); // Branco
        
        while(mining) {
            hashRate = rand() % 100 + 30;
            cpuTemp += 0.1;
            
            if (rand() % 100 < 5) {
                SetConsoleTextAttribute(hConsole, 14); // Amarelo
                blocksFound++;
                totalNEC += 9.0;
                cout << "\n>>> Bloco encontrado! <<<" << endl;
                SetConsoleTextAttribute(hConsole, 10); // Verde
                cout << ">>> +9 NEC <<<\n" << endl;
                saveLog("Bloco encontrado! Total: " + to_string(totalNEC) + " NEC");
                SetConsoleTextAttribute(hConsole, 7); // Branco
            }

            cout << "\rHash: ";
            SetConsoleTextAttribute(hConsole, 11); // Azul
            cout << hashRate << " MH/s";
            SetConsoleTextAttribute(hConsole, 7); // Branco
            cout << " | Temp: ";
            
            if (cpuTemp > 75.0) {
                SetConsoleTextAttribute(hConsole, 12); // Vermelho
                cout << cpuTemp << "C | ALERTA!";
                saveLog("Alerta de temperatura: " + to_string(cpuTemp) + "C");
            } else {
                SetConsoleTextAttribute(hConsole, 10); // Verde
                cout << cpuTemp << "C";
            }
            
            SetConsoleTextAttribute(hConsole, 7); // Branco
            cout << " | Blocos: ";
            SetConsoleTextAttribute(hConsole, 14); // Amarelo
            cout << blocksFound;
            SetConsoleTextAttribute(hConsole, 7); // Branco
            cout << " | NEC: ";
            SetConsoleTextAttribute(hConsole, 6); // Dourado
            cout << totalNEC << flush;
            SetConsoleTextAttribute(hConsole, 7); // Branco
            
            if (cpuTemp > 85.0) {
                cpuTemp = 45.0; // Resfria
            }
            
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11); // Azul
    cout << "=== NEC Miner v1.4 ===" << endl;
    SetConsoleTextAttribute(hConsole, 7); // Branco
    cout << "Inicializando..." << endl;
    
    NECMiner miner;
    
    cout << "\nPressione Enter para comecar a minerar...";
    cin.get();
    
    miner.startMining();
    
    return 0;
}