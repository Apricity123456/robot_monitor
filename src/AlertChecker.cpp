#include "AlertChecker.h"
#include <iostream>

void AlertChecker::checkAlerts(const std::vector<SensorRecord>& records) {
    for(const auto& record : records){
             if (record.type == "TEMP" && record.value > 38.0)
        {
            std::cout << "[ALERT] High temperature detected at timestamp "
                      << record.timestamp
                      << ": "
                      << record.value
                      << std::endl;
        }
        else if (record.type == "SPEED" && record.value > 2.0)
        {
            std::cout << "[ALERT] High speed detected at timestamp "
                      << record.timestamp
                      << ": "
                      << record.value
                      << std::endl;
        }
        else if (record.type == "HUMIDITY" && record.value > 60.0)
        {
            std::cout << "[ALERT] High humidity detected at timestamp "
                      << record.timestamp
                      << ": "
                      << record.value
                      << std::endl;
        }
    }
    }