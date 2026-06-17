class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;

        for(int i=0;i<tasks.size();i++)
        {
            freq[tasks[i]]++;
        }

        int time=0;
        queue<pair<char,int>> resting; //letter, release time

        priority_queue<pair<int,char>> maxHeap; //frequency, letter

        for(const auto& pair: freq)
        {
            maxHeap.push({pair.second,pair.first});
        }
        pair<int,char> temp;

        while(!maxHeap.empty() || !resting.empty()){
            if(!resting.empty())
            {
                while(resting.front().second==time)
                {
                    maxHeap.push({freq[resting.front().first] , resting.front().first});
                    resting.pop();
                }
                
            }
            if(maxHeap.empty())
            {
                time++;
                continue;
            }
            else{
                temp=maxHeap.top();
                freq[temp.second]--;
                if(freq[temp.second]==0)
                {
                    time++;
                    maxHeap.pop();
                    continue;
                }
                else{
                    resting.push({temp.second, time+n+1});
                    

                }
                time++;
                maxHeap.pop();
                
            }

        }
        return time;
    }
};
