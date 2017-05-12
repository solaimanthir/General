#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ULL unsigned long long
#define FORI(cap) for(int i = 0; i < cap; ++i)
#define FORD(cap) for(int i = cap-1; i >= 0; --i)

void merge(int arr[], int L, int mid, int R)
{
    int i, j, n1 = (mid-L+1), n2 = (R-mid);
    int Larr[n1], Rarr[n2];
    FORI(n1)
        Larr[i] = arr[L+i];
    FORI(n2)
        Rarr[i] = arr[mid+1+i];
    int k = L;
    i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(Larr[i] <= Rarr[j])
        {
            arr[k] = Larr[i];
            ++i;
        }
        else{
            arr[k] = Rarr[j];
            ++j;
        }
        ++k;
    }
    while(i < n1){
        arr[k++] = Larr[i++];
    }
    while(j < n2){
        arr[k++] = Rarr[j++];
    }
}

void mergeSort(int arr[], int L, int R)
{
    if(L < R){
        int mid = L+((R-L)>>1);
        mergeSort(arr, L, mid);
        mergeSort(arr, mid+1, R);
        merge(arr, L, mid, R);
    }
}

ULL getCount(ULL segt[], int curr, int currst, int currend, int queryst, int queryend)
{
	if((queryst > currend) || (queryend < currst))	return 0;
	if(currst >= queryst && currend <= queryend) 
	{
		return segt[curr];
	}
	int mid = currst + (currend-currst)/2;
	return (getCount(segt, 2*curr+1, currst, mid, queryst, queryend) + 
		getCount(segt, 2*curr+2, mid+1, currend, queryst, queryend));
}

void updateSegt(ULL segt[], int curr, int currst, int currend, int updIdx)
{
	if(currst > updIdx || currend < updIdx)	return;
	segt[curr] += 1;
	if(currst != currend){
		int mid = currst + (currend-currst)/2;
		updateSegt(segt, 2*curr+1, currst, mid, updIdx);
		updateSegt(segt, 2*curr+2, mid+1, currend, updIdx);
	}
}

void fetch_invcnt(int arrw[], int n, ULL *cnt)
{
	int arrb[n], arrbb[n], l, r, m, *ptr = NULL, sz;
	ULL segt[4*n+1];
	FORI(n){
		arrb[i] = arrw[i];
		arrbb[i] = arrb[i];
	}
	mergeSort(arrb, 0, n-1);
	FORI(n) {
		l = 0;
		r = n-1;
		while(l <= r){
			m = l + (r-l)/2;
			if(arrb[m] > arrbb[i])
				r = m-1;
			else if(arrb[m] < arrbb[i])
				l = m+1;
			else{
				ptr = &arrb[m];
				break;
			}
		}
		arrw[i] = &arrb[m] - &arrb[0];
	}
	/*segment tree*/
	memset(segt, 0, sizeof(segt));
	FORD(n){
		if(i != n-1){
			if(0 <= arrw[i]-1 && arrw[i]-1 <= n-1)
				*cnt += getCount(segt, 0, 0, n-1, 0, arrw[i]-1);
		}
		if(0 == i) break;
		if(arrw[i] >= 0 && arrw[i] <= n-1)
			updateSegt(segt, 0, 0, n-1, arrw[i]);
	}
}
int main()
{
	int t, n, i;
    ULL cnt;
    scanf("%d", &t);
    while(t--){
    	scanf("%d", &n);
        int arr[n];
        for(i = 0; i < n; ++i){
        	scanf("%d", &arr[i]);
        }
        cnt = 0;
        fetch_invcnt(arr, n, &cnt);
        printf("%llu\n", cnt);
    }
  	return 0;
}

