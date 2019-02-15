
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 删除链表的当前节点，实际上可以删除下一个节点，然后把当前节点和下下个节点连起来
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto tmp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete tmp;
    }
};