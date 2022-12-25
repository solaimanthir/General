/*Author: Solai*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode *> vec_arr = {head};
        int mid = 0;

        while(NULL != vec_arr.back()->next)
        {
            vec_arr.push_back(vec_arr.back()->next);
        }

        mid = vec_arr.size()/2;
        return vec_arr[mid];
    }
};
