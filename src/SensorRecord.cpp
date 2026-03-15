#include "SensorRecord.h"

SensorRecord::SensorRecord(int t, const std::string &s, double v)
{
        timestamp = t;
        type = s;
        value = v;
}