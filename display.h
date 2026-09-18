#pragma once
#include "Monitor.h"
struct SystemStats;

namespace Display
{
    void displayStats(const SystemStats& stats);
    void displayConfig(const Monitor::MonitorConfig& config);
}
