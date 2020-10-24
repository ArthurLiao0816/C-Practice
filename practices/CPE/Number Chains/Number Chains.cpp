#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxinput 5000
#define maxlength 10

int idx = 0;
int d_order(char *input);
int a_order(char *input);
int int_ize(char *input);
void process(char *input);
bool isRepeated(int number, int i, int *ans);

int main(){
    char input[maxlength];
    int can[maxinput];
    int i, j;

    //讀 & 存取數字
    for(i = 0; i < maxinput; i++){
        gets(input);
        //puts(input);

        can[i] = int_ize(input);
        //printf("can[%d] = %d\n", i, can[i]);

        /*if(isRepeated(can[i], i, can)){
            printf("isRepeated? -> true\n");
        }
        else printf("isRepeated? -> false\n");*/

        //printf("input = %s, strlen(input) = %d\n", input, strlen(input));

        if(can[i] == 0){
            break;
        }
    }

    //處理數字
    for(i = 0;; i++){
        if(can[i] == 0){
            break;
        }
        process(itoa(can[i], input, maxlength));
    }

    //印出結果
    /*for(i = 0; i < idx; i++){
        printf("result[%d] = %d\n", i, result[i]);
    }*/

    return 0;
}

//由大到小排序
int d_order(char *input){
    int nums[10];
    int i;

    for(i = 0; i < strlen(input); i++){
        nums[i] = (int)(input[i]-'0');
        //printf("%d\n", nums[i]);
    }

    for(i = 0; i < strlen(input); i++){
        for(int j = i; j < strlen(input); j++){
            if(nums[i] < nums[j]){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }

    for(i = 0;i < strlen(input); i++){
        //printf("%d", nums[i]);
        input[i] = nums[i] + '0';
    }
    //printf("\n");
    return atoi(input);
}

//由小到大排序
int a_order(char *input){
    int nums[10];
    int i;

    for(i = 0; i < strlen(input); i++){
        nums[i] = (int)(input[i]-'0');
        //printf("%d\n", nums[i]);
    }

    for(i = 0; i < strlen(input); i++){
        for(int j = i; j < strlen(input); j++){
            if(nums[i] > nums[j]){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }

    for(i = 0;i < strlen(input); i++){
        //printf("%d", nums[i]);
        input[i] = nums[i] + '0';
    }
    //printf("\n");
    return atoi(input);
}

//字串轉數字
int int_ize(char *input){
    return atoi(input);
}

//處理資料
void process(char *input){
    int ans[maxinput];
    printf("Original number was %s\n", input);

    for(int i = 0;; i++){
        ans[i] = d_order(input) - a_order(input);
        printf("%d - %d = %d\n", d_order(input), a_order(input), ans[i]);
        if(isRepeated(ans[i], i, ans)){
            printf("Chain length %d\n", i+1);
            break;
        }
        /*for(int j = 0; j < 5; j++){
            printf("ans[%d] = %d\n", j, ans[j]);
        }*/
        itoa(ans[i], input, maxlength);
    }
}

bool isRepeated(int number, int i, int *ans){
    for(int j = 0; j < i; j++){
        if(number == ans[j]){
            //printf("isRepeated? -> true\n");
            return true;
        }
    }
    return false;
}