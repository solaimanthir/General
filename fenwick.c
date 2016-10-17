#include <stdio.h>
#include <stdlib.h>

int getSum(int *BIT, int index)
{
	int sum = 0;
	index = index+1;

	while(index > 0)
	{
		sum += BIT[index];
		index = index - (index & -index);
	}
	return sum;
}

void updateBIT(int *BIT, int n, int ind, int val)
{
	ind = ind+1;
	while(ind <= n){
		BIT[ind] += val;
		ind += ind & (-ind);
	}
}

int * createBIT(int arr[], int n)
{
	int * BIT = (int *)malloc(sizeof(int)*(n+1));
	int i;
	for(i = 0;i <= n; ++i){
		BIT[i] = 0;	
	}

	for(i = 0; i < n; ++i){
		updateBIT(BIT, n, i, arr[i]);
	}
	return BIT;
}
int main()
{
	int arr[] = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int *BIT = createBIT(arr, n);
	int l, r;
	scanf("%d %d", &l, &r);
	if(l >= 0 && l < n && r >= 0 && r < n)
		printf("sum of range [%d, %d] is %d\n", l, r, (getSum(BIT, r)-getSum(BIT, l-1)));
	else return -1;
	arr[3] += 10;
	updateBIT(BIT, n, 3, 10);
	printf("sum of range [%d, %d] is %d\n", l, r, (getSum(BIT, r)-getSum(BIT, l-1)));
	return 0;
}
