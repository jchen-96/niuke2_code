//子序列可以不连续 ，子串必须连续

// kmp 求解str1中是否包含str2，包含的话，返回第一个位置

// 主要思想 ，利用前面的信息加速过程

//最长前缀和最长后缀的最长匹配长度

//   首先 求解str2的最长前后缀匹配长度

#include <iostream>
#include <string.h>
#include <vector>
#include <cstdio>

using namespace std;

class Code_01_KMP
{
  public:
    static int kmp(string s1, string s2)
    {
        if (s1.empty() || s2.empty() || s1.size() < s2.size())
        {
            return -1;
        }
        vector<int> next = getnext(s2);
        int i1 = 0;
        int i2 = 0;
        while (i1 < s1.size() && i2 < s2.size())
        {
            if (s1[i1] == s2[i2])
            {
                i1++;
                i2++;
            }
            else
            {
                if (next[i2] == -1)
                    i1++;
                else
                    i2 = next[i2];
            }
        }
        return i2 == s2.size() ? i1 - i2 : -1;
    }

    static vector<int> getnext(const string s)
    {
        vector<int> arr;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0)
                arr.push_back(-1);
            else if (i == 1)
                arr.push_back(0);
            else
            {
                arr.push_back(0);
                int temp = i - 1;
                while (arr[temp] != -1)
                {
                    if (s[arr[temp] == s[i - 1]])
                    {
                        arr[i] = arr[temp] + 1;
                        break;
                    }
                    else
                    {
                        temp = arr[temp];
                    }
                }
            }
        }
        return arr;
    }
};

int main(int argc, char const *argv[])
{
    string str = "abcabcababaccc";
    string match = "ddd";
    cout << Code_01_KMP::kmp(str, match) << endl;
    getchar();
    return 0;
}
