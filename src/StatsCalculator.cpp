#include"StatsCalculator.h"

std::map<std::string, SensorStats>
StatsCalculator::calculateStats(const std::vector<SensorRecord>& records)
{
    std::map<std::string, SensorStats> stats;

    for (const auto& record : records)
    {
        stats[record.type].count += 1;
        stats[record.type].sum += record.value;
    }

    for (auto& item : stats)
    {
        item.second.average =
            item.second.sum / item.second.count;
    }

    return stats;
}