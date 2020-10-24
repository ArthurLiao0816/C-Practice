#include <stdio.h>

bool possibleBipartition(int N, int** dislikes, int dislikesSize, int* dislikesColSize){
    if(dislikesSize == 0) return true;
    int label[N+1];
    for(int i = 1; i <= N; i++){
        label[i] = 0;
    }
    bool isChecked[dislikesSize];
    for(int i = 0; i < dislikesSize; i++){
        isChecked[i] = false;
    }
    int x = dislikes[0][0];
    int y = dislikes[0][1];
    label[x] = 1;
    label[y] = -1;
    isChecked[0] = true;
    
    while(true){
        bool isUpdated = false;
        for(int i = 1; i < dislikesSize; i++){
            //printf("%d label[3] = %d\n", i, label[3]);
            if(isChecked[i]) continue;
            x = dislikes[i][0];
            y = dislikes[i][1];
            //printf("%d %d\n", label[x], label[y]);
            if(label[x] == 0 && label[y] == 0){
                //printf("%d continue\n", i);
                continue;
            }
            else if(label[x] * label[y] == 1){
                //printf("i'm here\n");
                return false;
            }
            else if(label[x] != 0 && label[y] == 0){
                label[y] = -label[x];
                isChecked[i] = true;
                isUpdated = true;
                //printf("i'm here, label[y] = %d, y = %d\n", label[y], y);
            }
            else if(label[x] == 0 && label[y] != 0){
                label[x] = -label[y];
                isChecked[i] = true;
                isUpdated = true;
                //printf("i'm here\n");
            }
            else isChecked[i] = true;
        }
        bool isAllChecked = true;
        for(int i = 0; i < dislikesSize; i++){
            if(!isChecked[i]){
                isAllChecked = false;
                break;
            }
        }
        if(isAllChecked) break;
        if(isAllChecked) return true;
        if(!isUpdated && !isAllChecked){
            for(int i = 0; i < dislikesSize; i++){
                if(!isChecked[i]){
                    x = dislikes[i][0];
                    y = dislikes[i][1];
                    label[x] = 1;
                    label[y] = -1;
                    isChecked[i] = true;
                    break;
                }
            }
        }
    }
    
    return true;
}
// [[1,2],[3,4],[1,3],[1,4]]
//1 
//2 3 4