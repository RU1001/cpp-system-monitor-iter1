#include <iostream>

struct SystemStats
{
    double cpuUsage{};
    double memUsage{};
    int numProcesses{};

};


double getCpuUsage(){
    double usage{};
    std::cin >> usage;
    return usage;

}
double getMemUsage(){
    double memory{};
    std::cin >> memory;
    return memory;

}

int getNumProcesses(){
    int processes{};
    std::cin >> processes;
    return processes;
}

SystemStats collectSystemStats(){
    SystemStats stats {getCpuUsage(),getMemUsage(),getNumProcesses()};
    return stats;

}

void displayStats(const SystemStats& stats){
    std::cout << "System Stats" << '\n';
    std::cout << "CPU Usage:   " << stats.cpuUsage << '\n';
    std::cout << "Memory Usage:  " << stats.memUsage << '\n';
    std::cout << "Processes: " << stats.numProcesses << '\n';
}

void checkWarnings(const SystemStats& stats)
{
    const double cpuUsageWarningThreshold{80.0};
    const double memUsageWarningThreshold{80.0};

    if (stats.cpuUsage >= cpuUsageWarningThreshold)
    {
        std::cout << "WARNING: High CPU usage!\n";
    }

    if (stats.memUsage >= memUsageWarningThreshold)
    {
        std::cout << "WARNING: High memory usage!\n";
    }


}

int main(){
    std::cout << "Enter system stats: ";
    SystemStats stats{collectSystemStats()};

    displayStats(stats);
    checkWarnings(stats);

    return 0;
}
