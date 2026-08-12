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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = head;
        int count = 0;

        while (dummy != nullptr) {

            count++;

            dummy = dummy->next;
        }

        int target = count - n;
        ListNode d(0);
        d.next=head;
        ListNode* dummy2 = &d;
        for (int i = 1; i <=target; i++) {

            dummy2 = dummy2->next;
        }

        dummy2->next = dummy2->next->next;

        return d.next;
    }
};