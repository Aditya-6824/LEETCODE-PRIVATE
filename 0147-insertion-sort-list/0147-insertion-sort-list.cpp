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
    ListNode* insertionSortList(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* it = head->next; // iterator that loops from the second node to the last (pointing to the key)
        ListNode* last_key = head; // Points to the element that is in the position of the last key
        while (it != nullptr) {
            if (it->val >= last_key->val) { // key is already sorted
                last_key = it; it = it->next;
            } else {
                ListNode* h = head; // temp iterator over the sorted sub-array
                if (it->val < head->val) { // if the key is to be inserted at the start
                    last_key->next = it->next;
                    it->next = head;
                    head = it;
                    it = last_key->next;
                    continue;
                } 
                // Finding the position to insert the key
                while (h->next->val <= it->val) {
                    h = h->next;
                }
                last_key->next = it->next;
                ListNode* temp = h->next;
                h->next = it;
                it->next = temp;
                it = last_key->next;
            }
        }

        return head;
    }
};