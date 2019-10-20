#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
typedef struct NODESTRUCT {
    struct NODESTRUCT* left;
    struct NODESTRUCT* right;
    int data;
} node;

typedef struct {
    node* root;
} tree;

node* newNode(int data) {
    node* myNode = (node*) malloc(sizeof(node));
    if(myNode != NULL) {
    myNode->left = NULL;
    myNode->right = NULL;
    myNode->data = data;
    return myNode;
    } else {
        printf("Creation FAILED!");
        fflush(stdout);
        return NULL;
    }
}
int insert(tree* myTree, int data) {
    int depth = 1;
    node* current = NULL;
    if(myTree->root == NULL) {
        myTree->root = newNode(data);
        return depth;
    } else {
        current = myTree->root;
        while(1 == 1) {
            
            if(data <= current->data) {
                if(current->left == NULL) {
                    depth++;
                    current->left = newNode(data);
                    return depth;
                } else {
                    depth++;
                    current = current->left;
                }
            }
            else {
                if(current->right == NULL) {
                    depth++;
                    current->right = newNode(data);
                    return depth;
                } else {
                    depth++;
                    current = current->right;
                }
            }
        }
    }
}

int main() {
    tree myTree;
    myTree.root = NULL;
    int length = 0;
    int temp = 0;
    int i = 0;
    cin >> length;
    for(i = 0; i < length; i++) {
        cin >> temp;
        cout << insert(&myTree, temp) << " ";
    }
    return 0;
}