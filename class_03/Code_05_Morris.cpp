// Morris 遍历，采用空间复杂度为O(1) 实现，不用任何栈空间

/**
 * 开始cur 指针指向头节点
 * 
 * 当cur 有左孩子 ，找到左子树的最右节点mostright
 *          mostright 的右指针为空，mostright->right=cur, cur=cur.left
 *          mostright 的右指针为==cur，mostright-ritht=null,cur=cur.right
 **/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

class Node
{
  public:
    int value;
    Node *left;
    Node *right;

    Node(int v) : value(v), left(NULL), right(NULL) {}
};

class Code_05_Morris
{
  public:
    static void MorrisPre(Node *root)
    {
        if (root == NULL)
            return;
        Node *cur = root;
        Node *mostRight = NULL;
        while (cur != NULL)
        {
            mostRight = cur->left;
            if (mostRight != NULL)
            {
                while (mostRight != NULL && mostRight->right != NULL)
                    mostRight = mostRight->right;
                if (mostRight->right == NULL)
                {
                    mostRight->right = cur;
                    cout << cur->value << " ";
                    cur = cur->left;
                    continue;
                }
                else
                {
                    mostRight->right = NULL;
                }
            }
            else
                cout << cur->value << " ";
            cur = cur->right;
        }
    }
    static void MorrisIn(Node *root)
    {
        if (root == NULL)
            return;
        Node *cur = root;
        Node *mostRight = NULL;
        while (cur != NULL)
        {
            mostRight = cur->left;
            if (mostRight != NULL)
            {
                while (mostRight != NULL && mostRight->right != NULL)
                    mostRight = mostRight->right;
                if (mostRight->right == NULL)
                {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }
                else
                    mostRight->right = NULL;
            }

            cout << cur->value << " ";
            cur = cur->right;
        }
    }
};