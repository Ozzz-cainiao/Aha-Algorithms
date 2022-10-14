#include <stdio.h>
int main()
{
    int data[101], right[101];
    int t;
    int num;
    //读入已有的数
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data[i]);
    }
    //初始化数组right
    for (int i = 0; i < num; i++)
    {
        if (i != num - 1) //如果不是最后一个数
        {
            right[i] = i + 1; //就是直接指向下一个位置
        }
        else
            right[i] = -1; //如果是最后一个数 就指向开头
    }
    printf("all ready!");
    //在末尾加一个数  data数组直接在最后加数就行 将right数组里的索引更改一下
    num++;
    scanf("%d", &data[num - 1]);
    //更改索引  在哪个位置插入？
    //从链表的头部开始遍历
    t = 0;
    while (t != -1)
    {
        if (data[right[t]] > data[num - 1]) //如果当前节点下一个节点的值大于待插入数，将数插入到中间
        {
            right[num - 1] = right[t]; //将当前节点指向的下一节点的数移到最后一位
            right[t] = num - 1;        //将当前位置的下一个节点指向最后一个数
            break;                     //完成插入后就跳出循环
        }
        t = right[t]; // t是查找的索引 一直向后查找
    }

    //输出链表的所有数  下边错误  链表就是要拿right的索引去寻找
    // for (int i = 0; i < num; i++)
    // {
    //     printf("%d ", data[right[i]]);
    // }
    //正确输出
    t = 0;
    while (t != -1)
    {
        printf("%d", data[t]);
        t = right[t]; // t是查找的索引 一直向后查找
    }

    return 0;
}