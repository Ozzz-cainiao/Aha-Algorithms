// 3-2 炸弹人小游戏  改写成CPP

//谨记：判断条件==！
#include <iostream>
#include <string>
// #include <stdio.h>
using namespace std;

int main()
{
    int row, col;

    int sum, max = 0;
    int x_max = 0, y_max = 0;
    int x, y;
    cout << "please input row and colume " << endl;

    cin >> row;
    cin >> col;
    cout << "row=" << row << endl;
    cout << "col=" << col << endl;
    //设置地图数组
    char a[20][20];
    cout << "map:" << endl;

    for (int i = 0; i < row; i++)
    {

        cin >> a[i]; //按行输入
    }
    cout << "ok!" << endl;
    //采用枚举法来计算每个点能够炸到的个数
    for (int i = 0; i < row; i++) // hang
    {
        for (int j = 0; j < col; j++) // lie
        {
            if (a[i][j] == '.')
            {
                //炸弹可以放置在这个位置
                //开始计算能炸到的敌人个数
                //向4各方向进行计算  遇到墙“#”就停止前进
                sum = 0;
                x = i;
                y = j;
                while (a[x][y] != '#') //向下寻找
                {
                    if (a[x][y] == 'G')
                        sum++;
                    x++;
                }
                x = i;
                y = j;
                while (a[x][y] != '#')
                {
                    if (a[x][y] == 'G')
                        sum++;
                    x--;
                }
                x = i;
                y = j;
                while (a[x][y] != '#') //向下寻找
                {
                    if (a[x][y] == 'G')
                        sum++;
                    y++;
                }
                x = i;
                y = j;
                while (a[x][y] != '#') //向下寻找
                {
                    if (a[x][y] == 'G')
                        sum++;
                    y--;
                }
                if (sum > max)
                {
                    max = sum; //更新最大消灭敌人数
                    x_max = i;
                    y_max = j; //记录最大的坐标
                }
            }
        }
    }

    cout << "maxium=" << max << "location x" << x_max << "location y" << y_max << endl;
    // system("pause");
    return 0;
}
