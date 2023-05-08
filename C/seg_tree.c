#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

long getsumQuery(long *segt, int curr, int currs, int curre, int querystartIdx, int queryendIdx)

{
	if(currs >= querystartIdx && curre <= queryendIdx)
		return segt[curr];
	if(currs > queryendIdx || curre < querystartIdx)
		return 0;
	int mid = currs + (curre-currs)/2;
	return (getsumQuery(segt, 2*curr+1, currs, mid, querystartIdx, queryendIdx) +
			getsumQuery(segt, 2*curr+2, mid+1, curre, querystartIdx, queryendIdx));
}


void updateValQuery(long * segt, int curr, int currs, int curre, int updIdx, long diff)

{
	if(currs > updIdx || curre < updIdx)	return;
	
	segt[curr] += diff;
	if(currs != curre){
		int mid = currs + (curre-currs)/2;
		updateValQuery(segt, 2*curr+1, currs, mid, updIdx, diff);
		updateValQuery(segt, 2*curr+2, mid+1, curre, updIdx, diff);
	}	
}



long buildSegTreeUtil(long * array, long * segt, int curr, int currs, int curre)
{
	if(currs == curre){
		segt[curr] = array[currs];
		return segt[curr];
	}
	int mid = currs + (curre-currs)/2;
	segt[curr] = buildSegTreeUtil(array, segt, 2*curr+1, currs, mid) +
				 buildSegTreeUtil(array, segt, 2*curr+2, mid+1, curre);
	return segt[curr];
}

long * buildSegTree(long * array, int n)

{
	/*let's find out height of the tree
		and use it for allocation to a complete, balanced tree*/
	int height = log2(n+1);
	int num = 2*pow(2, height) - 1;
	long * segt = (long *)calloc(num, sizeof(long));
	assert(segt);
	buildSegTreeUtil(array, segt, 0, 0, n-1);
	return segt;
}


int getopt()
{
    while(1){
	int opt;
	printf("1 to perform sum query, 2 to perform update query, 3 to exit\n");
	scanf("%d", &opt);
	if(opt == 1 || opt == 2)
	    return opt;
	else if(opt == 3)
	    exit(0);
	else
	    printf("Invalid option...");
    }
}

int main()

{

    long *array, updVal, res; 
    //sample array input: {1, 100, 3, 5, 103, 99, 53}
    int n, opt, querystartIdx, queryendIdx, updIdx;

    printf("array size ? \n");
    scanf("%d", &n);
    array = (long *)calloc(n, sizeof(long));
    assert(array);
    for(int i = 0; i < n; ++i)
    {
	printf("element#%d?\n", i+1);
	scanf("%ld", (array+i));
    }

    long *segt = buildSegTree(array,n);
    while(1){
	opt = getopt();
	if(opt == 1){
	    printf("Enter query start Index\n");
	    scanf("%d", &querystartIdx);
	    printf("Enter query end Index\n");
		scanf("%d", &queryendIdx); 

        while(querystartIdx < 0 || queryendIdx >= n || querystartIdx > queryendIdx)
	    {
			printf("Enter sum range in %d to %d\n", 0, n-1);
        	printf("Enter query start Index\n");
        	scanf("%d", &querystartIdx);
        	printf("Enter query end Index\n");
        	scanf("%d", &queryendIdx);  
	    }
	    res = getsumQuery(segt, 0, 0, n-1, querystartIdx, queryendIdx);
	    printf("sum for range %d to %d is %ld\n", querystartIdx, queryendIdx, res);
	}
	else{
		printf("Enter Index for which value to be updated\n");
	    scanf("%d", &updIdx);
		printf("Enter value to update\n");
		scanf("%ld", &updVal);
	    while(updIdx < 0 || updIdx > n-1)
	    {
	        printf("Enter update Index in range %d to %d\n", 0, n-1);
        	printf("Enter Index for which value to be updated\n");
        	scanf("%d", &updIdx);
        	printf("Enter value to update\n");
        	scanf("%ld", &updVal);
	    }
	    long diff = updVal - array[updIdx];
	    array[updIdx] = updVal;

	    updateValQuery(segt, 0, 0, n-1, updIdx, diff);
	}
    }
	
	free(segt);
	free(array);
    return 0;

}
