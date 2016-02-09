#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subset_res {
    int *arrayPtr;
    int num;
    int xor;
    struct current_request {
       int *max_index;
    }curr_req;

}ss_result;

void gen_max_subset_xor(int *array, int n, int N, ss_result *resPtr, int st_idx);

int main()
{
    int array[] = {1, 2, 3, 4, 5};
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
        memset(res.curr_req.max_index, 0 , sizeof(int)*i);
        for(j = (N-1), k = (i-1); (j >= 0) && (k >= 0); --j, --k)
        {
            res.curr_req.max_index[k] = j;
        }
        gen_max_subset_xor(array, i, N, &res, 0);
        free(res.curr_req.max_index);
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

void gen_max_subset_xor(int *array, int n, int N, ss_result *resPtr, int st_idx)
{
    int subset[n];
    int curr_index[n];
    int i, p, xor = 0, count = 0;
    
    if(resPtr == NULL)
        exit(-1);

    memset(subset, 0, sizeof(subset));
    memcpy(curr_index, subset, sizeof(subset));
    for(i = st_idx, p = 0; (i < N) && (p < n); ++i, ++p)
    {
        subset[p] = array[i];
        curr_index[p] = i;
        ++count;
    }

    if(count < n)
      return;

    for(i = 0; i < n; ++i)
    {
        xor ^= subset[i];
        printf("%d ", subset[i]);
    }
    printf("\n");

    if(resPtr->xor < xor)
    {
        memcpy((char *)resPtr->arrayPtr, (char *)subset, (sizeof(int)*n));
        resPtr->xor = xor;
        resPtr->num = n;
    }

    for(i = (n-1); i > 0; --i)
    {
        while(curr_index[i] < resPtr->curr_req.max_index[i])
        {
            int j;
            subset[i] = array[++curr_index[i]];
            xor = 0;
            for(j = 0; j < n; ++j)
            {
                xor ^= subset[j];
                printf("%d ", subset[j]);
            }
            printf("\n");
            if(resPtr->xor < xor)
            {
                memcpy((char *)resPtr->arrayPtr, (char *)subset, (sizeof(int)*n));
                resPtr->xor = xor;
                resPtr->num = n;
            }
        }
    }

    if((i == 0) && (curr_index[0] < resPtr->curr_req.max_index[0]))
        gen_max_subset_xor(array, n, N, resPtr, curr_index[0]+1);
}
