#include <iostream>
#include <limits>
#include "display.h"
#include "SystemStats.h"
#include "Monitor.h"
#include "LogStats.h"


void runMonitoringCycle(const Monitor::MonitorConfig& config){
    //keeping system state local
    SystemStats stats{Monitor::collectSystemStats()}; //goes away after function ends

    Display::displayStats(stats);
    Display::displayConfig(config);
    Monitor::checkWarnings(stats,config);
    Logger::logStats(stats);



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

    const Monitor::MonitorConfig c{};

    while (true)
    {
        runMonitoringCycle(c);

        if (!shouldContinueMonitoring())
            break;
    }   

    return 0;
}
