
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        // 快慢指针:
        //      快指针一次走两步；慢指针一次走一步
        //      如果走得快的指针追上了走得慢的指针，那么链表就是环形链表；
        //      如果走得快的指针走到了链表的末尾（next指向 NULL）都没有追上第一个指针，那么链表就不是环形链表。
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};