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
      return vector<int>();
    vector<int> res;
    deque<int> q;
    int r = 0;
    //窗口为[l,r]
    //下面的代码可以整合到下面去
    // while (r < win)
    // {
    //     while (!q.empty() && arr[r] >= arr[q.back()])
    //     {
    //         q.pop_back();
    //     }
    //     q.push_back(r++);
    // }
    while (r < arr.size())
    {
      while (!q.empty() && arr[r] >= arr[q.back()])
        q.pop_back();
      q.push_back(r);
      if (q.front() == r - win)
        q.pop_front();
      if (r - win >= -1)
        res.push_back(arr[q.front()]);
      r++;
    }
    return res;
  }
};

int main(int argc, char const *argv[])
{
  vector<int> res =
      Code_01_MaxOfWin::getMaxArr(vector<int>{4, 3, 5, 4, 3, 3, 6, 7}, 3);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  getchar();
  return 0;
}
