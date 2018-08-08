// 单调栈结构解决 一个数组中左边离它最近的比他大的，和右边最近的比他大的

// 单调栈，做到从栈底到栈顶的数，依次由大到小(严格从大到小)

// 特殊情况，相同数字

// question:给定一个数组（没有重复数组），返回这个数组中每一个元素的右边第一个大于它的数，和左边第一个大于它的数
#include <stack>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class Code_01_MaxOfWin
{
  public:
    static void getMax(vector<int> arr)
    {
        if (arr.empty() || arr.size() <= 1)
            return;
        vector<int> left_max(arr.size(), INT32_MIN);
        vector<int> right_max(arr.size(), INT32_MIN);
        stack<int> tem;
        int index = 0;
        while (index < arr.size())
        {
            while (index < arr.size() && tem.empty() || arr[tem.top()] > arr[index])
                tem.push(index++);
            if (index < arr.size())
            {
                int i = tem.top();
                tem.pop();
                right_max[i] = arr[index];
                if (!tem.empty())
                    left_max[i] = arr[tem.top()];
            }
        }
        while (!tem.empty())
        {
            int i = tem.top();
            tem.pop();
            if (!tem.empty())
                left_max[i] = arr[tem.top()];
        }

        for (auto v : left_max)
            cout << v << " ";
        cout<<endl;
        for (auto v : right_max)
            cout << v << " ";
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 2, 4, 1, 5, 6, 7};
    Code_01_MaxOfWin::getMax(arr);
    getchar();
    return 0;
}
