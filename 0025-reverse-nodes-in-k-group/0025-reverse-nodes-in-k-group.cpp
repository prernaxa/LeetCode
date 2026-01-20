/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;                     // new head after reversal
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        
        // Checking if there are k nodes to reverse
        ListNode* node = head;
        for (int i = 0; i < k; i++) {
            if (!node) return head;             // less than k nodes, no reversal
            node = node->next;
        }
        
        // Reversing first k nodes
        ListNode* newHead = reverse(head, node);
        
        // head=tail after reversal, connecting it with next reversed part
        head->next = reverseKGroup(node, k);
        
        return newHead;
    }
};
