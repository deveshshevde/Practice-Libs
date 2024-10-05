#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <fcntl.h> 

#define THREAD_NUM 8

sem_t* semaphoreEmpty;
sem_t* semaphoreFull;

pthread_mutex_t mutexBuffer;

size_t buffer[10];
size_t count = 0;

void* producer(void* args) {
    while (1) {
        size_t x = rand() % 100;
        sleep(1);
        sem_wait(semaphoreEmpty);
        pthread_mutex_lock(&mutexBuffer);
        // Lock the critical condition , which may cause race!
        buffer[count] = x;
        count++;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(semaphoreFull);
    }
}
void* consumer(void* args) {
    while (1) {
        size_t y;
        sem_wait(semaphoreFull);
        pthread_mutex_lock(&mutexBuffer);
        y = buffer[count - 1];
        count--;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(semaphoreEmpty);
        printf("Got %lu\n", y); 
        sleep(2);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexBuffer, NULL);
    semaphoreEmpty = sem_open("/semaphoreEmpty", O_CREAT, 0644, 10);  // Buffer size is 10
    semaphoreFull = sem_open("/semaphoreFull", O_CREAT, 0644, 0);     // Initially empty
    if (semaphoreEmpty == SEM_FAILED || semaphoreFull == SEM_FAILED) {
        perror("sem init failed");
        return 1;
    }
    size_t i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (i > 0) {
           pthread_create(&th[i], NULL, &producer, NULL);
        } else 
        {
           pthread_create(&th[i], NULL, &consumer, NULL);
        }
    }

    for (i = 0; i < THREAD_NUM; i++)
     {
        pthread_join(th[i], NULL);
     }
    sem_close(semaphoreEmpty);
    sem_close(semaphoreFull);
    sem_unlink("/semaphoreEmpty");
    sem_unlink("/semaphoreFull");
    pthread_mutex_destroy(&mutexBuffer);

    return 0;
}
