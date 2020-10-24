#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Sample Input
4 50 2 10 1 20 2 30 1
7 20 1 2 1 10 3 100 2 8 2 5 20 50 10

Sample Output
80
185
*/

int main(){
    int n;
    //printf("I havn't entered.\n");
    while(scanf("%d", &n)!= EOF){
        //printf("I've entered thw while loop.\n");
        int p[10000] = {0}, d[10000] = {0}, t[10000] = {1}, map[10000] = {0}, mp[10000] = {0};
        long int ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &p[i], &d[i]);
        }

        //debug block
        /*printf("%d ", n);
        for(int i = 0; i < n; i ++) printf("%d %d ", p[i], d[i]);
        printf("\n");*/

        //record map
        //printf("I've been recording map.\n");
        for(int i = 0; i < n; i++){
            if(p[i] > mp[d[i]]){
                mp[d[i]] = p[i];
                map[i] = 1;
                t[d[i]] = 1;
            }
            else if (p[i] == mp[d[i]]){
                t[d[i]] += 1;
            }
            else continue;
        }

        //debug block
        /*printf("before_MAP:\n");
        for(int i = 0; i < n; i++)
            printf("%d ", map[i]);
        printf("\n");*/


        //process map
        //printf("I've been processing map.\n");
        for(int i = n-1; i > 0; i--){
            for (int j = i-1; j >= 0; j--){
                if(d[i] == d[j] && map[i] == 1) map[j] = 0;
            }
        }

        //debug block
        /*printf("after_MAP:\n");
        for(int i = 0; i < n; i++)
            printf("%d ", map[i]);
        printf("\n");*/

        //ans
        //printf("I've been dealing with ans.\n");
        for(int i = 0; i < n; i++){
            if(map[i] != 0){
                ans += mp[d[i]]*t[map[d[i]]];
                //printf("I add %d.\n", mp[d[i]]*t[map[d[i]]]);
            }
        }
        printf("%ld\n", ans);
    }
    
    return 0;
}
