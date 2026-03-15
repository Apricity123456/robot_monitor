#ifndef STATS_CALCULATOR_H
#define STATS_CALCULATOR_H
#include <map>
#include <vector>
#include <string>
#include "SensorRecord.h"

struct SensorStats
{
    int count = 0;
    double sum = 0.0;
    double average = 0.0;
};


class StatsCalculator {
public:
    std::map<std::string,SensorStats>
    calculateStats(const std::vector<SensorRecord>& records);

};

#endif