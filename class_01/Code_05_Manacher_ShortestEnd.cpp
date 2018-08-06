#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

//给定一个字符串，往字符串的后面添加最少的字符，使得其成为一个回文串

using namespace std;

class Code_05_Manacher_ShortestEnd
{
  public:
    static string getString(string s)
    {
        string res(s.size() * 2 + 1, '#');

        int index = 0;
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = (i & 1) == 0 ? '#' : s[index++];
        }
        return res;
    }

    static string Manahcer(string s)
    {
        if (s.empty())
        {
            return "";
        }
        string str = getString(s);
        int right = -1;
        int core = -1;
        int pR[str.size()];
        int res = -1;
        for (int i = 0; i < str.size(); i++)
        {
            pR[i] = right > i ? min(pR[core * 2 - i], right - i) : 1;
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
            if (right == str.size())
            {
                res = core;
                break;
            }
        }
        cout << res << endl;
        for (int i = res - pR[res]; i >= 0; i--)
        {
            str += str[i];
        }
        string f_res = "";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '#')
                f_res += str[i];
        }
        return f_res;
    }
};
int main(int argc, char const *argv[])
{
    cout << Code_05_Manacher_ShortestEnd::Manahcer("abcd123321") << endl;
    getchar();
    return 0;
}
