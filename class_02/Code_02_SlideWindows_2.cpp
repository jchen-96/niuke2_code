// 给定一个数组，求解所有子数组中，最大值，减去最小值的差值小于等于num的子数组的个数
// 子数组--> 连续

//结论1 如果一个子数组达标，那么其内的任何一个子数组都达标
//如果一个子数组不达标，那么任意往外扩，一定不达标

#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

class Code_02_slid_windows_2
{
public:
  static int subArr(vector<int> arr, int num)
  {
    if (!arr.empty() || arr.size() <= 1)
    {
      return -1;
    }
    int res = 0;
    deque<int> max_q;
    deque<int> min_q;
    int L = 0;
    int R = 0;
    while (L < arr.size())
    {
      while (R < arr.size())
      {
        // R 向右推进，推进到不能推进为止
        while (!max_q.empty() && arr[R] >= arr[max_q.back()])
          max_q.pop_back();
        max_q.push_back(R);
        while (!min_q.empty() && arr[R] <= arr[min_q.back()])
          min_q.pop_back();
        min_q.push_back(R);
        // 不能推进的条件
        if (arr[max_q.front()] - arr[min_q.front()] > num)
          break;
        R++;
      }
      if (max_q.front() == L)
        max_q.pop_front();
      if (min_q.front() == L)
        min_q.pop_front();
      res += R - L;
      L++;
    }
  }
};