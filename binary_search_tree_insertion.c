#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}


struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}


int main() {
    struct Node* root = NULL;
    int keys[] = {15, 8, 20, 3, 10, 17, 25};
    int numKeys = sizeof(keys) / sizeof(keys[0]);


    for (int i = 0; i < numKeys; i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    int searchKey = 10;
    struct Node* result = search(root, searchKey);

    if (result != NULL) {
        printf("Key %d found in the BST.\n", searchKey);
    } else {
        printf("Key %d not found in the BST.\n", searchKey);
    }

    return 0;
}