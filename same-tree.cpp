// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

/* Approach: Only condition we need to make sure is that the values of given nodes are equal and that their sub-trees are equal.
This approach checks each node in both trees level by level. */

// https://leetcode.com/problems/same-tree/submissions/1619039095
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p==NULL && q==NULL) return true;
            if (p==NULL & q!=NULL) return false;
            if (p!=NULL && q==NULL) return false;
            return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
    };