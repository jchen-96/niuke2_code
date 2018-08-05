// Manacher 找到一个字符串中的最长回文子串

//回文直径
//辅助数组，以每个位置为中心，求回文半径，回文半径数组
//  最右回文右边界
//回文右边界的中心

/**
 * i在r外，暴力扩
 * i在r 内，i‘回文在L，R 内
 *          i' 回文在L,R 外
 *          i' 刚好压线
 * */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>

using namespace std;

class Code_02_Mancaher
{
  public:
    static string transString(string s)
    {
        string res(s.size() * 2 + 1, '#');
        int index = 0;
        for (int i = 0; i != res.size(); i++)
        {
            res[i] = (i & 1) == 0 ? '#' : s[index++];
        }
        return res;
    }
    static int Manacher(string s)
    {
        if (s.size() <= 0)
            return -1;
        string str = transString(s);
        int pR[str.size()];  //保存每个点的半径
        int core = -1;       //保存最右边界的中心
        int right = -1;      //保存最右边界
        int res = INT32_MIN; //用来保存结果

        for (int i = 0; i < str.size(); i++)
        {
            pR[i] = right > i ? min(pR[2 * core - i], right - i) : 1; //2*core-i 对称点的索引
            while (i + pR[i] < str.size() && i - pR[i] > -1)
            {
                if (str[i + pR[i]] == str[i - pR[i]])
                {
                    pR[i]++;
                }
                else
                {
                    break;
                }
            }
            if (i + pR[i] > right)
            {
                right = i + pR[i];
                core = i;
            }
            res = max(res, pR[i]);
        }
        return res - 1;
    }
};

int main(int argc, char const *argv[])
{
    string str1 = "abab";
    cout << Code_02_Mancaher::Manacher(str1) << endl;
    getchar();
    return 0;
}
