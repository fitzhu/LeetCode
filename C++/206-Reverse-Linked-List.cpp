
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 反转链表，新建一个dummy node，然后遍历
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto dummy = ListNode{0};
        while (head) {
            auto tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }
        return dummy.next;
    }
};