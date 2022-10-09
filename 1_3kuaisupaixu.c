// 快速排序
#include <stdio.h>
int a[100];
void quicksort(int initnum, int len)
{
    if (len < initnum)
        return;

    int temp;
    temp = a[initnum];
    int i, j;
    i = initnum;
    j = len;
    while (i != j)
    {
        //一直寻找
        if (a[j] >= temp && i < j)
            j--;
        if (a[i] <= temp && i < j)
            i++;
        //发现目标就开始交换位置
        if (i < j)
        {
            int t;
            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
    //最终将基准数归位
    a[initnum] = a[i];
    a[i] = temp;
    quicksort(initnum, i - 1);
    quicksort(i + 1, len);
}
int main()
{
    printf("please input num");
    int len;
    scanf("%d", &len);
    printf("please input array");

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(0, len - 1);
    // output
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}