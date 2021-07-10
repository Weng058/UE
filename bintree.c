//
//  bintree.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#include "bintree.h"



binTree *t_init(){
    binTree *tmp = (binTree *)malloc(sizeof(binTree));
    tmp->root = NULL;
    tmp->size = 0;
    return tmp;
}

// TODO: double pointer einführen oder über return Werte lösen
node *insertNode(node *start, int key, const char *data){
    node *newNode;
    if (start == NULL) { /* 是否是根節點 */
        newNode = (node *) malloc(sizeof(node));
        if (newNode != NULL) {
            newNode->data = (char*) malloc(strlen(data)+1);
            strcpy(newNode->data, data);
            newNode->key = key;
            newNode->right = newNode->left = NULL;
        }
        return newNode; /* 傳回新節點位置 */
    }/* 左子樹 */
    if (key < start->key) {
        newNode = insertNode(start->left, key, data);
        if (start->left == NULL)
            start->left = newNode;
    } else { /* 右子樹 */
        newNode = insertNode(start->right, key, data);
        if (start->right == NULL)
            start->right = newNode; /* 傳回樹根指標 */
    }
    
    // TODO: Schritte 1-3
    // 1. Balancefaktor für den "start" Knoten mit Hilfe von treeDepth berechnen
    // 2. Überprüfung der Lastigkeit
    // 3. Ausführung der einzelnen Rotationen

    return newNode;
}

node *insert(binTree *t, int key, const char *data){
    node *newNode;
    newNode = insertNode(t->root, key, data);/* 樹根指標 */
    if (t->root == NULL) t->root = newNode;
    if (newNode != NULL) t->size++;/* 終止條件 */
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
    }
    else {
        return 1 +  max(treeDepth(start->left),
                        treeDepth(start->right));
    }
}

// TODO: Implementierung Rotationen
// rotateLL
node * rotateLL (node *start){
    printf("Rotating LL %d\n", start->key);
    node *a = start;
    node *b = a->left;

    a->left = b->right;
    b->right = a;

    return b;
}

// rotateRL
node * rotateRL (node *start){
    printf("Rotating RL %d\n", start->key);
    node *a = start;
    node *b = a->right;
    node *c = b->left;

    a->right = c->left;
    b->left = c->right;
    c->right = b;
    c->left = a;

    return c;
}
// rotateRR
node * rotateRR (node *start){
    printf("Rotating RR %d\n", start->key);
    node *a = start;
    node *b = a->right;

    a->right = b->left;
    b->left = a;

    return b;
}
// rotateLR
node* rotateLR(node *start){
    printf("Rotating LR %d\n", start->key);

    node *a = start;
    node *b = a->left;
    node *c = b->right;

    a->left = c->right;
    b->right = c->left;
    c->left = b;
    c->right = a;
    return c;
}