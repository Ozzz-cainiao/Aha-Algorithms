//火柴棍等式
#include <iostream>

using namespace std;

//计算每个数用的火柴棍数量
int calculateNum(int i)
{
    int number = 0;
    int aaa[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; //存储每个数字火柴棍的数量
    while (i / 10 != 0)
    {
        //说明至少有两位
        //计算位数应该从后往前计算  从低位算起数量
        number += aaa[i % 10]; //求最后一位
        i = i / 10;
    }
    //最后加上仅剩的1位数
    number += aaa[i];
    return number;
}
int main()
{
    int num;
    //输入火柴棍的数量
    cout << "input num" << endl;
    cin >> num;
    // 对能组成的等式进行遍历  然后判断火柴棍的数量是否够用
    //最大组成的数字是(num-4)/2位个1
    for (int i = 0; i < 1111; i++)
    {
        for (int j = 0; j < 1111; j++)
        {
            int num_i = calculateNum(i);
            int num_j = calculateNum(j);
            int k = i + j;

            int num_k = calculateNum(k);
            if (num_k == num - num_i - num_j - 4) //数字的等式能成立
            {
                cout << i << "+" << j << "=" << k << endl;
            }
        }
    }
    system("pause");
    return 0;
}