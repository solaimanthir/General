//Author: Solai

#include <stdio.h>
#include <stdlib.h>

#define MAX_QSZ 4 //arbitrary
int queue[MAX_QSZ];
int arr_front = -1;
int arr_rear = -1;

#define MAX_STSZ 4 //arbitrary
int stk[MAX_STSZ];
int arr_tos = -1;

typedef struct node node;

struct node
{
    int data;
    node * next;
};

node * list_tos = NULL;

node * list_front = NULL;
node * list_rear = NULL;

void arr_enqueue(int data)
{
    //queue is full?
    if((MAX_QSZ-1) == arr_rear)
    {
        printf("array queue is full\n");
        return;
    }

    //adjust front
    if(-1 == arr_front)
        arr_front = 0;

    ++arr_rear;
    queue[arr_rear] = data;
}

int arr_dequeue()
{
    if(-1 == arr_front)
    {
        printf("A. empty queue\n");
        return -1;
    }

    if(arr_front > arr_rear)
    {
        printf("B. empty queue\n");
        arr_front = -1;
        return -1;
    }

    int data = queue[arr_front];
    ++arr_front;
    return data;
}

void arr_push(int data)
{
    //stack is full?
    if((MAX_STSZ-1) == arr_tos)
    {
        printf("err: can't add since stack is already full\n");
        return;
    }

    ++arr_tos;
    stk[arr_tos] = data;
}

int arr_pop()
{
    //empty stack?
    if(-1 == arr_tos)
    {
        printf("err: empty stack\n");
        return -1;
    }
    
    int data = stk[arr_tos];
    --arr_tos;
    return data;
}

void list_enqueue(int data)
{
    node * newn = (node *)malloc(sizeof(node));
    if(NULL == newn)
    {
        printf("error: malloc\n");
        return;
    }

    newn->data = data;
    newn->next = NULL;

    if(NULL == list_rear)
    {
        list_front = newn;
        list_rear = newn;
        return;
    }

    list_rear->next = newn;
    list_rear       = newn;
}

int list_dequeue()
{
    if(NULL == list_front)
    {
        printf("error: trying list dequeue in empty queue\n");
        return -1;
    }

    int data = list_front->data;
    node * temp = list_front;
    list_front = list_front->next;
    if(NULL == list_front)
    {
        list_rear = NULL;
    }
    free(temp);

    return data;
}

void list_push(int data)
{
    node * newn = (node *)malloc(sizeof(node));
    if(NULL == newn)
    {
        printf("error: malloc\n");
        return;
    }

    newn->data = data;
    newn->next = list_tos;

    list_tos = newn;
}

int list_pop()
{
    if(NULL == list_tos)
    {
        printf("error: empty stack\n");
        return -1;
    }

    int data = list_tos->data;
    node * temp = list_tos;
    list_tos = list_tos->next;
    free(temp);
    return data;
}

int main()
{
    int data = -1;

    for(int i = 1; i <= 5; ++i)
    {
        arr_enqueue(i);
    }

    for(int i = 1; i <= 5; ++i)
    {  
        arr_push(i);
    }

    for(int i = 1; i <= 5; ++i)
    {
        list_enqueue(i);
    }

    for(int i = 1; i <= 5; ++i)
    {
        list_push(i);
    }
    
    for(int i = 1; i <= 5; ++i)
    {
        data = arr_dequeue();
        if(-1 != data)
            printf("arr q data: %d\n", data);
    }
    
    for(int i = 1; i <= 5; ++i)
    {
        data = arr_pop();
        if(-1 != data)
            printf("arr stk data: %d\n", data);
    }

    for(int i = 1; i <= 5; ++i)
    {
        data = list_dequeue();
        if(-1 != data)
            printf("list q data: %d\n", data);
    }

    for(int i = 1; i <= 5; ++i)
    {
        data = list_pop();
        if(-1 != data)
            printf("list stk data: %d\n", data);
    }

    return 0;
}
