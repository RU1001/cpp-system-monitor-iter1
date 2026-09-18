#include "SystemStats.h"
#include <iostream>
#include <fstream>
#include <chrono>

namespace Logger {
    void logStats(const SystemStats& stats){
    std::string filename = "monitor_log.txt";
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    auto t = std::chrono::system_clock::now();
    auto tme = std::chrono::system_clock::to_time_t(t);
    file << "Time:            " << std::ctime(&tme);
    file << "CPU Usage:      " << stats.cpuUsage << "%\n";
    file << "Memory Usage:   " << stats.memUsage << "%\n";
    file << "Processes:      " << stats.numProcesses << '\n';

    if(!file){
        std::cerr << "Failed to write to file." << std:: endl;
        return;
    }

   
    file.close(); //not really needed because ofstream destroys after usage

    }
}
