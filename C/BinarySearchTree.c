//Author: Solai

/*Note: Ensure tree nodes have unique key*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int key;
    node * left;
    node * right;
};

node * createnode(int key)
{
    node * newn = (node *)calloc(1, sizeof(node));
    if(NULL == newn)
    {
        printf("Line %d: calloc failed\n", __LINE__);
        return NULL;
    }

    newn->key = key;
    newn->left = NULL;
    newn->right = NULL;

    return newn;
}

node * insert(node * root, int key)
{
    if(NULL == root)
    {
        return createnode(key);
    }

    //insert key into leaf node's left or right;
    // and,or reassign non-leaf node's left or right with existing pointer.
    if(key < root->key)
    {
        root->left = insert(root->left, key);
    }

    else if(key > root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorder(node * root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(node * root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node * root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int heightBST(node * node)
{
    if(NULL == node)
    {
        return 0;
    }

    //calculate the height of each subtree
    int lh = heightBST(node->left);
    int rh = heightBST(node->right);

    if(lh > rh)
    {
        return lh + 1; //+1 for current level
    }
    
    return rh + 1;
}

void printlevel(node * node, int lev)
{
    if(NULL == node)
    {
        return;
    }

    /*we reached desired level*/
    if(1 == lev)
    {
        printf(" %d", node->key);
        return;
    }

    /*make recursive calls until we reach desired level
    on both subtrees*/
    if(lev > 1)
    {
        printlevel(node->left, lev - 1);
        printlevel(node->right, lev - 1);
    }
}

void levelorder(node * node)
{
    int height = heightBST(node);

    for(int i = 1; i <= height; ++i)
    {
        printf("\n");
        printlevel(node, i);
    }
}

void printleaf(node * node)
{
    if(NULL == node)
    {
        return;
    }

    if((NULL == node->left) &&
       (NULL == node->right))
    {
        printf(" %d",node->key);
        return;
    }

    printleaf(node->left);
    printleaf(node->right);
}

void printnonleaf(node * node)
{
    if(NULL == node)
    {
        return;
    }

    if((NULL != node->left) ||
       (NULL != node->right))
    {
        printf(" %d",node->key);
    }

    printnonleaf(node->left);
    printnonleaf(node->right);
}

int totnodesBST(node * node)
{
    if(NULL == node)
    {
        return 0;
    }

    int lc = totnodesBST(node->left);
    int rc = totnodesBST(node->right);

    //left+right+curr
    return lc+rc+1;
}

node * delNode(node * node, int key)
{
    if(NULL == node)
        return NULL;
    
    /*searching node is in right subtree?
    then, recurse and update right pointer accordingly*/
    if(key > node->key)
    {
        node->right = delNode(node->right, key);
        return node;
    }

    /*searching node is in left subtree?
    then, recurse and update left pointer accordingly*/
    if(key < node->key)
    {
        node->left = delNode(node->left, key);
        return node;
    }

    /*node's key is equal to search key.
     Handle with three cases:
     1. node with only one child
     2. node with no child
     3. node with two childs*/

    struct node * tmp = NULL;
    //case1&2
    if(NULL == node->right) //only left child(s) exist
    {
        tmp = node->left;
        free(node);
        return tmp;
    }
    if(NULL == node->left) //only right child(s) exist
    {
        tmp = node->right;
        free(node);
        return tmp;
    }

    /*case3: node with 2 children*/
    //fetch the inorder successor of the node
    tmp = node->right;
    while(tmp && (tmp->left != NULL))
    {
        tmp = tmp->left;
    }

    //tmp will never be NULL in case of node having two childs
    
    /*replace node's key with inorder successor 'tmp's key
    and free the tmp instead so that tree is kept intact*/
    node->key = tmp->key;
    //delete the tmp
    node->right = delNode(node->right, tmp->key);
    return node;
}

void deleteTree(node * node)
{
    if(NULL == node)
    {
        return;
    }

    //delete the child nodes first
    deleteTree(node->left);
    deleteTree(node->right);

    //all nodes in subtrees are deleted.
    //now, delete the current node
    printf(" %d", node->key);
    free(node);
}

int main()
{
    node * root = NULL;
    
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    printf("#####Inorder traversal#####\n");
    inorder(root);
    printf("\n###########################\n\n");

    printf("#####preorder traversal#####\n");
    preorder(root);
    printf("\n############################\n\n");

    printf("#####postorder traversal#####\n");
    postorder(root);
    printf("\n#############################\n\n");

    printf("#####levelorder traversal#####");
    levelorder(root);
    printf("\n#############################\n\n");

    printf("#####Print Leaf nodes#####\n");
    printleaf(root);
    printf("\n#########################\n\n");

    printf("#####Print non-leaf nodes#####\n");
    printnonleaf(root);
    printf("\n#########################\n\n");

    printf("#########################\n");
    printf("count: %d\n#########################\n", totnodesBST(root));

    printf("\n###Node(5) deletion###\n");
    delNode(root, 5); //delete node having key '5'
    printf("######################\n");

    printf("\n#####Inorder traversal after deleting node(5)#####\n");
    inorder(root);
    printf("\n##############################################\n\n");

    printf("#####Tree deletion#####\n");
    deleteTree(root);
    printf("\n###################\n");

    return 0;
}
