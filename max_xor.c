#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subset_res {
    int *arrayPtr;
    int num;
    int xor;
    struct current_request {
       int *max_index;
       int *curr_index;
       int *subset;
    }curr_req;

}ss_result;

void gen_max_subset_xor(int *array, int n, int N, ss_result *resPtr, int a_idx, int ss_idx);

int main()
{
    int array[] = {1, 2, 3, 4, 7, 5, 6};
    int N = (sizeof(array)/sizeof(array[0]));
    int i, j, k;
    ss_result res = {0};
    if(N < 1)
        return 0;
    res.arrayPtr = (int *)malloc(sizeof(int)*N);
    if(res.arrayPtr == NULL)
        return 0;
    memset(res.arrayPtr, 0, (sizeof(int)*N));
    
    res.arrayPtr[0] = array[0];
    res.num = 1;
    res.xor = array[0];

    for(i = 1; i <= N; ++i) {
        res.curr_req.max_index = (int *)malloc(sizeof(int)*i);
        if(res.curr_req.max_index == NULL)
            return 0;
        res.curr_req.curr_index = (int *)malloc(sizeof(int)*i);
        if(res.curr_req.curr_index == NULL)
            return 0;
        res.curr_req.subset = (int *)malloc(sizeof(int)*i);
        if(res.curr_req.subset == NULL)
            return 0;
        memset(res.curr_req.max_index, 0 , sizeof(int)*i);
        memset(res.curr_req.curr_index, 0 , sizeof(int)*i);
        memset(res.curr_req.subset, 0 , sizeof(int)*i);
        for(j = (N-1), k = (i-1); (j >= 0) && (k >= 0); --j, --k)
        {
            res.curr_req.max_index[k] = j;
        }
        gen_max_subset_xor(array, i, N, &res, 0, 0);
        free(res.curr_req.max_index);
        free(res.curr_req.curr_index);
        free(res.curr_req.subset);
    }

    printf("subset with max xor %d is {", res.xor);
    for(i = 0; i < res.num; ++i)
    {
        if(i == (res.num-1))
            printf("%d}", res.arrayPtr[i]);
        else
            printf("%d, ",res.arrayPtr[i]);
    }
    printf("\n");
    free(res.arrayPtr);
    return 0;
}

void gen_max_subset_xor(int *array, int n, int N, ss_result *resPtr, int a_idx, int ss_idx)
{
    int i, p, xor = 0;
    
    if(resPtr == NULL)
        exit(-1);

    for(i = a_idx, p = ss_idx; (i < N) && (p < n); ++i, ++p)
    {
        resPtr->curr_req.subset[p] = array[i];
        resPtr->curr_req.curr_index[p] = i;
    }
    for(i = 0; i < n; ++i)
    {
        xor ^= resPtr->curr_req.subset[i];
        printf("%d ", resPtr->curr_req.subset[i]);
    }
    printf("\n");

    if(resPtr->xor < xor)
    {
        memcpy((char *)resPtr->arrayPtr, (char *)resPtr->curr_req.subset, (sizeof(int)*n));
        resPtr->xor = xor;
        resPtr->num = n;
    }

    while(resPtr->curr_req.curr_index[n-1] < resPtr->curr_req.max_index[n-1])
    {
        resPtr->curr_req.subset[n-1] = array[++(resPtr->curr_req.curr_index[n-1])];
        xor = 0;
        for(i = 0; i < n; ++i)
        {
            xor ^= resPtr->curr_req.subset[i];
            printf("%d ", resPtr->curr_req.subset[i]);
        }
        printf("\n");
        if(resPtr->xor < xor)
        {
            memcpy((char *)resPtr->arrayPtr, (char *)resPtr->curr_req.subset, (sizeof(int)*n));
            resPtr->xor = xor;
            resPtr->num = n;
        }
    }
    for(i = 0; i < n; ++i)
    {
        if(resPtr->curr_req.curr_index[i] < resPtr->curr_req.max_index[i])
        {
            continue;
        }
        else
            break;
    }
    if((i < n) && (i > 0))
    {
        gen_max_subset_xor(array, n, N, resPtr, ++(resPtr->curr_req.curr_index[i-1]), (i-1));
    }
}
