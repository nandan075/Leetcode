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
    ListNode* reverseKGroup(ListNode* head, int k) {
     
     if( !head || k<=1){
        return head;
     }

     ListNode dummy(0 , head);
     ListNode* groupprev = &dummy;

     while(true){

        ListNode* kth = groupprev;
        for(int i = 0 ; i <k && kth != nullptr; ++i){
            kth = kth->next;
        }

        if (!kth) break;

        ListNode* groupnext = kth->next;
        ListNode* prev = groupnext;
        ListNode* curr = groupprev->next;

        while (curr != groupnext){

            ListNode* temp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* newGrouptail = groupprev->next;
        groupprev->next = kth;
        groupprev = newGrouptail;
     }
return dummy.next;
        
    }
};