#include <stdio.h>

bool possibleBipartition(int N, int** dislikes, int dislikesSize, int* dislikesColSize){
    if (dislikesSize == 0) return true;
    
    bool isChecked[dislikesSize];
    for (int i = 0; i < dislikesSize; i++) {
        isChecked[i] = false;
    }
    
    int label[N+1];    // label[i] 表示第 i 個人所在的隊伍 (group: -1, 1)
    for (int i = 1; i <= N; i++) {
        label[i] = 0;  // label[i] 為 0 表示第 i 個人還沒有指定隊伍
    }    
    
    
    // N:         4
    // dislikes: [[1, 2], [3, 4], [1, 3]]
    
    // label:  [X, 0, 0, 0, 0]
    int x = dislikes[0][0];
    int y = dislikes[0][1];
    label[x] = -1;
    label[y] = 1;
    isChecked[0] = true;

    while (true) 
    {
        bool isUpdated = false;
        for (int i = 1; i < dislikesSize; i++) {
            if (isChecked[i] == true) continue;

            // dislikes[i]: [x, y]  代表第 x 個人不能跟第 y 個人在同一隊
            x = dislikes[i][0];
            y = dislikes[i][1];

            if (label[x] == 0 && label[y] == 0) {  // 代表第 x 個人跟第 y 個人還沒分隊
                continue;
            } else if (label[x] != 0 && label[y] != 0) {  // 代表第 x 個人跟第 y 個人已經分隊
                if (label[x] == label[y]) {
                    return false;
                } else {
                    isChecked[i] = true;
                }
            } else if (label[x] != 0 && label[y] == 0) {  // 代表只有第 x 個人已經分隊
                label[y] = -label[x];            
                isChecked[i] = true;
                isUpdated = true;
            } else if (label[x] == 0 && label[y] != 0) {  // 代表只有第 y 個人已經分隊
                label[x] = -label[y];            
                isChecked[i] = true;
                isUpdated = true;
            }
        }   
        bool isAllChecked = true;
        for (int i = 1; i < dislikesSize; i++) {
            if (isChecked[i] == false) {
                isAllChecked = false;
                break;
            }
        }
        if (isAllChecked == true) return true;
        
        if (isUpdated == false && isAllChecked == false) {
            for (int i = 1; i < dislikesSize; i++) {
                if (isChecked[i] == false) {
                    x = dislikes[i][0];
                    y = dislikes[i][1];
                    label[x] = -1;
                    label[y] = 1;
                    isChecked[i] = true;
                    break;
                }
            }   
        }        
    }
    
    return false;    
}