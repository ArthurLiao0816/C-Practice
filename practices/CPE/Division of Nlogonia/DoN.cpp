#include <stdio.h>


int main(){
    int k = 0;
    int rlt[1000];
    int counter = 0;
    while(1){
        scanf("%d", &k);
        if(k != 0){
            int i, m, n, x, y;
            scanf("%d %d", &n, &m);
            for(i = 0; i < k; i++){
                scanf("%d %d", &x, &y);
                if(y == m || x == n){
                    rlt[counter+i] = 0;
                }
                else{
                    if(y > m && x > n){
                        rlt[counter+i] = 1;
                    }
                    if(y > m && x < n){
                        rlt[counter+i] = 2;
                    }
                    if(y < m && x > n){
                        rlt[counter+i] = 3;
                    }
                    if(y < m && x < n){
                        rlt[counter+i] = 4;
                    }
                }
            }
            counter += k;
        }
        else break;
    }
    int i;
    for(i = 0; i < counter; i++){
        if(rlt[i] == 0){
            printf("divisa\n");
        }
        else if (rlt[i] == 1){
            printf("NE\n");
        }
        else if (rlt[i] == 2){
            printf("N0\n");
        }
        else if (rlt[i] == 3){
            printf("SE\n");
        }
        else{
            printf("SO\n");
        }
    }
    return 0;
}