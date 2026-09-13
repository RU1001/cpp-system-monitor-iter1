#include <iostream>

double getcpuUsage(){
    double usage{};
    std::cin >> usage;
    return usage;

}
double getmemUsage(){
    double memory{};
    std::cin >> memory;
    return memory;

}

int getnumProcesses(){
    int processes{};
    std::cin >> processes;
    return processes;
}

int main(){
    //const double cpuUsageWarningThreshold{80.0};
    //const double memUsageWarningThreshold{80.0};

    std::cout << "Please enter cpu usage: ";
    double cpUsage{getcpuUsage()};
    std::cout << "CPU Usage: " << cpUsage << "\n";

    std::cout << "Please enter memory usage: ";
    double memUsage{getmemUsage()};
    std::cout << "Memory Usage: " << memUsage << "\n";
    
    std::cout << "Please enter number of processes: ";
    int proc{getnumProcesses()};
    std::cout << "Processes: " << proc << "\n";

    return 0;
}
