#pragma once
#include "Monitor.h"
#include "Process.h"
struct SystemStats;

namespace Display
{
    void displayStats(const SystemStats& stats);
    void displayConfig(const Monitor::MonitorConfig& config);
    void displayProcess(const Process& proc);
}
