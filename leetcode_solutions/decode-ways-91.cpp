/*Author: Solai*/
class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> hmap;
        int len = s.length();
        hmap[len] = 1;

        for(int i = len-1; i >= 0; --i)
        {
            if('0' == s[i])
                hmap[i] = 0;
            else
                /*copy result from next subproblem at i+1*/
                hmap[i] = hmap[i+1];
            
            /*copy result from next subproblem at i+2*/
            if((i+1) < len && s[i] == '1' || s[i] == '2' &&
                s[i+1] >= '0' && s[i+1] <= '6')
            {
                hmap[i] += hmap[i+2];
            }
        }

        return hmap[0];
    }
};
