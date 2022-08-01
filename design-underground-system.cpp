/*
https://leetcode.com/problems/design-underground-system/
*/

class UndergroundSystem {
    unordered_map<int, pair<string, int> > tic;
    map<pair<string, string>, pair<int, int> > avg_time;
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        tic[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) {
        string src = tic[id].first;
        int tvl_time = t - tic[id].second;
        if (avg_time.find({ src, stationName }) != avg_time.end()) {
            auto stationRecord = avg_time[{src, stationName}];
            avg_time[{src, stationName}] = { stationRecord.first + tvl_time, ++stationRecord.second };
        }
        else {
            avg_time[{src, stationName}] = { tvl_time, 1 };
        }
    }

    double getAverageTime(string startStation, string endStation) {
        auto stationRecord = avg_time[{startStation, endStation}];
        return (double)stationRecord.first / (double)stationRecord.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */