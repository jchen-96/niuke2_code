#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

//给定一个字符串，往字符串的后面添加最少的字符，使得其成为一个回文串

using namespace std;

class Code_05_Manacher_01
{
  public:
    static string getString(string s)
    {
        string res(s.size() * 2 + 1, '#');

        int index = 0;
        for (int i = 0; i < res.size(); i++)
        {
            res[i]=(i&1)==0?'#':s[index++];
        }
        return res;
    }

    static int Manahcer(string s){
        if(s.empty()){
            return -1;
        }
        string str=getString(s);
        int right=-1;
        int core=-1;
        int pR[str.size()];
        for(int i=0;i<str.size();i++){
            pR[i]=right>i?min(pR[core*2-i],right-i):1;
            while(i+pR[i]<str.size()&&i-pR[i]>-1){
                if(str[i+pR[i]]==str[i-pR[i]]){
                    pR[i]++;
                }else{
                    break;
                }
            }
            if(i+pR[i]>right){
                right=i+pR[i];
                core=i;
            }
            if(right=str.size()){
                return -1;//undo
            }
        }
        return -1;

    }
};