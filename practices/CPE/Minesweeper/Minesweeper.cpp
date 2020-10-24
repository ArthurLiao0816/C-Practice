#include <stdio.h>


int main(){
    int n = 0, m = 0;
    int i, j;
    int counter = 0;
    char map[100][100];
    char rltmap[100][100] = {0};
    while(1){
        scanf("%d %d", &n, &m);
        if(n != 0 && m != 0){
            for(i = 0; i < n; i++){
                for(j = 0; j < m; j++){
                    rltmap[i][j] = '0';
                }
            }
            counter += 1;
            for(i = 0; i < n; i++){
                scanf("%s", &map[i]);
                for(j = 0; j < m; j++){
                    if(map[i][j] == '*'){
                        rltmap[i][j] = '*';
                        if(i-1 >= 0 && i-1 < n && j-1 >= 0 && j-1 < m && rltmap[i-1][j-1] != '*')
                            rltmap[i-1][j-1] += 1;
                        if(i-1 >= 0 && i-1 < n && j+1 >= 0 && j+1 < m && rltmap[i-1][j+1] != '*')
                            rltmap[i-1][j+1] += 1;
                        if(i-1 >= 0 && i-1 < n && rltmap[i-1][j] != '*')
                            rltmap[i-1][j] += 1;
                        if(i+1 >= 0 && i+1 < n && j-1 >= 0 && j-1 < m && rltmap[i+1][j-1] != '*')
                            rltmap[i+1][j-1] += 1;
                        if(i+1 >= 0 && i+1 < n && j+1 >= 0 && j+1 < m && rltmap[i+1][j+1] != '*')
                            rltmap[i+1][j+1] += 1;
                        if(i+1 >= 0 && i+1 < n && rltmap[i+1][j] != '*')
                            rltmap[i+1][j] += 1;
                        if(j-1 >= 0 && j-1 < m && rltmap[i][j-1] != '*')
                            rltmap[i][j-1] += 1;
                        if(j+1 >= 0 && j-1 < m && rltmap[i][j+1] != '*')
                            rltmap[i][j+1] += 1;
                    }
                }
            }
            printf("Field #%d:\n", counter);
            for(i = 0; i < n; i++){
                printf("%s\n", rltmap[i]);
            }
        }
        else break;
    }
    
    return 0;
}