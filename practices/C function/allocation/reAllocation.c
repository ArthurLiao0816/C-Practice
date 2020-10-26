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
        numbers = realloc(numbers, sizeof(int)*(len));  //將指標numbers指向重新配置的記憶體
        numbers[len-1] = ipt;
    }
    for(int i = 0; i < len; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}