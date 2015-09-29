#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
void reverse_list(node ** head)
{
    node * prev = NULL, *next, * curr = *head;
    while(curr){
        prev = curr;
        next = curr->next;
        curr->next = prev;
        curr = next;
    }
    *head = prev;
}
void rearrange_list(node * head)
{
    node * slow = head, fast;
    node * head1, *head2;
    if(!head)
        return;
    fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    head1 = head;
    head2 = slow->next;
    reverse_list(&head2);
    while(head1 || head2){
        node * curr;
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
