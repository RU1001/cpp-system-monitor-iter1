#include <iostream>

struct SystemStats
{
    double cpuUsage{};
    double memUsage{};
    int numProcesses{};

};


double getCpuUsage(){
    double usage{};
    while (true) {
        std::cin >> usage;

        if (!std::cin || !(usage >= 0 && usage <= 100)) {

            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "Invalid CPU usage. Enter a value from 0 to 100: ";
            continue;
        }

    return usage;
    }

}


double getMemUsage(){
    double memory{};
    while (true) {
        std::cin >> memory;

        if (!std::cin || !(memory >= 0 && memory <= 100)) {

            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Invalid memory usage. Enter a value from 0 to 100: ";
            continue;
        }

        return memory;
    }
    

}

int getNumProcesses(){
    int processes{};
    while (true) {
        std::cin >> processes;

        if (!std::cin || (processes < 0)) {

            if (!std::cin) {
                std::cin.clear(); //clear input buffer bad characters
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //up until you hit a newline
                continue;
            }
            std::cout << "Invalid number of processes. Enter a value greater than or equal to zero: ";
            continue;
        }

        return processes;
    }
}

SystemStats collectSystemStats(){
    SystemStats stats {getCpuUsage(),getMemUsage(),getNumProcesses()};
    return stats;

}

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

void checkWarnings(const SystemStats& stats)
{
    const double cpuUsageWarningThreshold{80.0};
    const double memUsageWarningThreshold{80.0};
    bool warningFound{};

    if (stats.cpuUsage >= cpuUsageWarningThreshold)
    {
        std::cout << "WARNING: High CPU usage!\n";
        warningFound = true;
    }
  
    if (stats.memUsage >= memUsageWarningThreshold)
    {
        std::cout << "WARNING: High memory usage!\n";
        warningFound = true;
    }

    if (!warningFound) {
        std::cout << "System Status: OK\n";
    }

}

void runMonitoringCycle(){
    std::cout << "Enter system stats: ";
    SystemStats stats{collectSystemStats()};

    displayStats(stats);
    checkWarnings(stats);

}

int main(){
    bool continueMonitoring{true};

    do{
        runMonitoringCycle();
        std::cout << "Would you like to continue monitoring? (y/n) ?: ";
        char ans{};
        std::cin >> ans;

        if (ans == 'n') {
            continueMonitoring = false;
        }

    } while(continueMonitoring);
}
