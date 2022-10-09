//冒泡排序
#include <stdio.h>
// bubble function
void bubble(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            int temp;
            // little to big
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    printf("please input the num\n");
    int len;
    scanf("%d", &len);
    // get the array
    printf("please input the array\n");
    int a[100];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &a[i]);
        // a[i] = t;
    }
    bubble(a, len);
    // output
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}