//2017-04-28
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct binTreeNode {
    char data;
    struct binTreeNode *lchild;
    struct binTreeNode *rchild;  
};

struct binTreeNode* createBST() {
    struct binTreeNode *tree;
    char ch;
    scanf("%c", &ch);

    if (ch == '#') {
        return NULL;
    } else {
        tree = (struct binTreeNode*)malloc(sizeof(struct binTreeNode));
        tree -> data = ch;
        tree -> lchild = createBST();
        tree -> rchild = createBST();
    }
    return tree;
}

/*迭代实现*/
struct binTreeNode* searchNode(struct binTreeNode *tree, char ch) {
    struct binTreeNode *temp;
    temp = tree;  
    if (!tree) {
        printf("the tree is null\n");
        return NULL;
    } else {
        while (temp != NULL && temp -> data != ch) {
            if (ch < temp -> data) {
                temp = temp -> lchild;
            } else if (ch == temp -> data) {
                return temp;
            } else {
                temp = temp -> rchild;
            }
        }
        printf("sorry, we can't find the char you want\n");
    }
    return NULL;
}

/*递归实现*/
struct binTreeNode* SearchNode(struct binTreeNode *tree, char ch) {
    if (!tree || tree -> data == ch) {
        return tree;
    } else if (tree -> data > ch) {
        return SearchNode(tree -> lchild, ch);
    } else {
        return SearchNode(tree -> rchild, ch);
    }
}

/*BST的插入*/
int insertBST(struct binTreeNode *tree, struct binTreeNode *val) {
    struct binTreeNode *temp = NULL;
    struct binTreeNode *node = NULL;
    temp = tree;
    if (!tree) {
        tree =  val;
        return 0;
    } else {
        while (temp) {
            if (temp -> data > val -> data) {
                node = temp;
                temp = temp -> lchild;
            } else if(temp -> data == val -> data){
                return 0;
            } else {
                node = temp;
                temp = temp -> rchild;
            }
        }
        if (val -> data > node -> data) {
            node -> rchild = val;
        } else {
            node -> lchild = val;
        }
    }
    return 0;
}

/*递归BST插入*/
struct binTreeNode* insert(struct binTreeNode *tree, char x) {
    struct binTreeNode *p;

    if (NULL == tree) {
       p = (struct binTreeNode*)malloc(sizeof(struct binTreeNode));
       p -> data = x;
       p -> lchild = NULL;
       p -> rchild = NULL;
       return p;
    } else if (tree -> data > x) {
        tree -> lchild = insert(tree -> lchild, x);
    } else {
        tree -> rchild = insert(tree -> rchild, x);
    }
    return tree;
}

/*非递归BST插入*/
void Insert(struct binTreeNode *tree, char x) {
    struct binTreeNode *p = NULL;
    struct binTreeNode *temp = NULL;

    p = (struct binTreeNode*)malloc(sizeof(struct binTreeNode));
    p -> data = x;
    p -> lchild = NULL;
    p -> rchild = NULL;

    if (NULL == tree) {
        tree = p;
        return ;
    } else {
        temp = tree;
        while (temp -> lchild != p && temp -> rchild != p) {
            if (x < temp -> data) {
                if (temp -> lchild) {
                    temp = temp -> lchild;
                } else {
                    temp -> lchild = p;
                }
            } else {
                if (temp -> rchild) {
                    temp = temp -> rchild;
                } else {
                    temp -> rchild = p;
                }
            }
        }
    }
    return ;
}

/*删除节点*/
struct binTreeNode* delNode(struct binTreeNode *tree, char x) {
    struct binTreeNode *p, *q, *temp;
    bool find = false;
    p = tree;

    while(p && !find) {
        if (x == p -> data) {
            find = true;
        } else if (x < p -> data) {
            q = p;
            p = p -> lchild;
        } else {
            q = p;
            p = p -> rchild;
        }
    }

    if (!p) {
        printf("sorry we can't find the node\n");
        return NULL;
    } else {
        /*叶子节点*/
        if (NULL == p -> lchild && NULL == p -> rchild) {
            if (p == tree) {
                tree = NULL;
            } else if (q -> lchild == p) {
                q -> lchild = NULL;
            } else {
                q -> rchild = NULL;
            }
            return p;
        } else if (p -> lchild == NULL || p -> rchild == NULL) {  //有左子树或者是右子树
            if (p == tree) {
                if (p -> lchild == NULL) {
                    tree = p -> rchild;
                } else {
                    tree = p -> lchild;
                }
            } else {
                if (q -> lchild == p && p -> rchild) {
                    q -> lchild = p -> rchild;
                } else if (q -> lchild == p && p -> lchild) {
                    q -> lchild = p -> lchild;
                } else if (q -> rchild == p && p -> rchild) {
                    q -> rchild = p -> rchild;
                } else {
                    q -> rchild = p -> lchild;
                }
            }
        } else {//左右子树均存在
            temp = p;
            q = p -> lchild;

            while (q -> rchild) {
                temp = q;
                q = q -> rchild;
            }
            
            p -> data = q -> data;
            if (temp == p) {
                p -> lchild = q -> lchild;
            } else {
                temp -> rchild = q -> lchild;
            }

            return q;
        }
    }
}

int midOrder(struct binTreeNode *tree) {

    if (!tree) {
        return 0;
    } else {
        midOrder(tree -> lchild);
        printf("%c\t", tree -> data);
        midOrder(tree -> rchild);
    }

    return 0;
}

/*测试集532##4##87##9##*/
int main() 
{
    struct binTreeNode *tree;
    tree = createBST();
    delNode(tree, '2');
    midOrder(tree);
    printf("\n");
    delNode(tree, '3');
    midOrder(tree);
    printf("\n");
    delNode(tree, '8');
    printf("\n");
    midOrder(tree);
    return 0;
}