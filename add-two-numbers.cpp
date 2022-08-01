/**
* https://leetcode.com/problems/add-two-numbers/
* 
* 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int LLsize(ListNode* ll) {
        int sz = 0;
        while (ll) {
            ++sz;
            ll = ll->next;
        }
        return sz;
    }

    ListNode* sumLL(ListNode* maxSize, ListNode* minSize) {
        int carry = 0;
        ListNode* ptr = maxSize, * prev = minSize;
        while (minSize) {
            ptr->val += minSize->val + carry;
            carry = ptr->val / 10;
            ptr->val %= 10;
            minSize = minSize->next;
            prev = ptr;
            ptr = ptr->next;
        }
        while (ptr) {
            ptr->val += carry;
            carry = ptr->val / 10;
            ptr->val %= 10;
            prev = ptr;
            ptr = ptr->next;
        }
        if (carry) {
            prev->next = new ListNode(carry);
        }
        return maxSize;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int l1_size = LLsize(l1), l2_size = LLsize(l2);
        ListNode* sum = NULL;
        if (l1_size >= l2_size) return sumLL(l1, l2);
        else return sumLL(l2, l1);
    }
};