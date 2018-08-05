//给定一个字符串，在末尾添加若干字符 ，使得原字符串可以重复两次，要求添加的字符数达到最小

//关键在于kmp next 数组的应用

#include <iostream>
#include<cstdio>
#include <vector>

using namespace std;

class Code_03_KMP_twice
{

  public:
    static string makeTwice(string s)
    {
        if (s.size() <= 0)
            return NULL;
        string res(s);
        s = s + "#";
        vector<int> next = getNext(s);
        int len = next[s.size() - 1];
        for (int i = len; i < s.size()-1; i++)
        {
            res += s[i];
        }
        return res;
    }

    static vector<int> getNext(string s)
    {
        vector<int> arr;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0)
            {
                arr.push_back(-1);
            }
            else if (i == 1)
            {
                arr.push_back(0);
            }
            else
            {
                arr.push_back(0);
                int temp = i - 1;
                while (arr[temp] != -1)
                {
                    if (s[i - 1] == s[arr[temp]])
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
    string test2 = "abracadabra";
    cout << Code_03_KMP_twice::makeTwice(test2) << endl;
    getchar();
    return 0;
}
