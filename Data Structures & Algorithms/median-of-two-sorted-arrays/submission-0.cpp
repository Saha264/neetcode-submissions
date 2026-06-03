class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {


        if(nums1.size()>nums2.size())
        {
            swap(nums1,nums2);
        }

        int n= nums1.size();
        int m= nums2.size();
        int total= m+n;
        int half= total/2;

        int left=0;
        int right= n;

        int INF_MIN = std::numeric_limits<int>::min();
        int INF_MAX = std::numeric_limits<int>::max();

        while(left<=right)
        {


            int i=(left+right)/2;
            int j= half-i;


            int nums1left  = (i > 0) ? nums1[i-1] : INF_MIN;
            int nums1right = (i  < n) ? nums1[i ] : INF_MAX;

            int nums2left  = (j > 0) ? nums2[j-1] : INF_MIN;
            int nums2right = (j  < m) ? nums2[j] : INF_MAX;

            if(nums1left > nums2right)
            {
                right= i-1;
            }
            else if( nums2left > nums1right)
            {
                left=i+1;
            }
            else{
                if(total%2==0)
                {
                    return float((max(nums1left, nums2left) + min( nums1right, nums2right)))/2;
                }
                else{
                    return min( nums1right, nums2right);
                }
            }
        }
        return 0.0;

        



    }
};
