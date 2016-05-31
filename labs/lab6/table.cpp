#include "table.h"

int count(node * root){
    if(root == nullptr){
        return 0;
    }else{
        int left;
        int right;
        int total;
        left = count(root->left);
        right = count(root->right);
        total = 1 + left + right;
        return total;
    }
}

int sum(node * root){
    //recursively compute sum of binary tree nodes
    if(root == nullptr){
        return 0;
    }else{
        int left;
        int right;
        int total;
        left = sum(root->left);
        right = sum(root->right);
        total = root->data + left + right;
        return total;
    }
}

int height(node * root){
    //recursively computer height of binary tree
    if(root == nullptr){
        return 0;
    }else{
        int left;
        int right;
        int treeHeight;
        left = height(root->left);
        right = height(root->right);
        if(left > right){
            treeHeight = 1 + left;
        }else{
            treeHeight = 1 + right;
        }
        return treeHeight;
    }
}
