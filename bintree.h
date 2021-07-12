//
//  bintree.h
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#ifndef bintree_h
#define bintree_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_ {
    int key;//Balancefaktor?? 高度差（平衡因子）
    char *data;
    struct node_ *left;
    struct node_ *right;
} node;

typedef struct binTree_ {
    int size;//=Height (Wurzel einens Binary Search Tree)
    node *root;//私有資料結構
} binTree;

// Funktionsprototypen

binTree *t_init(void);
node *insertNode(node *, int, const char *);
node *insert(binTree *, int, const char *);
int treeDepth(node *);

// TODO: Rotationsprototypen
int getBalance(node *start);
node *rotateLL(node *start);//left child node of left child tree(left-left)
node *rotateRL(node *start);
node *rotateRR(node *start);
node *rotateLR(node *start);
int getKey(node* start);
node * deleteNode(node *start, int size);
void balanceTree(binTree *tree);

#endif /* bintree_h */
