/*
    This is for quick revision if i forgets anyting :) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef enum status{
    OK,
    ERR,
    ZERO,
    NEG = -1,
}status_t;
void* threadexecutionfuntion(){ // this will just return 42 ...
    int* result = (int*)malloc(sizeof(int));
    *result = 42;
    return (void*)result;
}
int main(int argc, char const *argv[])
{
    int* result_from_thread;
    pthread_t thread1;
    if(pthread_create(&thread1 , NULL , &threadexecutionfuntion , NULL) != OK){
        return NEG;
    }
    if(pthread_join(thread1  , (void**) &result_from_thread) != OK ){
        return NEG; 
    }
    printf("value return will be : %d\n" , *result_from_thread);
    free(result_from_thread);
    return 0;
}
