#ifndef PARSER_H
#define PARSER_H

#include<vector>
#include<string>
#include"SensorRecord.h"

class Parser{
public:
    std::vector<SensorRecord> parseFile(const std::string& filename);
};
#endif