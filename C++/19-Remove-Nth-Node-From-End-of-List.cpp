
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 用双指针，fast指针先走n步，然后fast和slow指针一起走，当fast指针到末尾，slow->next指针为需要删除的node
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0};
        dummy.next = head;
        auto slow = &dummy;
        auto fast = &dummy;

        // fast is n-steps ahead;
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast->next ！= nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        auto node_to_delete = slow->next;
        slow->next = slow->next->next;
        delete node_to_delete;
        return dummy.next;
    }
};