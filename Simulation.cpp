#include "Simulation.h"
#include <stdexcept>
#include <array>
#include <random>

namespace Simulation
{

    constexpr std::array<std::string_view, 5> processNames{
        "Chrome",
        "Python",
        "Terminal",
        "VS Code",
        "System"
    };

    std::vector<Process> generateProcesses(int count)
    {
        std::vector<Process> processes;

        if (count < 0){
            throw std::invalid_argument("Process count cannot be negative");
        }

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<double> cpuDist(0.0, 100.0);
        std::uniform_real_distribution<double> memDist(0.0, 100.0);

        for (int i = 0; i < count; ++i)
        {
            double cpu = cpuDist(gen);
            double mem = memDist(gen);
            Process proc = {i+1, processNames[i % processNames.size()], cpu,mem, ProcessState::Running};
            processes.push_back(proc);
        }

        return processes;

        
    }
}
