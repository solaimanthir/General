#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

bool isSparse(unsigned int x)
{
    unsigned int one = 1;
    int i;
#define SZ_OF_BYTE 8
#define MAX (sizeof(unsigned int)*SZ_OF_BYTE)
    for(i = 1; i < MAX; ++i){
      if((x & (one<<i)) && (x & (one<<(i-1))))
          return false;
    }
    return true;
}
int main()
{
    unsigned int x = 3;
    
    while(1){
        if(x == UINT_MAX)
            break;
        if(isSparse(x)){
            printf("%u is sparse\n", x);
            break;
        }
        else
            ++x;
    }

    return 0;
}
