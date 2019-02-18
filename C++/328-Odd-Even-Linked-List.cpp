
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 使用两个指针分别把奇数节点和偶数节点串起来，注意最后把偶数节点连在后面
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *odd_head = head, *even_node = head->next, *tmp = even_node;
        while (even_node != nullptr && even_node->next != nullptr) {
            // 奇数放到奇数后面，偶数放在偶数后面
            odd_head->next = even_node->next;
            odd_head = odd_head->next;
            even_node->next = odd_head->next;
            even_node = even_node->next;
        }
        // 把偶数节点连接在后面
        odd_head->next = tmp;
        return head;
    }
};