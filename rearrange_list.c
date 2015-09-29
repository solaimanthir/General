#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
Example: 
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3 

Input:  1 -> 2 -> 3
Output: 1 -> 3 -> 2 
*/
typedef struct node node;

struct node {
    int data;
    node * next;
};

node * add_new_node(node * head, int data)
{
    node * temp = malloc(sizeof (node));
    if(!temp)   return NULL;
    temp->data = data;
    temp->next = head;
    return temp;
}
void print_list(node * head)
{
    node * temp = head;
    while(temp){
        printf("%d", temp->data);
        if(temp->next)  printf("-->");
        temp = temp->next;
    }
    printf("\n");
}
void rearrange_list(node * head)
{
    node * curr = head, * next;
    if(!head)
        return;
    if(head && !head->next)
        return;
    if(head && head->next && !head->next->next)
        return;
    while(curr){
        node * last = curr, * prev = NULL;
        while(last && last->next){
            prev = last;
            last = last->next;
        }
        if((curr == last) || (curr->next == last))
            return;
        prev->next = NULL;
        next = curr->next;
        curr->next = last;
        last->next = next;
        curr = next;
    }
}
int main()
{
   node * head = NULL;
   while(1) {
       int opt;
       printf("Enter data to add into list node, 0 to exit\n");
       scanf("%d", &opt);
       switch(opt) {
           case 0:
           break;
           default:
           head = add_new_node(head, opt);
           break;
        }
       if(!opt)
           break;
   }
   print_list(head);
   rearrange_list(head);
   print_list(head);
   return 0;
}
