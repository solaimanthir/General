class Solution {
public:
    bool canJump(vector<int>& nums) {
        int post = nums.size() - 1;

        for(int i = post; i >= 0; i--)
        {
            if(nums[i]+i >= post)
                post = i;
        }

        if(0 == post)
            return true;
        
        return false;
    }
};
