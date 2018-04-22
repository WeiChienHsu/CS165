#include <iostream>

int sum(int *, int *, int *);

int sum(int *a, int *b, int *ans){

    *ans = *a + *b;

    return 0;
}

int main(){

    int num_1;
    int num_2;
    int *answer;
    int ans;

    num_1 = 1;
    num_2 = 2;
    answer = &ans;

    if(sum(&num_1, &num_2, &ans) != 0){
        //not reach, because sum() return 0
     printf("error\n");
    }

    printf("The answer is ...\n");

    printf("answer = %d\n", *answer);

    return 0;
}