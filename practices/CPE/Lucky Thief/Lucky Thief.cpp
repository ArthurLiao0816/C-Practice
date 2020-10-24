#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    long int t;
    long long int n[100000], m[100000];
    scanf("%ld", &t);
    for(long int i = 0; i < t; i++){
        scanf("%lld %lld", &n[i], &m[i]);
    }

    for(long int i = 0; i < t; i++){
        printf("%lld\n", n[i]*(2*m[i]-n[i]-1)/2);
    }

    return 0;
}