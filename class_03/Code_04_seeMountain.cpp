
#include <iostream>

//若每座山的高度都不同，则很简单
//找到最高的山峰和次高的山峰，任意选择其他一座山峰，都可以和最高，次高，组成一对  2(n-2) 加上 次高和最高这一对 2*n -3

//求解思路:
//使用单调栈结构（单调栈中的数据依次从大到小）



#include <stack>
#include <vector>

using namespace std;
//保存山峰的高度和出现的次数
class Times
{
  public:
    int value;
    int times;
    Times(int v) : value(v), times(1) {}
};

class Code_04_seeMountains
{
  public:
    static long communication(vector<int> arr)
    {
        if (arr.empty() || arr.size() <= 1)
        {
            return 0;
        }

        int length = arr.size();
        // 找到数组中最大值的位置
        int maxIndex = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            maxIndex = arr[i] > arr[maxIndex] ? i : maxIndex;
        }
        int maxValue = arr[maxIndex];

        //返回当前下标的下一个下标
        int index = nextIndex(length, maxIndex);
        long res = 0;
        stack<Times> ss;
        ss.push(Times(maxValue));

        //没有返回到原地
        while (index != maxIndex)
        {
            int value = arr[index];
            while (!ss.empty() && value > ss.top().value)
            {

                //每次弹出的时候，结算以当前元素为最低山峰的山峰对数目
                int tms = ss.top().times;
                ss.pop();
                res += getInternalSum(tms) + 2 * tms;
            }
            if (!ss.empty() && ss.top().value == value)
                ss.top().value++;
            else
                ss.push(Times(value));

            index = nextIndex(length, index);
        }

        //回到起点，栈中可能还有元素(按从大到小，从底向上排列)
        while (!ss.empty())
        {
            int tms = ss.top().times;
            ss.pop();
            res += getInternalSum(tms);
            if (!ss.empty())
            {
                res += tms;
                if (ss.size() > 1)
                    res += tms;
                else
                //单独计算第二条记录，如果最高的times ==1 则C(k,2)+k,否则 C(k,2) +2*k
                    res += ss.top().times > 1 ? tms : 0;
            }
        }

        return res;
    }

    // 返回n个相同高度的山峰可以互相看见的对数(排列组合C(k,2))
    static int getInternalSum(int k)
    {
        return k == 1 ? 0 : k * (k - 1) / 2;
    }

    //由于是环形，返回下一个索引
    static int nextIndex(int size, int curInex)
    {
        return curInex == size - 1 ? 0 : curInex + 1;
    }
};

int main(int argc, char const *argv[])
{
    cout<<Code_04_seeMountains::communication(vector<int>{1,2,4,5,3});
    getchar();
    return 0;
}
