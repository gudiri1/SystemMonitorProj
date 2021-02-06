#include <string>
#include <sstream>
#include "format.h"
using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds/*[[maybe_unused]]*/) { 
    
    //int hours, mins, secs;
    std::stringstream uptime;
    string h, m, s;
    if (seconds/3600 < 10) {h = "0";} else {h="";}
    if (seconds/60 - ((seconds/3600)*60) < 10) {m = "0";} else {m="";}
    if (seconds%60 < 10) {s = "0";} else {s="";}

    uptime << h << seconds/3600 << ":" << m << seconds/60 - ((seconds/3600)*60) << ":" << s << seconds%60 << "\n";
    return uptime.str();
}

