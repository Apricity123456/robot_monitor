#include "Parser.h"
#include "Logger.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<SensorRecord> Parser::parseFile(const std::string &filename)
{
    std::vector<SensorRecord> records;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        Logger::error("connot open file:" + filename);
        return records;
    }
    std::string line;
    int lineNumber = 0;
    while (std::getline(file, line))
    {
        lineNumber++;
        if (line.empty())
        {
            Logger::error("Skipping empty line at line :" + std::to_string(lineNumber));
            continue;
        }
        std::stringstream ss(line);
        std::string timestampStr, type, valueStr;

        if (!std::getline(ss, timestampStr, ',') ||
            !std::getline(ss, type, ',') ||
            !std::getline(ss, valueStr, ','))
        {
            Logger::error("Invalid format at line " + std::to_string(lineNumber) + ": " + line);
            continue;
        }
        try
        {
            int timestamp = std::stoi(timestampStr);
            double value = std::stod(valueStr);

            SensorRecord record(timestamp, type, value);
            records.push_back(record);
        }
        catch (const std::exception &e)
        {
            Logger::error("Conversion failed at line " + std::to_string(lineNumber) + ": " + line);
            continue;
        }
    }
    file.close();
    return records;
}