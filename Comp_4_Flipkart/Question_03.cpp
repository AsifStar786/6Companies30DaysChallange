//  Question #3 of challenge #4(Flipkart)
//  Name - Remove Zero Sum Consecutive Nodes from Linked List
//  LeetCode #1171

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *curr = head;

        map<int, ListNode*> map;
        map[0] = dummy;

        int prefix = 0;
        while(curr) {
            prefix += curr -> val;

            if(map.count(prefix)) {
                ListNode *p = map[prefix] -> next;
                int val = prefix;
                while(p != curr) {
                    val += p -> val;
                    map.erase(val);
                    p = p -> next;
                }
                map[prefix] -> next = curr -> next;
            }else {
                map[prefix] = curr;
            }
            curr = curr -> next;
        }
        
        return dummy -> next;
    }
};