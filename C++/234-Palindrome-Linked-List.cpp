
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 如果要空间复杂度O(1)的话，先用快慢指针找到链表中点，同时翻转前一部分链表，然后再向两边遍历
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Reverse the first half list, and find mid
        ListNode *reverse = nullptr, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            const auto head_next = head->next;
            head->next = reverse;
            reverse = head;
            head = head_next;
        }

        // If the number of the nodes is odd,
        // set the head of the tail list to the next of the median node.
        ListNode *tail = fast ? head->next : head;

        // 向两边比对链表，同时把之前翻转的链表再翻转回来
        bool res = true;
        while (reverse) {
            res = res && reverse->val == tail->val;
            const auto reverse_next = reverse->next;
            reverse->next = head;
            head = reverse;
            reverse = reverse_next;
            tail = tail->next;
        }
        return res;
    }
};