#include <iostream>
#include "SensorRecord.h"
#include "Parser.h"
#include "StatsCalculator.h"
#include "Reporter.h"
#include "Logger.h"
#include "AlertChecker.h"
int main()
{
    // SensorRecord r(1001,"temp",36.5);
    // std::cout << "timestamp:"<< r.timestamp << std::endl;
    // std::cout << "type:"<< r.type << std::endl;
    // std::cout << "value:"<< r.value << std::endl;
    // std::cout << "Robot Monitor started successfully!" << std::endl;

    // Parser parser;
    // std::vector<SensorRecord> records = parser.parseFile("data/sensor_data.txt");

    // for (const auto& record : records) {
    //     std::cout << "timestamp: " << record.timestamp
    //               << ", type: " << record.type
    //               << ", value: " << record.value << std::endl;
    // }

    // StatsCalculator calculator;
    // auto stats = calculator.calculateStats(records);

    // for (const auto &item : stats)
    // {
    //     std::cout << item.first
    //               << " -> count: "
    //               << item.second.count
    //               << " avg: "
    //               << item.second.average
    //               << std::endl;
    // }
    Logger::info("Starting robot monitor...");
    Parser parser;
    Logger::info("Parser sensor_data.txt file.");
    auto records = parser.parseFile("data/sensor_data.txt");
    Logger::info("Records loaded: " + std::to_string(records.size()));
    Logger::info("Checking alerts...");
    AlertChecker::checkAlerts(records);
    // StatsCalculator calculator;
    StatsCalculator calculator;
    Logger::info("Calculating statistics");
    auto stats = calculator.calculateStats(records);
    Logger::info("Calculating statistics");
    Reporter::printStats(stats);
    Logger::info("Printing results");
    return 0;
}