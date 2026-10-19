#include "Simulation.h"
#include <stdexcept>

namespace Simulation
{
    std::vector<Process> generateProcesses(int count)
    {
        if (count < 1){
            throw std::invalid_argument("Process count cannot be negative");
        }
        
    }
}
