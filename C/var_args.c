//Author Solai
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) 
{
    va_list args;
    int tot = 0;
    
    va_start(args, count); //init args with count
    
    for(int i = 0; i < count; ++i)
    {
        tot = tot + va_arg(args, int);
    }
    
    va_end(args); //cleanup args
    
    return tot;
}

int main() {
    int ans1 = sum(5, 10, 10, 10, 10, 10); // s1 = 50
    int ans2 = sum(3, 10, 10, 10); // s2 = 30
    
    printf("ans1 = %d\n", ans1);
    printf("ans2 = %d\n", ans2);
    
    return 0;
}
