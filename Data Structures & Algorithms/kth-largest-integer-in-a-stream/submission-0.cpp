class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
  
        kSize=k;
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
    }
    
    int add(int val) {
        

        
        minHeap.push(val);

        if(minHeap.size()>kSize)
        {
            minHeap.pop();
        }
        int res= minHeap.top();

        return res;
        
    }
private:
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int kSize;
};
