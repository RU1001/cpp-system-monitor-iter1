#include "display.h"
#include "SystemStats.h"
#include "Monitor.h"
#include <iostream>

namespace Display {
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

    void displayConfig(const Monitor::MonitorConfig& config){
        std::cout << "\n============================\n";
        std::cout << "       MONITOR SETTINGS\n";
        std::cout << "============================\n";

        std::cout << "CPU Warning:      " << config.cpuUsageWarningThreshold << "%\n";
        std::cout << "Memory Warning:   " << config.memUsageWarningThreshold << "%\n";

        std::cout << "============================\n";


    }

    void displayProcess(const Process& proc){
        if (proc.state == ProcessState::Running)
        {
            std::cout << "Running";
            
        }
        else
        {
            std::cout << "Stopped";
        }

        std::cout << proc.processID << " ";
        std::cout << proc.name << " ";
        std::cout << proc.cpuUsage << " ";
        std::cout << proc.memUsage << '\n';
    }



}
