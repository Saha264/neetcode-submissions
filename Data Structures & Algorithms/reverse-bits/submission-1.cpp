class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int temp=0;
        for(int i=0;i<32;i++)
        {
            temp= ((n>>i) & 1);
            res |= temp<<(31-i);
            
        }
        return res;
    }
};
