/*Author: Solai*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while((NULL != fast) && (NULL != fast->next))
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
