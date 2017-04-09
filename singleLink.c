//2017-04-09
#include<stdio.h>
#include<stdlib.h>

struct Studetn {
    int num;
    float score;
    struct Student *next;
};

/*创建链表*/
struct Student *create() {
    int n = 0;    //链表的长度
    struct Student *head;    //头结点
    struct Student *p1 = NULL;    //p1保存新创建的节点
    struct Student *p2 = NULL;    //p2保存原链表最后一个节点的地址

    p1 = (struct Student*)malloc(sizeof(struct Student));
    p2 = p1;

    if(p1 == NULL) {
        printf("\nCan't create it, try it again");
        return NULL;
    }
    else {
        head = NULL;
        printf("Please input %d node -- num:", n + 1);
        scanf("%d", &(p1 -> num));
    }

    while(p1 -> num != 0) {
        n += 1;
        if(n == 1) {
            head = p1;
            p2 -> next = NULL;
        }
        else {
            p2 -> next = p1;
        }
        p2 = p1;
        p1 = (struct Student*)malloc(sizeof(struct Student));
        printf("Please input %d node --num:", n + 1);
        scanf("%d", &(p1 -> num));
    }
    p2 -> next = NULL;
    free(p1)；
    p1 = NULL;  //把释放的变量清空置为NULL，否则会成为野指针
    return head;
}

/*输出节点*/
void Print(struct Student *head) {
    struct Student *p = head;
    if (head != NULL) {
        printf("head is %o\n", head);
        do {
            printf("节点地址：%o,\tnum:%d\n", p, p -> num);
            p = p -> next;
        } while(p != NULL)
    }
}

/*删除节点*/
struct Student* Del(struct Student *head, int num) {
    struct Student *p1;
    struct Student *p2;

    if (head == NULL) {
        printf("\nList is null!\n");
        return head;
    }

    p1 = head;
    while (p1 -> num != num && p1 -> next != NULL) {
        p2 = p1;
        p1 = p1 -> next;
    }

    if (p1 -> num == num) {
        if(p1 == head) { //如果要删除的节点是头节点
            head = p1 -> next;
        }
        else {
            p2 -> next = p1 -> next;
        }

        free(p1);
        p1 = NULL;
        printf("\delete %ld success!\n", num);
    }
    else {
        printf("\n%d not found\n", num);
    }
    return head;
}

/*销毁链表*/
void DestoryList(struct Student *head) {
    struct Student *p1 = NULL;
    if (head == NULL) {
        return 0;
    }
    while(head) {
        p = head -> next;
        free(head);
        head = p;
    }
    return 1;
}

/*插入节点*/
struct Student *Insert(struct Student *head, int num, struct Student* node) {
    struct Student *p1;
    if (head == NULL) {
        head = node;
        node -> next = NULL;
        return head;
    }

    p1 = head;
    while (p1 -> num != num && p1 -> next != NULL) {
        p1 = p1 -> next;
    }
    if (p1 -> num == num) {
        node -> next = p1 -> next;
        p1 -> next = node;
    }
    else {
        printf("\n%ld not found\n", num);
    }
    return head;
}

/*反序链表*/
struct Student* Reverse(struct Student *head) {
    struct Student *p;
    struct Student *p1;
    struct Student *p2;

    p1 = NULL;
    p2 = head;
    while (p2 != NULL) {
        p = p2 -> next;
        p2 -> next = p1;
        p1 = p2;
        p2 = p;
    }
    head = p1;
    return head;
}

/*选择排序(由小到大)*/
struct Student* SelectSort(struct Student *head) {
    struct Student *first; //保留排序后有序链的表头指针
    struct Student *tail; //保留排序后有序链的表尾指针
    struct Student *p_min; //保留键值更小的节点的前驱节点的指针
    struct Student *min; //存储最小的节点
    struct Student *p; //当前比较的节点

    first = NULL;
    while (head != NULL) {
        for (p = head, min = head; p -> next != NULL; p = p -> next) {
            if (p -> next -> num < min -> num) {
                p_min = p; //保存找到节点的前驱节点，
                min = p -> next; //保存键值更小的节点
            }
        }

        //首先要把min放入有序链表中，二是根据相应的条件判断，min要离开原链表
        if (first == NULL) {
            first = min;
            tail = min;
        }
        else {
            tail -> next = min;
            tail = min;
        }

        if(min == head) {  //如果找到的最小节点是第一个节点
            head = head -> next;
        }
        else {
            p_min -> next = min -> next;
            //前次最小节点的next指向当前min的next，就让min离开了原链表
        }
    }

    if(first != NULL) {
        tail -> next = NULL;
    }
    head = first;
    return head;
}

/*直接插入排序*/
struct Student* InsertSort(struct Student* head) {
    struct student *first;
    struct student *t;
    struct student *p, *q;

    first = head -> next;
    head -> next = NULL;

    while (first != NULL) {
        for (t = first, q = head; ((q != NULL) && (q -> num < t -> num)); p = q, q = q -> next);
        first = first -> next;
        if( == head) {
            head = t;
        }
        else {
            p -> next = t;
        }
        t -> next = 1;
    }
    return head;
}