#include "Monitor.h"
#include <iostream>
#include <limits>
namespace Monitor{

    double getCpuUsage(){
        double usage{};
        std::cout << "Enter CPU usage: ";
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
        std::cout << "Enter memory usage: ";
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
        std::cout << "Enter number of processes: ";
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


    void checkWarnings(const SystemStats& stats, const MonitorConfig& config)
    {

        bool warningFound{};

        if (stats.cpuUsage >= config.cpuUsageWarningThreshold)
        {
            std::cout << "WARNING: High CPU usage!\n";
            warningFound = true;
        }
    
        if (stats.memUsage >= config.memUsageWarningThreshold)
        {
            std::cout << "WARNING: High memory usage!\n";
            warningFound = true;
        }

        if (!warningFound) {
            std::cout << "System Status: OK\n";
        }

    }


}
