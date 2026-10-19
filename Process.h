#pragma once
#include <string_view>
#include <vector>

struct Process
{
    int processID {};
    std::string_view name {};
    double cpuUsage{};
    double memUsage{};

};


std::vector<Process> generateProcesses(int count);
