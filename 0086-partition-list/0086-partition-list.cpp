
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        // Dummy nodes for two partitions
        ListNode dummySmall(0);
        ListNode dummyLarge(0);

        ListNode* small = &dummySmall;
        ListNode* large = &dummyLarge;

        while (head != NULL) {
            ListNode* nextNode = head->next; // save next

            head->next = NULL; // detach current node

            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }

            head = nextNode;
        }

        // Connect both lists
        small->next = dummyLarge.next;

        return dummySmall.next;
    }
};