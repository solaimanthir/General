/*Author: Solai*/
class Solution {
public:
    vector<vector<int>> result = {};
    vector<int> in_arr = {};
    int tar;

    void recursion_dfs(int i, vector<int>& cur, int tot)
    {
        if(tar == tot)
        {
            vector<int> curcopy = {};
            curcopy.assign(cur.begin(), cur.end());
            result.push_back(curcopy);
            return;
        }

        if((tot > tar) || (i>=in_arr.size()))
        {
            return;
        }

        //decision#1
        cur.push_back(in_arr[i]);
        recursion_dfs(i, cur, (tot + in_arr[i]));
        //decision#2
        cur.pop_back();
        recursion_dfs(i+1, cur, tot);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur = {};
        tar = target;
        in_arr.assign(candidates.begin(), candidates.end());
        recursion_dfs(0, cur, 0);
        return result;
    }
};
