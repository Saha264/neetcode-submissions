class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        int count=0;
        int i=0;
        int largest=0;
        
        while(i<nums.size() )
        {
            if(minHeap.size()<k)
            {
                minHeap.push(nums[i]);
                i++;
                
            }
            else{
                if(nums[i]>minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(nums[i]);

                }
                i++;
            }

        }
        return minHeap.top();
        
    }
};
