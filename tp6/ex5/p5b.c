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
    void *ret = malloc(sizeof(int));

    int res =  nums.num1+nums.num2;
    *(int *) ret = res;

    //printf("Sum of numbers is %d. \n", res);

    return ret;
}

void *sub_thr(void *arg){
    numbers nums = *(numbers *) arg;
    void *ret = malloc(sizeof(int));

    int res = nums.num1 - nums.num2;
    *(int *) ret = res;

    //printf("Subtraction of numbers is %d. \n", res);

    return ret;
}

void *mult_thr(void *arg){
    int *nums = (int *) arg;
    void *ret = malloc(sizeof(int));

    int res = nums[0] * nums[1];
    *(int *) ret = res;

    //printf("Multiplication of numbers is %d. \n", res);

    return ret;
}

void *div_thr(void *arg){
    int *nums = (int *) arg;
    void *ret = malloc(sizeof(int));

    int res = nums[0] / nums[1];
    *(int * )ret =res;

    //printf("Division of numbers is %d. \n", res);

    return ret;
}

int main(){
    //to add and subtract
    numbers nums;
    //to divide and multiply
    int arr[2] = { 0, 0};
    void *threadret[4];

    pthread_t tid[4];

    printf("Two numbes to operato on: \n");
    scanf("%d %d", &nums.num1, &nums.num2);

    arr[0] = nums.num1;
    arr[1] = nums.num2;

    pthread_create(&tid[0], NULL, add_thr, (void*) &nums);
    pthread_create(&tid[1], NULL, sub_thr, (void*) &nums);
    pthread_create(&tid[2], NULL, mult_thr, &arr);
    pthread_create(&tid[3], NULL, div_thr, &arr);

    pthread_join(tid[0], &threadret[0]);
    pthread_join(tid[1], &threadret[1]);
    pthread_join(tid[2], &threadret[2]);
    pthread_join(tid[3], &threadret[3]);

    printf("Sum of numbers is %d. \n",*(int *)threadret[0]);
    printf("Subtraction of numbers is %d. \n", *(int *)threadret[1]);
    printf("Multiplication of numbers is %d. \n", *(int *)threadret[2]);
    printf("Division of numbers is %d. \n", *(int *)threadret[3]);

   

    pthread_exit(0);
}