#pragma once

#include <vector>
#include "SensorRecord.h"

class AlertChecker
{
public:
    static void checkAlerts(const std::vector<SensorRecord>& records);
};