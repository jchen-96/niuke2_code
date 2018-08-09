// 给定一个一个整型矩阵,只包含0和1两种元素，求其中元素全为1的最大的矩形面积
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;
class Code_03_maxSubMatrix{
    public:

    static int MaxAreaOfMatirx(vector<vector<int> > arr){
        vector<int> height(arr[0].size(),0);
        int maxArea=0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                height[j]=arr[i][j]==0?0:height[j]+1;
            }
            maxArea=max(maxButtom(height),maxArea);
        }
        cout<<maxArea<<endl;
        return maxArea;
    }


    //最重要的函数，如果一个数组表示一个直方图，每一个数表示高度，求解最大的矩形面积
    static int maxButtom(vector<int> height){
        if(height.empty()){
            return 0;
        }
        int maxArea=0;
        stack<int> ss;
        for(int i=0;i<height.size();i++){
            while(!ss.empty()&&height[i]<=height[ss.top()]){
                int j=ss.top();
                ss.pop();
                //如果栈弹出一个元素之后为空，将这个矩形的左边界设置为-1,否则左边界为左边第一个比当前数大的数
                int k=ss.empty()?-1:ss.top();
                int curArea=(i-k-1)*height[j];
                maxArea=max(curArea,maxArea);
            }
            ss.push(i);
        }

        while(!ss.empty()){
            int j=ss.top();
            ss.pop();
            int k=ss.empty()?-1:ss.top();
            int curArea=(height.size()-k-1)*height[j];
            maxArea=max(maxArea,curArea);
        }
        return maxArea;
    }
};
int main(int argc, char const *argv[])
{
    Code_03_maxSubMatrix::MaxAreaOfMatirx(vector<vector<int> >{{1,0,1,1},{1,1,1,1},{1,1,1,1}});
    getchar();
    return 0;
}
