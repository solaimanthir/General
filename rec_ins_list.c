#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data;
    struct node * next;
}node, list;

void rec_ins(list ** head, int data, int pos, int position, node * prev)
{
    if(pos > position)
        return;
    else if(pos == position) {
        node * new_node = (node *)malloc(sizeof(node));
        if(new_node == (node *)NULL)
            return;
        new_node->data = data;
        if(prev) {
            new_node->next = prev->next;
            prev->next = new_node;
            printf("element %d inserted after %d\n", data, prev->data);
        }
        else {
            new_node->next = (node *)*head;
            *head = (list *)new_node;
            printf("element %d inserted\n", new_node->data);
        }
    }
    else {
        if((*head) != NULL)
            rec_ins(&(*head)->next, data, ++pos, position, (node *)*head);
    }
}
void rec_ins_wrap(list ** head, int data, int position)
{
    int pos = 1;
    rec_ins(head, data, pos, position, (node *)NULL);
}
void print_list(list * head)
{
   node * temp = (node *)head;
   while(temp != (node *)NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

 struct node * group_odd_even_nodes(struct node * head)
 {
     bool is_odd = true;
     struct node * oddGrp_list = NULL, * evenGrp_list = NULL, *traverse;
     struct node * odd_head, * even_head;
     
     if(head == NULL) {
         return NULL;
     }
     
     for(traverse = head; traverse != NULL; traverse = traverse->next)
     {
         if(is_odd) {
             if(oddGrp_list == NULL) {
                 oddGrp_list = traverse;
                 odd_head = traverse; 
             }
             else {
                 oddGrp_list->next = traverse;
                 oddGrp_list = traverse;
             }
         }
         else {
             if(evenGrp_list == NULL) {
                 evenGrp_list = traverse;
                 even_head = traverse;
             }
             else {
                 evenGrp_list->next = traverse;
                 evenGrp_list = traverse;
             }
         }
         is_odd = (!is_odd);
     }
     
     oddGrp_list->next = even_head;
     if(evenGrp_list)
        evenGrp_list->next = NULL;
     
     return odd_head;
 }
 
int main()
{
    list * head  = NULL;
    rec_ins_wrap(&head, 10, 1); /*TC1 : First element to list*/
    rec_ins_wrap(&head, 11, 1); /*TC2: Insert in Start*/
    rec_ins_wrap(&head, 12, 3); /*TC3: Insert in End*/
    rec_ins_wrap(&head, 13, 2); /*TC4: Insert 2nd pos from Start*/
    rec_ins_wrap(&head, 14, 4); /*TC5: Insert 2nd pos from End*/
    rec_ins_wrap(&head, 15, 3); /*TC6: Insert at random location->3*/
    rec_ins_wrap(&head, 16, 8); /*TC7: Negative test case: position 8 exceeds max insert position 7*/
    print_list(head);
    head = group_odd_even_nodes(head);
    print_list(head);
    return 0;
}
