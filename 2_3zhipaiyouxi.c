//纸牌游戏

#include <stdio.h>

struct queue
{
    int data[1000];
    int head;
    int tail;
};
struct stack
{
    int data[10];
    int top;
};
int main()
{
    struct queue q1, q2;
    struct stack s;
    int book[10] ;
    for (int i = 0; i < 10;i++)
    {
        book[i] = 0;
        // q1.data[i] = 0;
        // q2.data[i] = 0;
    }

        //初始化队列
    q1.head = 0;
    q1.tail = 0;
    q2.head = 0;
    q2.tail = 0;
    //初始化栈
    s.top = 0;

    //初始化两人的牌
    printf("init q1 array\n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    printf("init q2 array\n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }
    int t; //当前出的牌
    while (q1.head < q1.tail && q2.head < q2.tail)
    {
        t = q1.data[q1.head];
        if (book[t] == 0)
        {
            //表明当前桌上没有这张牌
            book[t] = 1;
            q1.head++; //此牌出队
            //桌上牌入栈
            s.top++;//从1开始
            s.data[s.top] = t;
            
        }
        else
        {
            //桌上有这张牌  先出牌 再收牌
            q1.head++;            //出牌
            q1.data[q1.tail] = t; //放入队尾
            q1.tail++;
            // s.data[s.top]=t;//  这句不能有 先入栈 就无法在while循环中找到了另一个t
            // s.top++;
            while (s.data[s.top] != t)
            {
                
                book[s.data[s.top]] = 0;
                //将牌依次放入队尾
                q1.data[q1.tail] = s.data[s.top]; //放入队尾
                q1.tail++;
                s.top--;

            }
        }

        t = q2.data[q2.head];
        if (book[t] == 0)
        {
            //表明当前桌上没有这张牌
            book[t] = 1;
            q2.head++; //此牌出队
            //桌上牌入栈
            s.top++;
            s.data[s.top] = t;
            
        }
        else
        {
            //桌上有这张牌  先出牌 再收牌
            q2.head++;            //出牌
            q2.data[q2.tail] = t; //放入队尾
            q2.tail++;
            // s.data[s.top]=t;//  这句不能有 先入栈 就无法在while循环中找到了另一个t
            // s.top++;
            while (s.data[s.top] != t)
            {
                
                book[s.data[s.top]] = 0;
                //将牌依次放入队尾
                q2.data[q2.tail] = s.data[s.top]; //放入队尾
                q2.tail++;
                s.top--;
                
            }
        }
    }
    if (q2.head == q2.tail)
    {
        printf("a win\n");
        printf("a has :");

        for (int i = q1.head; i < q1.tail; i++)
        {
            printf("%d ", q1.data[i]);
        }
        if (s.top > -1)
        {
            printf("\ntable has:");
            for (int i = 1; i <= s.top; i++)
            {
                printf("%d ", s.data[i]);
            }
        }
        else
            printf("\nNothing on the table");
    }
    else
    {
        printf("b win\n");
        printf("b has :");

        for (int i = q2.head; i < q2.tail; i++)
        {
            printf("%d ", q2.data[i]);
        }
        if (s.top > -1)
        {
            printf("\ntable has:");
            for (int i = 1; i <= s.top; i++)
            {
                printf("%d ", s.data[i]);
            }
        }
        else
            printf("\nNothing on the table");
    }
    // system("pause");
    getchar();
    getchar();
    return 0;
}