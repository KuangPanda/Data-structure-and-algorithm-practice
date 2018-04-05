/*
 * 二叉树递归遍历
 */

#include<iostream>
#include<cstdlib>

/*
 * 树的存储结构
 */
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

/*
 * 队列
 */
typedef struct queueNode {
    Node* value;
    struct queueNode *next;
}queueNode;

typedef struct queue {
    queueNode *head;
    queueNode *tail; 
}Queue;

/*
 * 初始化队列
 */
Queue* initQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue -> head = NULL;
    queue -> tail = NULL;
}

/*
 * 入队
 */
void enterQueue(Queue *queue, queueNode node) {
    if(!queue -> head) {
        queue -> head = &node;
        queue -> tail = &node; 
    } else {
        queue -> tail -> next = &node;
        queue -> tail = queue -> tail -> next;
    }
}

/*
 * 出队
 */
queueNode* outQueue(Queue *queue) {
    queueNode *node;
    if(!queue -> head) {
        printf("%s\t", "队列为空");
    } else if(queue -> head == queue -> tail) {
        node = queue -> head;
    } else {
        node = queue -> head;
        queue -> head = queue -> head -> next;
    }
    return node;
}

/*
 * 创建二叉树
 */
Node* createBinTree() {
    int value = 0;
    Node *node = (Node*)malloc(sizeof(Node));
    scanf("%d", &value);

    if(0 == value) {
        node = NULL;
    } else {
        node -> value = value;
        node -> left = createBinTree();
        node -> right = createBinTree();
    }

    return node;
}

/*
 * 先序遍历
 */
void preOrder(Node *tree) {
    if(tree) {
        printf("%d\t", tree -> value);
        preOrder(tree -> left);
        preOrder(tree -> right);
    }
}

/*
 * 中序遍历
 */
void inOrder(Node *tree) {
    if(tree) {
        inOrder(tree -> left);
        printf("%d\t", tree -> value);
        inOrder(tree -> right);
    }
}

/*
 * 后序遍历
 */
void afterOrder(Node *tree) {
    if(tree) {
        afterOrder(tree -> left);
        afterOrder(tree -> right);
        printf("%d\t", tree -> value);
    }
}

/*
 * 层序遍历
 */
void layerOrder(Node *tree) {
    queue* queue;
    queueNode* node_1 = (queueNode*)malloc(sizeof(queueNode));
    queueNode* node_2 = (queueNode*)malloc(sizeof(queueNode));

    if(tree) {
        node_1 -> value = tree;
        node_1 -> next = NULL;

        while(node_1) {
            printf("%d\t", node_1 -> value -> value);
            node_2 -> next = NULL;
            if(node_1 -> value -> left) {
                node_2 -> value = node_1 -> value -> left;
                enterQueue(queue, *node_2);
            }
            if(node_1 -> value -> right) {
                node_2 -> value = node_1 -> value -> right;
                enterQueue(queue, *node_2);
            }
            node_1 = outQueue(queue);
        }
    }
}

int main() {
    Node *node = NULL;
    node = createBinTree();
    layerOrder(node);
    return 0;
}