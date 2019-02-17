
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 不需要使用额外空间，只新建两个链表头，大于给定数的和小于给定数的，放到相应的链表结尾就行了，然后再把它们连起来
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy_larger{0};
        ListNode dummy_smaller{0};
        auto larger = &dummy_larger;
        auto smaller = &dummy_smaller;

        while (head) {
            if (head->val < x) {
                smaller->next = head;
                smaller = smaller->next;
            } else {
                larger->next = head;
                larger = larger->next;
            }
            head = head->next;
        }
        smaller->next = dummy_larger.next;
        larger->next = nullptr;

        return dummy_smaller.next;
    }
};