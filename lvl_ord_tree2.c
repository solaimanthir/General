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

struct qnode{
    struct node * tnode;
    struct qnode *next;
};

void enque(struct node * data, struct qnode **frontptr, struct qnode **rearptr)
{
    struct qnode * rear = *rearptr;
    struct qnode *tmp = (struct qnode *)calloc(1, sizeof(struct qnode));
    tmp->tnode = data;
    if(rear == NULL)
    {
        *frontptr = tmp;
        *rearptr = tmp;
    }
    else
    {
        rear->next = tmp;
        *rearptr = tmp;
    }
}

struct node * deque(struct qnode **frontptr)
{
    struct qnode * front = *frontptr;

    if(front == NULL) return NULL;

    struct node * result = front->tnode;
    struct qnode *tmp = front;
    *frontptr = front->next;
    free(tmp);
    return result;
}

print_lvl_ord(struct node * root)
{
    struct node * tmp = root;
    struct qnode *front = NULL;
    struct qnode *rear = NULL;
    while(tmp){
        printf("%d ", tmp->data);

        if(tmp->left)
            enque(tmp->left, &front, &rear);
        if(tmp->right)
            enque(tmp->right, &front, &rear);

        tmp = deque(&front);
    }
}

void free_tree(struct node * root)
{
    if(root->left)
        free_tree(root->left);
    if(root->right)
        free_tree(root->right);
        free(root);
}
int main()
{
    struct node * root = alloc_node(1);
    root->left = alloc_node(2);
    root->right = alloc_node(3);
    root->left->left = alloc_node(4);
    root->left->right = alloc_node(5);
    print_lvl_ord(root);
    free_tree(root);
    return 0;
}
