/*
    The main idea behind this is to take some value form main funtion , process individually and come back :) 
*/
/*
 what we are going to do 
    * Will take some multiple values 
    * process each value individually 
    * and return !!    
*/


// I want to compute mean square on diffrent threads!!
//  data : 
//  [12 , 15 , 18 , 10 ,20]
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void* calculate(void *args);

int data[] = { 12, 15, 18, 10, 20 };
int* result[5];

int main(int argc, char const *argv[])
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    unsigned int x = sizeof(data) / sizeof(int); 
    pthread_t threads[x];
    for (uint16_t i = 0; i < x; i++)
    {
        pthread_create(&threads[i], NULL, calculate, &data[i]);
    }
    for (uint16_t i = 0; i < x; i++)
    {
        pthread_join(threads[i], (void**)&result[i]); 
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    int sum = 0;
    for (uint16_t i = 0; i < x; i++)
    {
        sum += *result[i];
        free(result[i]);
    }
    double mean_square = (double)sum / x;
    printf("Mean square: %.2f\n", mean_square);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time taken: %.9f seconds\n", time_taken);

    return 0;
}
void* calculate(void* args)
{
    int value = *(int*)args;
    int* result = (int*)malloc(sizeof(int));
    *result = value * value;
    return (void*)result;
}
