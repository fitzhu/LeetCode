
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 首先获得链表的长度
        int n = 1;
        auto curr = head;
        for (; curr->next; curr = curr->next) {
            ++n;
        }
        // 把当前链表连成环，再找到第n个节点断开，便完成了旋转链表
        curr->next = head;

        auto tail = curr;
        k = n - k % n;
        curr = head;
        for (int i = 0; i < k; curr = curr->next, ++i) {
            tail = curr;
        }

        tail->next = nullptr;
        return curr;
    }
};