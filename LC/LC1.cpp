class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Number is the key, its index is the value
        unordered_map<int, int> hash;
        int len = nums.size();
        int comple = 0;

        for(int i = 0; i < len; ++i)
        {
            comple = target - nums[i];

            if(hash.find(comple) != hash.end())
            {
                int ind = hash[comple];
                return vector<int> {ind, i};
            }

            hash[nums[i]] = i;
        }
        return vector<int> {};
    }
};
