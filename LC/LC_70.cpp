class Solution {
public:
    int climbStairs(int n) {
        //base cases
        int one_step = 1;
        int two_steps = 1;
        int copy = 0;

        //build solutions with bottom-up DP approach
        //we iterate n-1 steps.
        for(int i = 1; i < n; ++i)
        {
            copy = one_step;
            one_step += two_steps;
            two_steps = copy;
        }

        return one_step;
    }
};
