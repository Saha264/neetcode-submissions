class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int i=0;i<stones.size();i++)
        {
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size()>1)
        {
            int first=maxHeap.top();
            maxHeap.pop();
            int second=maxHeap.top();
            maxHeap.pop();

            if(first==second)
            {
                continue;
            }
            else{
                maxHeap.push(abs(first-second));
            }
        }
        if(!maxHeap.empty())
        {
            int res=maxHeap.top();
            return res;
        }
        
        return 0;
    }
};
