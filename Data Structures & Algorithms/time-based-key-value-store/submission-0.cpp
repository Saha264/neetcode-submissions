#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TimeMap {
private:
    // Map each key to a list of pairs (timestamp, value)
    unordered_map<string, vector<pair<int, string>>> db;

public:
    TimeMap() {
        // Constructor can remain empty
    }
    
    void set(string key, string value, int timestamp) {
        // Since timestamps are strictly increasing, they will naturally be sorted
        db[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // If the key doesn't exist, return empty string
        if (db.find(key) == db.end()) {
            return "";
        }
        
        const auto& values = db[key];
        int left = 0;
        int right = values.size() - 1;
        string res = ""; // Keeps track of our best valid answer
        
        // Standard Binary Search
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (values[mid].first <= timestamp) {
                res = values[mid].second; // This is a potential answer, store it
                left = mid + 1;           // Try to find a closer (larger) valid timestamp
            } else {
                right = mid - 1;          // Timestamp is too big, search left
            }
        }
        
        return res;
    }
};