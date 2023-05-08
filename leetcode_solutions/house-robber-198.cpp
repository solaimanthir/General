/*Author: Solai*/
class Solution {
public:
    int rob(vector<int>& nums) {
        /*p is max sum value at 'previous to previous house' of current house*/
        int p = 0;
        /*q is max sum value at 'previous house' of current house*/
        int q = 0;
        /*r is max sum value at current house*/
        int r = 0;

        for(auto val: nums)
        {
            r = max(val+p, q);

            /*adjust p and q for next house*/
            p = q;
            q = r;
        }
        
        /*max sum value possible at the end from the last house 'q'*/
        return q;
    }
};
