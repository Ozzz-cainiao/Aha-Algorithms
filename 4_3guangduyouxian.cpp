//广度优先搜索算法
//通过一侧一层扩展的方法来找到小哈  扩展时每发现一个点就将这个点加入到队列中，直到到达目标位置为止
#include <iostream>

using namespace std;

//用队列来储存走过的位置  用结构体实现队列
struct note
{
    int x;
    int y;
    int f;    //在队列中的编号
    int step; //起点到当前位置的步数
};
int main()
{
    struct note que[2501]; //队列的扩展
    int map[51][51] = {0};
    int book[51][51] = {0};
    //定义一个表示探索方向的数组
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    //定义队列头尾的位置；
    int head, tail;
    //地图的长度
    int lenx, leny;

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
    int A_pos[2], B_pos[2];
    //输入小ha的坐标
    cout << "please input B_POS" << endl;
    cin >> B_pos[0] >> B_pos[1];
    //输入小哼的起始坐标
    cout << "please input A_POS" << endl;
    cin >> A_pos[0] >> A_pos[1];

    //队列初始化
    head = 0;
    tail = 0;
    //向队列插入迷宫入口坐标
    que[tail].x = A_pos[0];
    que[tail].y = A_pos[1];
    que[tail].f = 0;
    que[tail].step = 0;
    tail++;
    book[A_pos[0]][A_pos[1]] = 1; //将走过的点标记上
    bool flag = false;            //证明还没有到达标记点

    int x, y; //当前位置
    //队列不为空时进行循环
    while (head < tail)
    {
        //从当前位置向4个方向探索
        for (int i = 0; i < 4; i++)
        {
            //计算下一个点的坐标
            x = que[head].x + next[i][0];
            y = que[head].y + next[i][1];
            //判断是否越界
            if (x >= lenx || x < 0 || y < 0 || y >= leny)
                continue;
            //判断是否是障碍物或者已经在路径中
            if (map[x][y] == 0 && book[x][y] == 0)
            {
                book[x][y] = 1;
                //将这个点入队
                que[tail].x = x;
                que[tail].y = y;
                que[tail].step =que[head].step+1;//当前的步数是父节点步数+1
                que[tail].f = head; //因为这个点是从Head扩展出来的，所以它的父亲是head
                tail++;
            }
            if (x == B_pos[0] && y == B_pos[1])
            {
                //到达目标点了
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            break;
        }
        head++;//这个父节点向4个方向遍历完就移到下一个节点 作为新的父节点进行4个方向的遍历
    }
    cout << "最短的步数为："<<que[tail - 1].step<<endl;
    system("pause");
    return 0;
}