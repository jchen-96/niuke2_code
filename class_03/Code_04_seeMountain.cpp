//单调栈问题

// 给定一个数组，有多少个元素就有多少座山，数组中每个元素代表相应山的高度，这些山首尾相连，围成一个圈子
// 规定，相邻的两座山可以互相看见，不相邻的两座山可以互相看见的前提是，这两座山之间没有比这两座山高的山峰
// 求解:有多少对山峰
#include <iostream>

//若每座山的高度都不同，则很简单
//找到最高的山峰和次高的山峰，任意选择其他一座山峰，都可以和最高，次高，组成一对  2(n-2) 加上 次高和最高这一对 2*n -3

//难得是存在相同高度的山，只能用单调栈进行求解
//求解思路:



//网易笔试题，难得有点过分，左神都写了1个多少小时
#include <stack>
#include <vector>

using namespace std;
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
        stack<Times> tt;
        tt.push(Times(maxValue));

        //没有返回到原地
        while (index != maxIndex)
        {
            value = arr[index];
            while (!times.empty() && value > tt.top()->value)
            {

                //每次弹出的时候，结算以当前元素为最低山峰的山峰对数目
                int tms = tt.top()->times;
                tt.pop();
                res += getInternalSum(tms) + 2 * tms;
            }
            if (!ss.empty() && ss.top()->value == value)
                ss.top()->value++;
            else
                ss.push(Times(value));

            index = nextIndex(length, index);
        }
        while (!ss.empty())
        {
            int tms = ss.top()->times;
            ss.pop();
            res += getInternalSum(tms);
            if (!ss.empty())
            {
                res += tms;
                if (ss.size() > 1)
                    res += tms;
                else
                //单独计算第二条记录，如果最高的times ==1 则C(k,2)+k,否则 C(k,2) +2*k
                    res += ss.top()->times > 1 ? tms : 0;
            }
        }

        return res;
    }

    // 返回n个相同高度的山峰可以互相看见的对数
    static int getInternalSum(int k)
    {
        return n == 1 ? 0 : n * (n - 1) / 2;
    }

    static int nextIndex(int size, int curInex)
    {
        return curInex == size - 1 ? 0 : curInex + 1;
    }
}