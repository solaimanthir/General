#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node * alloc_node(int data)
{
    struct node * tmp = (struct node *)calloc(1, sizeof(struct node));
    tmp->data = data;
    return tmp;
}

int height(struct node * root)
{
    if(root == NULL) return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    if(lheight > rheight)
        return lheight+1;
    else
        return rheight+1;
}

print_lvl(struct node * root, int lvl)
{
    if(lvl == 1)
        printf("%d ", root->data);
    else {
        if(root->left)
            print_lvl(root->left, lvl-1);
        if(root->right)
            print_lvl(root->right, lvl-1);
    }
}

print_lvl_ord(struct node * root)
{
    int lvl = height(root);
    int i;
    for(i = 1; i<= lvl; ++i){
        print_lvl(root, i);
        printf("\n");
    }
}

int main()
{
    struct node * root = alloc_node(1);
    root->left = alloc_node(2);
    root->right = alloc_node(3);
    root->left->left = alloc_node(4);
    root->left->right = alloc_node(5);
    print_lvl_ord(root);
    return 0;
}
