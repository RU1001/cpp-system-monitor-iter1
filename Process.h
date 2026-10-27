#pragma once
#include <string_view>
#include <vector>

enum class ProcessState
{
    Running,
    Stopped
};

struct Process
{
    int processID {};
    std::string_view name {};
    double cpuUsage{};
    double memUsage{};
    ProcessState state{ProcessState::Running};

};


std::vector<Process> generateProcesses(int count);
