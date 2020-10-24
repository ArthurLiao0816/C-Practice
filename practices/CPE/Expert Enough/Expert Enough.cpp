#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    //the number of test cases follow
    int t;
    scanf("%d", &t);
    //printf("I'm 't'.\n");

    while(t--){
        int d, l[10000], h[10000], q, p[1000];
        char m[10000][21];
        scanf("%d", &d);
        //printf("I'm 'd'.\n");

        for(int i = 0; i < d; i++){
            scanf("%s %d %d", m[i], &l[i], &h[i]);
        }

        scanf("%d", &q);
        //printf("I'm 'q'.\n");

        for(int i = 0; i < q; i++){
            scanf("%d", &p[i]);
        }

        int counter = 0;

        for(int i = 0; i < q; i++){
            for(int j = 0; j < d; j++){
                ++counter;
                if((l[j] <= p[i]) && (p[i] <= h[j])){
                    printf("%s\n", m[j]);
                    counter = 0;
                    break;
                }
                if (counter == d) printf("UNDETERMINED\n");
            }
        }
        printf("\n");
    }

    return 0;
}