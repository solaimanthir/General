/*Author: Solai*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int p = 0;
        int q = 0;
        int r = 0;
        int val = 0;

        if(1 == len)
        {
            return nums[0];
        }

        /*1st and last house are connected. So, divide
         the array into two subarrays. And, find the maximum sum from these
         two subarrays*/
        
        /*1st subarray: excludes last house*/
         for(int i = 0; i < len-1; ++i)
         {
             val = nums[i];
             r = max(val+p, q);
             p = q;
             q = r;
         }
         int max1 = q;

        p = 0;
        q = 0;
        /*2nd subarray: excludes 1st house*/
         for(int i = 1; i < len; ++i)
         {
             val = nums[i];
             r = max(val+p, q);
             p = q;
             q = r;
         }
         int max2 = q;

        return max(max1, max2);
    }
};
