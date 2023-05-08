#include<stdlib.h>
#include<stdio.h>

struct tree_node {
   int val;
   struct tree_node * right, * left;
};

typedef struct tree_node node;

typedef struct close_leaf {
   node * leaf;
   int min;   
}cleaf;

void insert(node ** tree, node * item) {
   if((*tree) == NULL) {
      *tree = item;
      return;
   }
   if(item->val<(*tree)->val)
      insert(&(*tree)->left, item);
   else if(item->val>(*tree)->val)
      insert(&(*tree)->right, item);
}

void printout(node * tree) {
   if(tree->left) printout(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) printout(tree->right);
}

void free_nodes(node *tree)
{
   if((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
      free(tree);
   else 
   {
      free_nodes(tree->left);
      free_nodes(tree->right);
   }
}

int get_dist_from_root(node * root, node *x)
{
    node * temp;
    int dist = 0;

    if((root == NULL) || (x == NULL))
        return dist;

    for(temp = root; temp != NULL;)
    {
        if(temp == x)
            break;
        else if(temp->val < x->val)
            temp = temp->right;
        else
            temp = temp->left;
        ++dist;
    }

    return dist;
}

void rec_and_find_close_leaf(node *x, int min, cleaf *leaf_node)
{
    if((x == NULL) || (leaf_node == NULL))
        return;
    if((x->left == NULL) && (x->right == NULL))
    {
        if((leaf_node->leaf == NULL) || (leaf_node->min > min))
        {
            leaf_node->leaf = x;
            leaf_node->min = min;
        }
    }

    rec_and_find_close_leaf(x->left, min+1, leaf_node);
    rec_and_find_close_leaf(x->right, min+1, leaf_node);
}

cleaf * rec_and_find_close_leaf_wrap(node *x)
{
   cleaf * leaf_node = NULL;

   if(x == NULL)
       return NULL;
   leaf_node = (cleaf *)malloc(sizeof(cleaf));
   if(leaf_node == NULL)
       return leaf_node;
   leaf_node->leaf = NULL;
   leaf_node->min = 0;
   rec_and_find_close_leaf(x, 0, leaf_node);

   return leaf_node;
}

cleaf * find_close_leaf_node(node *root, node *x)
{
    cleaf * leaf = NULL;
    node * curr_parent = root;
    int dist_from_root = 0;
    if((root == NULL) || (x == NULL))
        return leaf;

    leaf = rec_and_find_close_leaf_wrap(x);
    dist_from_root = get_dist_from_root(root, x);
    if(leaf == NULL)
        return leaf;

    for(; dist_from_root >= 1; --dist_from_root)
    {
        printf("curr_parent->val: %d\n", curr_parent->val);
        if(x->val > curr_parent->val)
        {
            rec_and_find_close_leaf(curr_parent->left, dist_from_root+1, leaf);
            curr_parent = curr_parent->right;
        }
        if(x->val < curr_parent->val)
        {
            rec_and_find_close_leaf(curr_parent->right, dist_from_root+1, leaf);
            curr_parent = curr_parent->left;
        }
    }
    return leaf;
}

int main() {
   node * curr, * root, *x;
   int i;
   cleaf * close_leafNode = NULL;
   int arr[] = {100, /*55, 10, 9, 45, 48, 7, 6, 8,*/ 101, 55, 40, 45, /*46, 47, 48, */56};
   int min = 0;

   root = NULL;

   for(i=0;i < 6;i++) {
      curr = (node *)malloc(sizeof(node));
      curr->left = curr->right = NULL;
      curr->val = arr[i];
      insert(&root, curr);
   }

   printout(root);
   x = root->left->left;
   close_leafNode = find_close_leaf_node(root, x);
   if(close_leafNode && close_leafNode->leaf)
       printf("closest leaf to %d is %d at distance %d\n", x->val, close_leafNode->leaf->val, close_leafNode->min);
   free(close_leafNode);
   free_nodes(root);
   return 0;
}
