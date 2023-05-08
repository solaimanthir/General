#include <iostream>
#include <queue>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

void printlvlord(node *root)
{
    if(NULL == root) return;

    queue<struct node *>q;

    q.push(root);
    while(1){
        int cnt = q.size();
        if(0 == cnt) break;
        while(cnt > 0){
            struct node *tmp = q.front();
            cout << tmp->data << " ";
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            cnt--;
        }
        cout << endl;
    }
}

int main()
{
    /*insert tree code*/

    printlvlord(root);
    return 0;
}
