#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int depth(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    return (left > right ? left : right) + 1;
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL){
        return true;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    if (abs(left - right) > 1){
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}