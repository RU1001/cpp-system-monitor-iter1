#pragma once
#include "SystemStats.h"

namespace Monitor{

    struct MonitorConfig
    {
        const double cpuUsageWarningThreshold{80.0};
        const double memUsageWarningThreshold{80.0};
    };
    double getCpuUsage();
    double getMemUsage();
    int getNumProcesses();

    SystemStats collectSystemStats();

    void checkWarnings(const SystemStats& stats, const MonitorConfig& config);
}
