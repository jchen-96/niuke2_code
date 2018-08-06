// 给一个滑动的窗口，在窗口滑动过程中，不断求解窗口的最大值

#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>

using namespace std;

class Code_01_MaxOfWin
{
  public:
    static vector<int> getMaxArr(vector<int> arr, int win)
    {
        if (arr.empty() || arr.size() < win)
        {
            return vector<int>();
        }
        vector<int> res;
        deque<int> q;
        int r = 0;
        //窗口为[l,r]
        while (r < win)
        {
            while (!q.empty() && arr[r] >= arr[q.back()])
            {
                q.pop_back();
            }
            q.push_back(r++);
        }
        while (r < arr.size())
        {
            res.push_back(arr[q.front()]);
            if ((r - win) >= q.front())
                q.pop_front();
            while (!q.empty() && arr[r] >= arr[q.back()])
            {
                q.pop_back();
            }
            q.push_back(r++);
        }
        res.push_back(arr[q.front()]);

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> res = Code_01_MaxOfWin::getMaxArr(vector<int>{1,2,3,4,5,6,7,2,1,1,0,10}, 3);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    getchar();
    return 0;
}