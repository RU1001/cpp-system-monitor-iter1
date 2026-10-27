#pragma once

#include <vector>
#include "Process.h"

namespace Simulation
{
    std::vector<Process> generateProcesses(int count);

    void simulateProcess(Process& proc);
}

