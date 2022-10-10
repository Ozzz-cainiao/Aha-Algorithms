// 2_2 ZHAN
#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], s[101];
    int len;
    gets(a);
    len = strlen(a);
    int mid = len / 2 - 1;

    int top = 0;
    //将mid前的数据入栈
    for (int i = 0; i <= mid; i++)
    {
        ++top;
        s[top] = a[i];
    }
    //判断字符串的长度是奇数还是偶数 找到需要匹配的起始下标
    int next;
    if (len % 2 == 0)
        next = mid + 1;
    else
        next = mid + 2;
    for (int i = next; i <= len - 1; i++)
    {
        if (s[top] != a[i])
            break;
        top--;
    }
    if (top == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
