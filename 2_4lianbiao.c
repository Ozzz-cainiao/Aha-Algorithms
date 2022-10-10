// 2_4 链表
#include <stdio.h>
#include <stdlib.h>

//创建一个表示链表的结点类型
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head, *p, *q, *t;
    int n, a;
    printf("please input num");
    scanf("%d", &n);
    head = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        //动态申请一个空间 用来存放一个节点 并用临时指针p指向这个节点
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a;
        p->next = NULL;
        if (head == NULL)
        {
            //证明是第一个节点
            head = p;
        }
        else
            q->next = p; //上一个节点的下一个节点指针指向这里
        q = p;
    }
    scanf("%d", &a);
    t = head;

    while (t != NULL)
    {
        if (t->next->data > a)
        {
            p = (struct node *)malloc(sizeof(struct node));
            p->data = a;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
        // printf("%d ", t->data);
        // t = t->next; //继续指向链表的下一个元素 直到为指向下一个元素的指针为空
    }
    t = head;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next; //继续指向链表的下一个元素 直到为指向下一个元素的指针为空
    }
    return 0;
}