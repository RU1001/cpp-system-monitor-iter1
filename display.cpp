#include "display.h"
#include "SystemStats.h"
#include <iostream>

namespace Monitor {
    void displayStats(const SystemStats& stats)
{
    std::cout << "\n============================\n";
    std::cout << "       SYSTEM MONITOR\n";
    std::cout << "============================\n";

    std::cout << "CPU Usage:      " << stats.cpuUsage << "%\n";
    std::cout << "Memory Usage:   " << stats.memUsage << "%\n";
    std::cout << "Processes:      " << stats.numProcesses << '\n';

    std::cout << "============================\n";
}

}
