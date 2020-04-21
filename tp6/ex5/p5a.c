#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct{
    int num1;
    int num2;
} numbers;


void *add_thr(void *arg){
    numbers nums = *(numbers *) arg;

    int res =  nums.num1+nums.num2;

    printf("Sum of numbers is %d. \n", res);

    return NULL;
}

void *sub_thr(void *arg){
    numbers nums = *(numbers *) arg;

    int res = nums.num1 - nums.num2;

    printf("Subtraction of numbers is %d. \n", res);

    return NULL;
}

void *mult_thr(void *arg){
    int *nums = (int *) arg;

    int res = nums[0] * nums[1];


    printf("Multiplication of numbers is %d. \n", res);

    return NULL;
}

void *div_thr(void *arg){
    int *nums = (int *) arg;

    int res = nums[0] / nums[1];

    printf("Division of numbers is %d. \n", res);

    return NULL;
}

int main(){
    //to add and subtract
    numbers nums;
    //to divide and multiply
    int arr[2] = { 0, 0};

    pthread_t tid[4];

    printf("Two numbes to operato on: \n");
    scanf("%d %d", &nums.num1, &nums.num2);

    arr[0] = nums.num1;
    arr[1] = nums.num2;

    pthread_create(&tid[0], NULL, add_thr, (void*) &nums);
    pthread_create(&tid[1], NULL, sub_thr, (void*) &nums);
    pthread_create(&tid[2], NULL, mult_thr, &arr);
    pthread_create(&tid[3], NULL, div_thr, &arr);


    pthread_exit(0);
}