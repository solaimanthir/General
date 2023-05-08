typedef struct trnd trnd;
typedef struct snd snd;

struct trnd
{
   int data;
   trnd * left;
   trnd * right;
};

struct snd
{
  trnd *tnode;
  snd *next;
};

void inOrder(trnd *root)
{
    trnd *curr = root;
    snd *stk = NULL;

    while(1){
        if(curr){
            push(&stk, curr);
            curr = curr->left;
        }
        else{
            if(isEmpty(stk))
                break;
            else{
                curr = pop(&stk);
                printf(" %d ", curr->data);
                curr = curr->right;
            }
        }
    }
}

void push(snd ** topptr, trnd *t)
{
    snd * tmp = (snd *)calloc(1, sizeof(snd));
    tmp->tnode = t;
    tmp->next = (*topptr);
    (*topptr) = tmp;
}

bool isEmpty(snd *top)
{
    if(NULL == top)
        return true;
    return false;
}

trnd *pop(snd ** topptr)
{
    if(!topptr || isEmpty(*topptr))
        return NULL;
    snd *stmp = (*topptr);
    trnd *ttmp = stmp->t;
    (*topptr) = stmp->next;
    free(stmp);
    return ttmp;
}

int main()
{
  /* construct tree */
  inOrder(root);
  return 0;
}
