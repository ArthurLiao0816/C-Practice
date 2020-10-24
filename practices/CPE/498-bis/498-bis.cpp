#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    long long int x_value, input[100], output[100] = {0}, process[100] = {0}, Idx = 0, Idx_opt = -1, i, j;


    while (scanf("%lld", &x_value) != EOF) {
        //cout << "x_value = " << x_value << '\n' << endl;    //debug
        Idx_opt += 1;

        while(cin >> input[Idx++]){
            char ch = getchar();
            if(ch == '\n') break;
        }

        for(i = 0; i < (Idx - 1); i++){
            process[i] += input[i]*(Idx - 1 - i);  //a_0*n+...+a_(n-1)*1
            for(j = (Idx - 2 - i) ;j > 0; j--) {
                    process[i] *= x_value;
            }
            //cout << "process[" << i << "] = " << process[i] << '\n' << endl;
            output[Idx_opt] += process[i];
        }
        cout << output[Idx_opt] << endl;

        //debug
        /*for(i = 0;i < Idx;i++){
            if(input[i] != '\0'){
                cout << "input[" << i << ']' << input[i] << '\n' << endl;
            }
        }*/

        //For initializing input
        for(i = 0;i < Idx;i++){
            input[i] = 0;
            process[i] = 0;
        }
        Idx = 0;
    }
    /*cout << "I'm here." <<endl;
    for(i = 0;i < Idx_opt; i++){
        cout << output[i] << '\n' << endl;
    }*/

    return 0;
}
