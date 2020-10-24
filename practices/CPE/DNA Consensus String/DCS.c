#include <stdio.h>

char* max(int point[4][1000], int n){
    int i, j, k, max[1000];
    static char rlt[1000];
    for(i = 0; i < n; i++){
        max[i] = 0;
    }
    for(k = 0; k < n; k++){
        for(i = 1; i < 4; i++){
            if(point[i][k] > point[max[k]][k]){
                max[k] = i;
            }
        }
    }
    for(i = 0; i < n; i++){
        if(max[i] == 0) rlt[i] = 'A';
        else if(max[i] == 1) rlt[i] = 'C';
        else if(max[i] == 2) rlt[i] = 'G';
        else rlt[i] = 'T';
    }

    return rlt;
}

int err(int point[4][1000], int n){
    int i, k, max[1000], ans = 0;
    for(i = 0; i < n; i++){
        max[i] = 0;
    }
    for(k = 0; k < n; k++){
        for(i = 1; i < 4; i++){
            if(point[i][k] > point[max[k]][k]){
                ans += point[max[k]][k];
                max[k] = i;
            }
            else ans += point[i][k];
        }
    }

    return ans;
}

int main(){
    int t, m, n;
    int i, j;
    char seq[50][1000];
    int point[4][1000]; //A, C, G, T
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &n);

        for(i = 0; i < 4; i++){ //initialize point array
            for(j = 0; j < n; j++){
                point[i][j] = 0;
            }
        }

        for(i = 0; i < m; i++){
            scanf("%s", &seq[i]);

            for(j = 0; j < n; j++){ //score
                if(seq[i][j] == 'A'){
                    point[0][j] += 1;
                }
                else if(seq[i][j] == 'C'){
                    point[1][j] += 1;
                }
                else if(seq[i][j] == 'G'){
                    point[2][j] += 1;
                }
                else{
                    point[3][j] += 1;
                }
            }
        }
        char *rlt = max(point, n);
        printf("\n");
        puts(rlt);
        printf("%d\n\n", err(point, n));
    }    

    return 0;
}