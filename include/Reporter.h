#pragma once
 
#include<map>
#include<string>
#include"StatsCalculator.h"


class Reporter {
public: 
    static void printStats(const std::map<std::string,SensorStats>& stats);    
};
