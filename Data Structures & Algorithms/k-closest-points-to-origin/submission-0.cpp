class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxHeap; 

        for (int i = 0; i < points.size(); i++) {
            
            int distSq = points[i][0] * points[i][0] + points[i][1] * points[i][1];

            if (maxHeap.size() < k) {
                maxHeap.push({distSq, points[i]});
            } 
           
            else if (distSq < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push({distSq, points[i]});
            }
        }


        std::vector<std::vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second); 
            maxHeap.pop();
        }
        
        return res;

    }
};
