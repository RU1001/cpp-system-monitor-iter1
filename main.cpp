#include <iostream>
#include <limits>
#include <fstream>
#include <chrono>
#include "display.h"
#include "SystemStats.h"



struct MonitorConfig
{
    const double cpuUsageWarningThreshold{80.0};
    const double memUsageWarningThreshold{80.0};
};


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




void displayConfig(const MonitorConfig& config){
    std::cout << "\n============================\n";
    std::cout << "       MONITOR SETTINGS\n";
    std::cout << "============================\n";

    std::cout << "CPU Warning:      " << config.cpuUsageWarningThreshold << "%\n";
    std::cout << "Memory Warning:   " << config.memUsageWarningThreshold << "%\n";

    std::cout << "============================\n";


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

void runMonitoringCycle(const MonitorConfig& config){
    //keeping system state local
    SystemStats stats{collectSystemStats()}; //goes away after function ends

    Monitor::displayStats(stats);
    displayConfig(config);
    checkWarnings(stats,config);
    logStats(stats);



}

bool shouldContinueMonitoring(){
    while (true) {
        std::cout << "Would you like to continue monitoring? (y/n) ?: ";

        char ans{};
        std::cin >> ans;

        if (!std::cin || !(ans == 'y' || ans == 'n')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter y or n.\n";
            continue;
        }
         if (ans == 'n') {
            return false;
        }

        return true;

    }

}


int main(){

    const MonitorConfig c{};

    while (true)
    {
        runMonitoringCycle(c);

        if (!shouldContinueMonitoring())
            break;
    }
    return 0;
}
