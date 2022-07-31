/*
Subtract Two Numbers Represented as Linked List

Problem Statement
A singly linked lsit is represented by the following structure:
struct Node
{
	int data;
	struct Node* next;
};

Implement the following function:
struct Node* SubtractTwoLists(struct Node* head1, struct Node* head2);

The function accepts two pointers to the start of the linked lists, 'head1' and 'head2' as its argument. 
Implement the function to subtract a number represented by linked list 'head2' from a number represented
by linked list 'head1' and return the resultant linked list containing subtraction of these two numbers.

Assumption:
Number represented by 'head1' is always greater than equal to the number represented by 'head2'

Note:
1. Return NULL if 'head1' is NULL
2. Return 'head1' if 'head2' is NULL
3. Do not allocate extra memory


Example:
Input:
head1: 5->6->2->1
head2: 4->1->8

Output:
5->2->0->3

*/

Node* rev(Node* ll) {
    Node *prev, *curr, *nxtOfCurr;
    if (ll && ll->next) {
        prev = ll;
        curr = ll->next;
    }
    else {
        return ll;
    }
    while (curr) {
        nxtOfCurr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxtOfCurr;
    }
    ll->next = NULL;
    return prev;
}

struct Node* SubtractTwoLists(struct Node* 11, struct Node* 12);
{
    //Your code here
    if (!l1 || !l2) return l1;
    l1 = rev(l1);
    l2 = rev(l2);
    Node* n1 = l1, * n2 = l2;
    while (n1 && n2) {
        if (n2->data > n1->data) {
            n1->next->data -= 1;
            n1->data += 10;
        }
        n1->data -= n2->data;
        n1 = n1->next;
        n2 = n2->next;
    }
    l1 = rev(l1);
    while (l1->data == 0) l1 = l1->next;
    return l1;
}


