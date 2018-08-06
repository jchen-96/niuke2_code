//判断一个一个树是不是另外一个树的子树

// 将二叉树进行序列化，再判断一个是不是另外一个的字串(KMP算法) 妙啊！

#include <iostream>
#include <string>
#include <vector>
#include<cstdio>

using namespace std;

class Node
{
  public:
    int value;
    Node *left;
    Node *right;

    Node(int v) : value(v), left(NULL), right(NULL) {}
};

class Code_04_KMP_subtree
{
  public:
    static bool isSubTree(Node *root1, Node *root2)
    {
        string s1 = serialTree(root1);
        cout << s1 << endl;
        string s2 = serialTree(root2);
        cout << s2 << endl;

        return kmp(s1, s2) != -1;
    }
    static string serialTree(Node *root)
    {
        if (root == NULL)
        {
            return "#!";
        }

        //将数字转换成字符串，真的是麻烦。。。。。。laji C++
        string v=to_string(root->value);
        string s=v+"!";
        string s1 = serialTree(root->left);
        string s2 = serialTree(root->right);
        return s += s1 + s2;
    }

    // 二叉树的反序列化
    static Node* deserialTree(string s){
        return NULL;
    }

    static int kmp(string s1, string s2)
    {
        if (s1.empty() || s2.empty() || s2.size() > s1.size())
        {
            return -1;
        }
        int i1 = 0;
        int i2 = 0;
        vector<int> next = getNext(s2);
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
                {
                    i1++;
                }
                else
                {
                    i2 = next[i2];
                }
            }
        }
        return i2 == s2.size() ? i1 - i2 : -1;
    }

    static vector<int> getNext(string s)
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
                while (arr[temp != -1])
                {
                    if (s[i - 1] == s[arr[temp]])
                    {
                        arr[i] = arr[temp + 1];
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
    Node *t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);
    t1->left->left = new Node(4);
    t1->left->right = new Node(5);
    t1->right->left = new Node(6);
    t1->right->right = new Node(7);
    t1->left->left->right = new Node(8);
    t1->left->right->left = new Node(9);

    Node *t2 = new Node(2);
    t2->left = new Node(4);
    t2->left->right = new Node(8);
    t2->right = new Node(5);
    t2->right->left = new Node(9);

    cout<<Code_04_KMP_subtree::isSubTree(t1,t2);
    getchar();
    return 0;
}
