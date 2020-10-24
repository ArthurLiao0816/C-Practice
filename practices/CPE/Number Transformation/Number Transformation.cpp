#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Sample Input
6 12
6 13
0 0

Sample Output
Case 1: 2
Case 2: -1
*/

int case_idx = 0, f_idx = 0;
int map[64][64] = {{0}};
int get_factor(int *f, int s);

int main(){
    int s, t;

    while(scanf("%d %d", &s, &t) && s&&t){
        //printf("s = %d, t = %d\n", s, t);
        int ans = -1, f[64] = {0};

        case_idx += 1;
        f_idx = 0;

        *f = get_factor(f, s);
        
        printf("f_idx = %d\n", f_idx);
        for(int i = 0; i < f_idx; i++){
            printf("f[f_idx] = %d\n", f[i]);
        }

        //to see if s could transform to t
        //6 13
        //6 (2) -> 9 (3) -> 12 (X)
        //  (3) -> 8 (2) -> 11 (X)
        //           (4) -> 10 (2) -> 12 (X)
        //                     (5) -> 15 (X)
        //root node

        printf("Case %d: %d\n", case_idx, ans);
    }
    
    return 0;
}

int get_factor(int *f, int s){
    f_idx = 0;

    for(int i = 2; i <= s - 1; i++){
        if(s%i == 0) {
            //printf("f_idx = %d, i = %d\n", f_idx, i);
            f[f_idx] = i;
            f_idx += 1;
        }
    }

    return *f;
}
