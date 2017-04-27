/*2017-04-27*/
#include<stdio.h>
#include<stdlib.h>

#define LENGTH 100
/*二叉树节点*/
struct binTreeNode {
    char data;
    struct binTreeNode *lchild;
    struct binTreeNode *rchild;
};

/*创建栈*/
struct stack {
    int top; //指向当前元素
    int tag[LENGTH];
    struct binTreeNode *arr[LENGTH]; 
};

/*进栈*/
void push(struct stack *s, struct binTreeNode *node) {
    if (s -> top >= LENGTH) {
        printf ("stack is full\n");
        return ;
    } else {
        s -> top++;
        s -> arr[s -> top] = node;
    }
    return ;
}

/*出栈*/
struct binTreeNode* pop(struct stack *s) {
    if (-1 == s -> top) {
        printf("this is not elements\n");
        return NULL;
    } else {
        s -> top--;
        return s -> arr[s -> top + 1];
    }
}

/*创建队列*/
struct queue {
    struct binTreeNode *arr[LENGTH];
    int front;
    int rear;
};

/*入队*/
int enterQueue(struct queue *q, struct binTreeNode *node) {
    if (q -> rear >= LENGTH) {
        printf("the queue is full\n");
        return 1;
    } else {
        q -> arr[q -> rear] = node;
        q -> rear ++;
    }
    return 0;
}

/*出队*/
struct binTreeNode* outQueue(struct queue *q) {
    if (q -> front == q -> rear) {
        printf("there is no element\n");
        return NULL;
    } else {
        q -> front++;
        return  q -> arr[q -> front - 1]; 
    }
}

/*创建二叉树，"#"代表NULL*/
struct binTreeNode* createBinTree() {
    struct binTreeNode* tree;
    char ch;

    scanf("%c", &ch);
    if ('#' == ch) {
        return NULL;
    } else {
        tree = (struct binTreeNode*)malloc(sizeof(struct binTreeNode));
        tree -> data = ch;
        tree -> lchild = createBinTree();
        tree -> rchild = createBinTree();
    }

    return tree;
}

/*二叉树前序递归遍历*/
int preOrder(struct binTreeNode* tree) {
    
    if (!tree) {
        return 0;
    } else {
        printf("%c\t", tree -> data);
        preOrder(tree -> lchild);
        preOrder(tree -> rchild);
    }

    return 0;
}

/*二叉树前序非递归遍历*/
int PreOrder(struct binTreeNode *tree) {
    struct stack s;
    s.top = -1;

    if (!tree) {
        return 0;
    } else {
        while(tree != NULL || s.top != -1) {
            while (tree != NULL) {
                printf("%c\t", tree -> data);
                push(&s, tree);
                tree = tree -> lchild;
            } 
            tree = pop(&s);
            tree = tree -> rchild;
        }
    }

    return 0;
}

/*二叉树中序递归遍历*/
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

/*二叉树中序非递归遍历*/
int MidOrder(struct binTreeNode *tree) {
    struct stack s;
    s.top = -1;

    if (!tree) {
        return 0;
    } else {
        while(tree != NULL || s.top != -1) {
            while(tree) {
                push(&s, tree);
                tree = tree -> lchild;
            }
            tree = pop(&s);
            printf("%c\t", tree -> data);
            tree = tree -> rchild;
        }
    }
}

/*二叉树后序递归遍历*/
int postOrder(struct binTreeNode *tree) {

    if (!tree) {
        return 0;
    } else {
        postOrder(tree -> lchild);
        postOrder(tree -> rchild);
        printf("%c\t", tree -> data);
    }

    return 0;
}

/*二叉树后序非递归遍历, */
int PostOrder(struct binTreeNode *tree) {
    struct stack s;
    s.top = -1;

    if (!tree) {
        return 0;
    } else {
        while (tree != NULL || s.top != -1) {
            while (tree) {
                push(&s, tree);
                s.tag[s.top] = 0;
                tree = tree -> lchild;
            } 
            if (s.tag[s.top] == 0) {
                tree = s.arr[s.top];
                s.tag[s.top] = 1;
                tree = tree -> rchild; //提供转向功能
            } else{
                while(s.tag[s.top] == 1) {
                    tree = pop(&s);
                    printf("%c\t", tree -> data);
                }
                tree = NULL; //必须将t置空，跳过向左走，直接向右走
            }
        }
    }

    return 0;
}

/*层序遍历*/
int levelOrder(struct binTreeNode *tree) {
    struct queue q;
    q.front = q.rear = 0;
    struct binTreeNode *temp;

    if (!tree) {
        printf("this is the empty tree!\n");
        return 1;
    } 

    enterQueue(&q, tree);

    while (q.front != q.rear) {
        tree = outQueue(&q);
        printf("%c\t", tree -> data);
        if (tree -> lchild) {
            enterQueue(&q, tree -> lchild);
        } 
        if (tree -> rchild) {
            enterQueue(&q, tree -> rchild);
        }
    }
}

/*二叉树的释放*/
int destroyBinTree(struct binTreeNode *tree) {

    if (!tree) {
        return 0;
    } else {
        destroyBinTree(tree -> lchild);
        destroyBinTree(tree -> rchild);
        free(tree);
    }

    return 0;
}

int main() {
    struct binTreeNode* tree;
    tree = createBinTree();
    printf("\n前序遍历\n");
    preOrder(tree);
    printf("\n");
    PreOrder(tree);
    printf("\n中序遍历\n");
    midOrder(tree);
    printf("\n");
    MidOrder(tree);
    printf("\n后序遍历\n");
    postOrder(tree);
    printf("\n");
    PostOrder(tree);
    printf("\n层序遍历\n");
    levelOrder(tree);
    printf("\n");
    destroyBinTree(tree);
    return 0;
}