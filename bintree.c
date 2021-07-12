//
//  bintree.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.

/** https://webis.de/downloads/lecturenotes/algorithms-and-datastructures/unit-de-search-trees.pdf */


#include <dciman.h>
#include "bintree.h"


//Link-basierter Binärbaum
binTree *t_init(){
    binTree *tmp = (binTree *)malloc(sizeof(binTree));
    tmp->root = NULL;
    tmp->size = 0;
    return tmp;
}

// TODO: double pointer einführen oder über return Werte lösen
node *insertNode(node *start, int key, const char *data){
    node *newNode;
    if (start == NULL) { /* whether the root node or not */
        newNode = (node *) malloc(sizeof(node));
        if (newNode != NULL) {
            newNode->data = (char*) malloc(strlen(data)+1);
            strcpy(newNode->data, data);
            newNode->key = key;
            newNode->right = newNode->left = NULL;
        }
        return newNode; /* allocation the new node */
    }/* left child tree */
    if (key < start->key) {
        newNode = insertNode(start->left, key, data);
        if (start->left == NULL)
            start->left = newNode;
    } else {
        newNode = insertNode(start->right, key, data);
        if (start->right == NULL)
            start->right = newNode; /* update the tree root pointer */
    }
    
    // TODO: Schritte 1-3
    // 1. Balancefaktor für den "start" Knoten mit Hilfe von treeDepth berechnen
    // 2. Überprüfung der Lastigkeit
    // 3. Ausführung der einzelnen Rotationen

    return newNode;
}

node *insert(binTree *t, int key, const char *data){
    node *newNode;
    newNode = insertNode(t->root, key, data);// Root pointer
    if (t->root == NULL) t->root = newNode;
    if (newNode != NULL) t->size++;// End operation
    return newNode;

}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int treeDepth(node *start){
    if (start == NULL) {
        return 0;
    }else {
        return 1 +  max(treeDepth(start->left),
                        treeDepth(start->right));
    }
}
int getBalance(node *start){
    int balance = 0;

    if(start->left) balance += treeDepth(start->left);
    if(start->right) balance -= treeDepth(start->right);

    return balance;
}

// TODO: Implementierung Rotationen
int getKey(node *start){
    if(start->left && start->right){
        return start->left->key - start->right->key;
    }else if(start->left && start->right == NULL){
        return start->left->key;
    }else if(start->left== NULL && start->right ){
        return -start->right->key;
    }
}
// LL-Rotation ist symmetrisch zur RR-Rotation.
node *rotateLL (node *start){
    node *a = start;
    node *b = a->left;
    a->left = b->right;
    b->right = a;

    return b;
}
//RL-Rotation ist symmetrisch zur LR-Rotation.
node *rotateRL (node *start){
    node *a = start;
    node *b = a->right;
    node *c = b->right->left;

    a->right = c->left;
    b->left = c->right;
    c->left = a;
    c->right = b;
    return c;
}
// RR-Rotation ist symmetrisch zur LL-Rotation.
node *rotateRR (node *start){
    node *a = start;
    node *b = a->right;

    a->right = b->left;
    b->left = a;

    return b;
}
//LR-Rotation ist symmetrisch zur RL-Rotation.
node *rotateLR(node *start){
    node *a = start;
    node *b = a->left;
    node *c = b->left->right;

    a->left = c->right;
    b->right = c->left;
    c->right = a;
    c->left = b;

    return c;
}

void balanceTree(binTree *tree) {
    node * newRoot;
    newRoot = deleteNode(tree->root);
    if (newRoot != tree->root) tree->root = newRoot;

}
