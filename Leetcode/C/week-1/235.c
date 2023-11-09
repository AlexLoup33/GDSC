#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
        if (root == NULL) return NULL;
        if (root->val == p->val || root->val == q->val) return root;
    
        struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
        struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
        if (left != NULL && right != NULL) return root;
        else if (left == NULL) return right;
        else if (right == NULL) return left;
        return NULL;
}