//队列
#include <stdio.h>
struct queue
{
    int data[100];
    int head;
    int tail;
};

int main()
{
    struct queue q;
    int i;
    //初始化队列
    q.head = 0;
    q.tail = 0;
    printf("START");
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &q.data[q.tail]);
        q.tail++;
    }
    while (q.head < q.tail)
    {
        printf("%d ", q.data[q.head]);
        q.head++; //删除队首

        q.data[q.tail] = q.data[q.head];
        q.tail++; //将队首复制到队尾
        q.head++; //删除队首
    }
}