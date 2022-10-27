//深度优先搜索算法
//深度优先搜索算法的关键在于解决“当下如何做”。“下一步如何做”是和“当下如何做是一样的”  
//当下如何做的方法就是把每种可能都去尝试一边 当这一步解决之后遍进入下一步（递归的调用 注意递归的跳出条件）
//深度优先搜索的基本模型：

//  void dfs(int step)
// {
//     判断边界 并返回
//     尝试每一种可能
//     for (size_t i = 0; i < count; i++)
//     {
//         继续下一步
//         dfs(step+1)
//     }
//     返回
// }
#include <iostream>

using namespace std;

int a[10], book[10], n; //全局变量  一会检查一下是否默认初值为0；

void dfs(int step);
int main()
{
    cout << "请输入盒子和纸牌的数量" << endl;
    cin >> n;

    //调用深度搜索算法
    dfs(1);
    system("pause");
    return 0;
}
void dfs(int step) // step表示当前站在第几个盒子前
{
    if (step == n + 1)
    {
        //证明前n个盒子已经放好扑克牌
        // 打印出结果
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        return; //输出完就返回 不再继续调用这个函数
    }
    for (int i = 1; i <= n; i++)
    {
        //判断扑克牌是否还在手上
        if (book[i] == 0)
        {
            book[i] = 1;
            a[step] = i; //将i放在了step盒子中
            //走到下一个盒子前
            dfs(step + 1); //通过递归来实现  自己调用自己  就是调用自己 导致盒子+1+1 //
            //然后走到最后一个盒子 后 将结果输出
            book[i] = 0; //将刚才尝试的扑克牌收回
        }
    }
    return;
}
