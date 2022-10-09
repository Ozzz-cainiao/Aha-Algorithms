//第1章 桶排序
#include <stdio.h>
int main()
{
    //先创造出桶来 用于盛放次数
    int tong[10] = {0};
    // read data from input

    printf("please input data\n");
    int t;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &t);
        tong[t]++; // read in and +1
    }
    // output
    // for (int i = 0; i < 10; i++)// little to big
    // {
    //     for (int j = 0; j < tong[i]; j++)
    //         printf("%d", i);
    // }
        for (int i = 9; i >=0; i--)// little to big
    {
        for (int j = 0; j < tong[i]; j++)
            printf("%d ", i);
    }
    // system("pause");
    getchar();
    getchar();
    return 0;
}