//解救小哈  深度优先搜索算法
#include <iostream>

using namespace std;

//放一些全局变量
int map[50][50], book[50][50]; //地图以及标记
int A_pos[2], B_pos[2];        //二人的起始位置
int minstepnum = 99999;        //步数计数
int lenx, leny;
void dfs(int x, int y, int stepcount);
int main()
{
    //输入地图的长宽

    cout << "please input lenx and leny" << endl;
    cin >> lenx >> leny;
    //输入地图
    cout << "please input map" << endl;
    for (int i = 0; i < lenx; i++)
    {
        for (int j = 0; j < leny; j++)
        {
            scanf("%d", &map[i][j]); //读入地图 0代表空地 1代表障碍物
        }
    }

    //输入小ha的坐标
    cout << "please input B_POS" << endl;
    cin >> B_pos[0] >> B_pos[1];
    //输入小哼的起始坐标
    cout << "please input A_POS" << endl;
    cin >> A_pos[0] >> A_pos[1];
    //从A的起始位置开始搜索
    book[A_pos[0]][A_pos[1]] = 1; //起点先标记上

    dfs(A_pos[0], A_pos[1], 0);

    cout << "get B and the minmal stepcount is" << minstepnum << endl;
    system("pause");
    return 0;
}
//深度优先的搜索算法
void dfs(int x, int y, int stepcount)
{
    int next[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    //判断是否是边界  是就输出返回
    if (x == B_pos[0] && y == B_pos[1])
    {
        if (stepcount < minstepnum)
            minstepnum = stepcount;
        return;
    }
    //不是边界 就遍历递归  将尝试过的点标记上
    int tx, ty;
    for (int i = 0; i < 4; i++)
    {
        //计算下一个点的坐标
        tx = x + next[i][0];
        ty = y + next[i][1];
        //判断是不是边界or障碍物
        // if (tx > -1 && ty > -1 && tx < lenx && ty < leny)
        // {
        if (tx < 0 || tx >= lenx || ty < 0 || ty >= leny)
            continue;
        if (map[tx][ty] == 0 && book[tx][ty] == 0)
        {
            book[tx][ty] = 1; //走到这点就标记上  又败在了=和==的区别上
            dfs(tx, ty, stepcount + 1);
            book[tx][ty] = 0;
        }
        // }
    }
    return;
}