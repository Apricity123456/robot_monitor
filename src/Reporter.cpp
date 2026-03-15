#include"Reporter.h"
#include<iostream>

void Reporter::printStats(const std::map<std::string,SensorStats>& stats){
    for(const auto& item : stats){
        std::cout << item.first
        <<"-> cout:"
        <<item.second.count
        <<"avg:"
        <<item.second.average
        <<std::endl;
    }
}