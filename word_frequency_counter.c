#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the tree node
Typedef struct Node {
    Char word[100]; // Word stored in the node
    Int count;      // Frequency count for the word
    Struct Node *left, *right; // Pointers to left and right children
} Node;

// Function to create a new tree node
Node* createNode(char *word) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    Strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a word into the BST
Void insert(Node** root, char *word) {
    If (*root == NULL) {
        *root = createNode(word);
    } else if (strcmp(word, (*root)->word) < 0) {
        Insert(&((*root)->left), word);
    } else if (strcmp(word, (*root)->word) > 0) {
        Insert(&((*root)->right), word);
    } else {
        (*root)->count++;
    }
}

// Function for in-order traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf(“%s: %d\n”, root->word, root->count);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the BST
void freeTree(Node* root) {
    If (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to drive the word frequency counter
int main() {
    Node* root = NULL;
    char buffer[100];
    printf(“Enter words separated by spaces (type ‘.’ to finish):\n”);
    
    While (1) {
        Scanf(“%99s”, buffer);
        If (strcmp(buffer, “.”) == 0) {
            Break;
        }
        Insert(&root, buffer);
    }

    printf(“Word frequencies:\n”);
    inorderTraversal(root);
    freeTree(root);
    return 0;
}