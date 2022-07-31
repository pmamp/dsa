/*
Trim a Binary Search Tree

Problem Statement
You are given a BST, each of whose nodes is represented as:
struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *TrimBinarySearchTree(struct TreeNode *root, int minValue, int maxValue);

The function accepts a pointer 'root' of a BST and two integers, 'minValue' and 'maxValue'.
Implement the function to trim the input BST such that all the data in the trimmed BST are
between minValue and maxValue (both inclusive). Return the root node of the trimmed BST 
from the function. Ensure that the returned tree is a valid BST.


Note:
1. Do not create a new tree, only modify the input tree
2. In case trimming does not yield any node, or the input is NULL, the return NULL


Example:
Input:

			13
	3				14
1		4				18


minValue=4, maxValue=14


Output:

	13
4		14


*/

struct TreeNode* TrimBinarySearchTree(struct TreeNode* root, int minValue, int maxValue) {
	if (root == NULL) return NULL;

	root->left = TrimBinarySearchTree(root->left, minValue, maxValue);
	root->right = TrimBinarySearchTree(root->right, minValue, maxValue);

	if (root->key < minValue) {
		struct TreeNode* rChild = root->right;
		delete root;
		return rChild;
	}
	if (root->key > maxValue) {
		struct TreeNode* lChild = root->left;
		delete root;
		return lChild;
	}

	return root;
}
