#include <stdio.h>
#include <stdlib.h>

int main(){
    int* numbers = 0;   //將指標的值預設為'0'代表這個指標是'空指標'
    int len = 0;
    while(1){
        int ipt;
        scanf("%d", &ipt);
        if(ipt == -1) break;
        len += 1;
        int* largerArr = malloc(sizeof(int)*len);   //用新的指標指向新配置的記憶體
        for(int i = 0; i < len-1; i++) largerArr[i] = numbers[i];   //將numbers所指向的記憶體裡的資料複製到largerArr指標所指的記憶體中
        free(numbers);  //釋放numbers的記憶體(因為沒用了)
        numbers = largerArr;    //將numbers指向largerArr所指向的記憶體
        numbers[len-1] = ipt;
    }
    for(int i = 0; i < len; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}