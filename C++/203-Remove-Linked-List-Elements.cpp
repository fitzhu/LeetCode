
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 一般这种问题（需要删除当前节点的）都是用两个指针遍历
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy{0};
        dummy.next = head;
        auto *prev = &dummy, *cur = dummy.next;

        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};