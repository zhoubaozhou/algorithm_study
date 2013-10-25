/**
 * 题目：http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
 *
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == NULL) return;
        if (root->left == NULL || root->right == NULL) return;
        root->left->next = root->right;
        if(root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
