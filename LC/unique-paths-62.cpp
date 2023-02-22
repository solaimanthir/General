/*Author: Solai*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        /*unique paths from all cells in last row will always be 1*/
        vector<int> prev_row(n, 1);
        
        int len1 = m-1;
        int len2 = n-2;
        for(int i = 0; i < len1; ++i)
        {
            /*initialization. Last cell will always be 1*/
            vector<int> curr_row(n, 1);
            
            for(int j = len2; j >= 0; --j)
            {
                /*add from the right and down cells*/
                curr_row[j] = curr_row[j+1] + prev_row[j];
            }
            prev_row = curr_row;
        }
        return prev_row[0];
    }
};
