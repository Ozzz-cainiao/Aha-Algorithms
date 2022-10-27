// 3_0 9张扑克牌组成三个三位数的等式
//采用深度优先搜索算法进行解算

#include <iostream>

using namespace std;
int n; //
int a[10], book[10];
void dfs(int step);
int main()
{
    cin >> n;
    dfs(1); //从起始位开始 自己递归
    system("pause");
    return 0;
}
void dfs(int step)
{
    if (step == n + 1)
    {
        if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
        {
            cout << a[1] << a[2] << a[3] << "+" << a[4] << a[5] << a[6] << "=" << a[7] << a[8] << a[9] << endl;
        }

        return; //输出完就返回 不再继续调用这个函数
    }
    for (int i = 1; i <= 9; i++)
    {
        if (book[i] == 0)
        {
            book[i] = 1;//已使用
            a[step] = i;
            dfs(step + 1);

            book[i] = 0;
        }
    }
    return;
}