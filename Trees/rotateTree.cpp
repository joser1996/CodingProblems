#include <stdlib.h>
#include <iostream>

/* 
 *   root->left->left = root->right;
 *   root->left->right = root;
 *   root->left = NULL;
 *   root->right = NULL; 
 */

struct Node {
    int data;
    Node* left, *right;
};

struct Node* newNode(int data) {
    struct Node* n = new struct Node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}


Node* flipBinaryTree(Node* root) {
    // Base cases
    if (root == NULL) return root;
    if (root->left == NULL && root->right == NULL) return root;

    Node* flippedRoot = flipBinaryTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = NULL;
    return flippedRoot;
}

int height(Node* root) {
    if (root == NULL) return 0;
    else {
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        return (lHeight > rHeight ? lHeight + 1 : rHeight + 1);
    }
}

void printLevel(Node* root, int level) {
    if (root != NULL) {
        if (level == 1) std::cout << root->data << " ";
        else {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }
}


void printLevelOrder(Node* root) {
    int h = height(root);
    for(int i = 1; i <= h; i++) {
        printLevel(root, i);
        std::cout << std::endl;
    }
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);

    std::cout << "Current Level order of tree: " << std::endl;
    printLevelOrder(root);

    root = flipBinaryTree(root);
    std::cout << "Level order traversal of flipped tree: " << std::endl;
    printLevelOrder(root);
    return 0;
}