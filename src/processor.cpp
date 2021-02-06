#include "processor.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "linux_parser.h"
using std::string;
using std::stof;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
  string line, desc, user, nice, psystem, idle, iowait, irq, softirq, steal;
  std::ifstream stream("/proc/stat"/*kProcDirectory+kStatFilename*/);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> desc >> user >> nice >> psystem >> idle >> iowait >> irq >> softirq >> steal;
    float idlet =  stof(idle) + stof(iowait);
    float total =  idlet + (stof(user) + stof(nice) + stof(psystem) + stof(irq) + stof(softirq) + stof(steal));
    usage_cpu_ = (total - idlet)/total;
  }  
   
  return usage_cpu_; 
}

/*
PrevIdle = previdle + previowait
Idle = idle + iowait

PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal
NonIdle = user + nice + system + irq + softirq + steal

PrevTotal = PrevIdle + PrevNonIdle
Total = Idle + NonIdle

# differentiate: actual value minus the previous one
totald = Total - PrevTotal
idled = Idle - PrevIdle

CPU_Percentage = (totald - idled)/totald

*/