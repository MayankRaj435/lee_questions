1class Solution {
2public:
3    ListNode* deleteMiddle(ListNode* head) {
4        if (head == NULL || head->next == NULL) {
5            return nullptr; 
6        }
7        ListNode* slow = head;
8        ListNode* fast = head;
9        ListNode* prev = nullptr; 
10        while (fast != NULL && fast->next != NULL) {
11            prev = slow;
12            slow = slow->next;
13            fast = fast->next->next;
14        }
15        prev->next = slow->next;
16        delete slow; 
17        return head;
18    }
19};
20