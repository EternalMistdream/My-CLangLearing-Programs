#include<stdio.h>

#define limit 20



void cal(int i, long long int num[]) {
    num[i + 2] = num[i] + num[i + 1];
    i++;
    if (i + 2 >= limit)
    {
        return;
    }
    cal(i,num);
    
                                        
}
                                                          
int main(){
    long long int N[limit] = { 0,1 };
    cal(0,N);
    for (int i = 0; i < limit; i++)
    {
        printf("%lld\n", N[i]);
    }
    return 0;
}