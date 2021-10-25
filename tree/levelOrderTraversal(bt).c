// A Level Order Traversal is a traversal which always traverses based on the level of the tree.
// So, this traversal first traverses the nodes corresponding to Level 0, and then Level 1, and so on, from the root node.
// In the example Binary Tree above, the level order traversal will be:

// (Root) 10 -> 20 -> 30 -> 40 -> 50

// We must first find the height of the tree
// We need to find a way to print the nodes corresponding to every level.

//output:
// Level 0: 10 -> 
// Level 1: 20 -> 30 -> 
// Level 2: 40 -> 50 -> 
 
 
// -----Complete Level Order Traversal:-----
// 10 -> 20 -> 30 -> 40 -> 50 -> 


#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node Node;
struct Node {
    int value;
    // Pointers to the left and right children
    Node* left, *right;
};
 
Node* init_tree(int data) {
    // Creates the tree and returns the
    // root node
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}
Node* create_node(int data) {
    // Creates a new node
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}
 
 
int tree_height(Node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
 
void print_level(Node* root, int level_no) {
    // Prints the nodes in the tree
    // having a level = level_no
     
    // We have a auxiliary root node
    // for printing the root of every
    // subtree
    if (!root)
        return;
    if (level_no == 0) {
        // We are at the top of a subtree
        // So print the auxiliary root node
        printf("%d -> ", root->value);
    }
    else {
        // Make the auxiliary root node to
        // be the left and right nodes for
        // the subtrees and decrease level by 1, since
        // you are moving from top to bottom
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }
 
}
 
void print_tree_level_order(Node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}
 
int main() {
    // Program to demonstrate Level Order Traversal
 
    // Create the root node having a value of 10
    Node* root = init_tree(10);
     
    // Insert nodes onto the tree
    root->left = create_node(20);
    root->right = create_node(30);
    root->left->left = create_node(40);
    root->left->right = create_node(50);
     
    // Level Order Traversal
    print_tree_level_order(root);

    return 0;
}