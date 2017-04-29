//2017-04-29
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct binTreeNode {
    char data;
    int height;
    struct binTreeNode *lchild;
    struct binTreeNode *rchild;
}

int getTreeHeight(struct binTreeNode *tree) {
    int lheight = 0;
    int rheight = 0;
    
    if (NULL == tree) {
        return 0;
    } else if (tree -> lchild == NULL && tree -> rchild == NULL) {
        return NULL;
    } else {
        lheight = getTreeHeight(tree -> lchild);
        rheight = getTreeHeight(tree -> rchild);
        return (lheight > rheight) ? (lheight + 1) : (rheight + 1)
    }
}

/*single rotate right rotate*/
struct binTreeNode* singleRightRotate(struct binTreeNode *tree) {
    struct binTreeNode* temp = tree -> lchild;
    tree -> lchild = temp -> rchild;
    temp -> rchild = tree;

    tree -> height = getTreeHeight(tree);
    temp -> height = getTreeHeight(temp);

    return temp;
}

/*single rotate left rotate*/
struct binTreeNode* singleLeftRotate(struct binTreeNode *tree) {
    struct binTreeNode* temp = tree -> rchild;
    tree -> rchild = temp -> lchild;
    temp -> lchild = tree;

    tree -> height = getTreeHeight(tree);
    temp -> height = getTreeHeight(temp);

    return temp; 
}

/*double rotate left right rotate*/
struct binTreeNode* LRRotate(struct binTreeNode *tree) {
    tree -> lchild = singleLeftRotate(tree -> lchild);
    return singleRightRotate(tree);
}

/*double rotate right left rotate*/
struct binTreeNode* RLRotate(struct binTreeNode *tree) {
    tree -> rchild = singleRightRotate(tree -> rchild);
    return songleLeftRotate(tree);
}

/*insert a node*/
struct binTreeNode* insert(struct binTreeNode *tree, char data) {
    int bf = 0;
    
    if (NULL == tree) {
        tree = (struct binTreeNode*)malloc(sizeof(struct binTreeNode));
        tree -> data = data;
        tree -> lchild = NULL;
        tree -> rchild = NULL;
        tree -> height = 1;
    } else if (tree -> data > data) {
        tree -> lchild = insert(tree -> lchild, data);
        bf = getTreeHeight(tree -> lchild) - getTreeHeight(tree -> rchild);
        if (2 == bf) {
            if (data < tree -> lchild -> data) { //LL型， 右侧单旋
                tree = singleRightRotate(tree);
            } else { //LR型，左侧双旋
                tree = LRRotate(tree);
            }
        }
    } else if (tree -> data < data) {
        tree -> rchild = insert(tree -> rchild, data);
        bf = getTreeHeight(tree -> rchild) - getTreeHeight(tree -> lchild);
        if (2 == bf) {
            if (data > tree -> rchild -> data) { //RR型，右侧单旋
                tree = singleRightRotate(tree)
            } else { //RL型，右侧双旋
                tree = RLRotate(tree);
            }
        }
    } else { //if key is already exists, nothing to do
        ;
    }

    tree -> height = getTreeHeight(tree);
    return tree;
}

struct binTreeNode* del(struct binTreeNode* tree, char data) {
    struct binTreeNode *temp = NULL;

    if (!tree) {
        return NULL;
    }
    
    /*del a node*/
    if (tree -> data > data) {
        tree -> lchild = del(tree -> lchild, data);
    } else if (tree -> data < data) {
        tree -> rchild = del(tree -> rchild, data);
    } else {
        if (NULL != tree -> lchild) {
            for(temp = tree -> lchild; NULL != temp -> rchild; temp = temp -> rchild) {
                ；
            }
            tree -> data = temp -> data;
            tree -> lchild = del(tree -> lchild, temp -> data);
        } else if (NULL != tree -> rchild) {
            for(temp = tree -> rchild; NULL != tree -> lchild; temp = temp -> lchild) {
                ；
            }
            tree -> data = temp -> data;
            tree -> rchild = del(tree -> rchild, temp -> data);
        } else {
            free(tree);
            return NULL;
        }
    }

    /*adjust order*/
    if (getTreeHeight(tree -> lchild) - getTreeHeight(tree -> rchild) == 2) {
        if (getTreeHeight(tree -> lchild -> lchild) - getTreeHeight(tree -> lchild -> rchild) == 1) { //LL型
            tree = singleRightRotate(tree);
        } else { //LR型
            tree = LRRotate(tree);
        }
    } else if (getTreeHeight(tree -> rchild) - getTreeHeight(tree -> lchild) == 2) {
        if (getTreeHeight(tree -> rchild -> rchild) - getTreeHeight(tree -> rchild -> lchild) == 1) { //RR型
            tree = singleLeftRotate(tree);
        } else { //RL型
            tree = RLRotate(tree);
        }
    } else {
        ；
    }

    tree -> height = getTreeHeight(tree);
    return tree;
}