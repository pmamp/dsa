/*
* 
* https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
* 
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* fmd(Node* curr, Node* next) {
        if (curr == NULL) return NULL;
        Node* ptr = curr, * ptr_prev = curr;
        while (ptr) {
            if (ptr->child) {
                Node* ptr_nxt = ptr->next;
                ptr->next = ptr->child;
                ptr->child->prev = ptr;
                Node* ptr_nxt_prev = fmd(ptr->child, ptr_nxt);
                if (ptr_nxt) ptr_nxt->prev = ptr_nxt_prev;
                ptr->child = NULL;
            }
            ptr_prev = ptr;
            ptr = ptr->next;
        }
        ptr_prev->next = next;
        return ptr_prev;
    }


    Node* flatten(Node* head) {
        fmd(head, NULL);
        return head;
    }
};