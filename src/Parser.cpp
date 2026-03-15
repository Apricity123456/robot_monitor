#include"Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<SensorRecord> Parser::parseFile(const std::string& filename) {
    std::vector<SensorRecord> records;
    std::ifstream file(filename);

    if(!file.is_open()){
        std::cerr << "ERROR:can not open file" << filename <<std::endl;
        return records;
    }
    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss(line);
        std::string timestampStr, type, valueStr;
 
        std::getline(ss,timestampStr,',');
        std::getline(ss,type,',');
        std::getline(ss,valueStr,',');
        int timestamp = std::stoi(timestampStr);
        double value = std::stod(valueStr);

        SensorRecord record(timestamp, type, value);
        records.push_back(record);
    }
     file.close();
    return records;
}