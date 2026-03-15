#ifndef SENSOR_RECORD_H
#define SENSOR_RECORD_H

#include <string>

class SensorRecord
{
public:
    SensorRecord(int t, const std::string &s, double v);

public:
    int timestamp;
    std::string type;
    double value;
};
#endif