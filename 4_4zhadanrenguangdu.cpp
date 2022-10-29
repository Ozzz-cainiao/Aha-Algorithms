//广度优先计算炸弹人
//先广度优先搜索出都能去到哪些点，然后在当前点上计算能够炸死的敌人个数

#include <iostream>

using namespace std;

char map[20][20];
int book[20][20];

struct node
{
    int x;
    int y;
    int sum; //记录这个点能炸多少人
};
int getnum(int x, int y);
int main()
{
    int lenx, leny;
    int start[2]; //起始点

    cout << "please input lenx leny" << endl;
    cin >> lenx >> leny;
    cout << "please input map" << endl;
    for (int i = 0; i < lenx; i++)
    {
        for (int j = 0; i < leny; i++)
        {
            scanf("%c", &map[i][j]);
        }
    }
    cout << "please input start pos" << endl;
    cin >> start[0] >> start[1];

    //开始进行广度搜索
    int head, tail;
    struct node que[401];

    book[20][20] = {0};
    book[start[0]][start[1]] = 1;

    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    //队列初始化
    head = 0;
    tail = 0;

    //往队列插入起始坐标
    que[tail].x = start[0];
    que[tail].y = start[1];
    tail++;

    //当前位置坐标
    int x, y;
    int maximum = 9999;
    while (head < tail)
    {
        //枚举4个方向
        for (int i = 0; i < 4; i++)
        {
            //计算下一点的位置
            x = que[head].x + next[i][0];
            y = que[head].y + next[i][1];

            //判断下一点是否出界
            if (x < 0 || x >= lenx || y < 0 || y >= leny)
                continue;
            if (map[x][y] == '.' && book[x][y] == 0)
            {
                //先入队
                que[tail].x = x;
                que[tail].y = y;
                //在这点计算杀敌数
                que[tail].sum = getnum(x, y);
                if (que[tail].sum < maximum)
                    maximum = que[tail].sum;
                tail++;
            }
        }
        head++;
    }
    cout << "maximum=" << maximum << endl;

    system("pause");
    return 0;
}
//计算当前位置的杀敌数
int getnum(int x, int y)
{
    int sum = 0;
    int tx, ty;
    //从当前点开始 向4个方向进行计数，遇到墙壁就停止
    tx = x;
    ty = y;
    while (map[tx][ty] != '#')
    {
        if (map[tx][ty] == 'G')
            sum++;
        tx++;
    }
    tx = x;
    ty = y;
    while (map[tx][ty] != '#')
    {
        if (map[tx][ty] == 'G')
            sum++;
        ty++;
    }
    tx = x;
    ty = y;
    while (map[tx][ty] != '#')
    {
        if (map[tx][ty] == 'G')
            sum++;
        tx--;
    }
    tx = x;
    ty = y;
    while (map[tx][ty] != '#')
    {
        if (map[tx][ty] == 'G')
            sum++;
        ty--;
    }

    return sum;
}