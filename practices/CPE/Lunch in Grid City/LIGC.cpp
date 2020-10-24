#include <stdio.h>
int main(){
    int t, s, a, f, idx = 0, i, avgS[50000], avgA[50000];
    float sumA, sumS, atmp, stmp;
    scanf("%d", &t);
    while(t--){
        sumA = 0, sumS = 0, atmp = 0, stmp = 0;
        scanf("%d %d %d", &s, &a, &f);
        for(i = 0; i < f; i++){
            scanf("%f %f", &stmp, &atmp);
            sumA += atmp;
            sumS += stmp;
            printf("sumA = %f", sumA);
            printf("sumS = %f\n", sumS);
        }
        avgA[idx] = (int)(sumA/f + 0.5);
        avgS[idx] = (int)(sumS/f + 0.5);
        idx += 1;
    }
    for(i = 0; i < idx; i++){
        printf("(Street: %d, Avenue: %d)\n", avgS[i], avgA[i]);
    }
    return 0;
}