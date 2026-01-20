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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* tail = head;
        int n=1;
        while(tail->next){
             tail=tail->next;
             n++;                     //length
        }
        tail->next=head;              //circular list
        k=k%n;
        int stepsToNewTail=n-k-1;      //effec rotation
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next=nullptr;                     //break circle
        return newHead;
    }
};