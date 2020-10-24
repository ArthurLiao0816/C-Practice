#include <stdio.h>

int main(){
    int m, n, i, j, k, stu[50000], timer, rlt[100], idx = -1;
    for(k = 0; k < 100; k++){
        rlt[k] = 0;
    }
    while(1){
        idx += 1;
        timer = 0;
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        for(k = 1; k <= n; k++){
            stu[k] = 0;
        }
        for(k = 0; k < m; k++){
            scanf("%d %d", &i, &j);
            if(stu[i] == 0 && stu[j] == 0){
                timer += 1;
                stu[i] = timer;
                stu[j] = timer;
            }
            else if(stu[i] != 0 && stu[j] == 0){
                stu[j] = stu[i];
            }
            else if(stu[j] != 0 && stu[i] == 0){
                stu[i] = stu[j];
            }
            else stu[i] += 0;
        }
        rlt[idx] = timer;
        for(k = 1; k <= n; k++){
            if(stu[k] == 0) rlt[idx] += 1;
        }
    }
    for(k = 0; k < idx; k++){
        printf("Case %d: %d\n", k+1, rlt[k]);
    }
    return 0;
}