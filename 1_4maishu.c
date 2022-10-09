// 1-4买书
#include <stdio.h>
int main()
{
    // tongpaixu
    printf("please input the num\n");
    int num;
    scanf("%d", &num);
    printf("please input the array\n");
    int array[100];
    int tong[100] = {0}; //来计数
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
        tong[array[i]]++;
    }
    for (int i = 0; i < 100; i++)
    {
        if (tong[i] != 0)
            printf("%d ", i);
    }
}
