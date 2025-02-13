#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define MAX_THREAD 20
#define bufferSize 10

sem_t semaphoreFull;
sem_t semaphoreEmpty;
pthread_mutex_t f;
pthread_mutex_t r;
int front = 0;
int rear = -1;
int buffer[10];
int iterator = 0;

void *generateNumber()
{
   
    while(1)
    {
        sem_wait(&semaphoreEmpty);
        pthread_mutex_lock(&r);
        rear = (rear + 1) % bufferSize;
        buffer[rear] = rand() % 20;
        printf("Number generated is %d\n",buffer[rear]);
        sleep(1);
        pthread_mutex_unlock(&r);
        sem_post(&semaphoreFull);   
    }
   
}

void *printNumber()
{
    while(1)
    {
        
        if(sem_wait(&semaphoreFull))
        {
            printf("Waiting for Producer\n");
        }
        else
        {
            pthread_mutex_lock(&f);
            int value = buffer[front];
            front = (front+1)%bufferSize;
            printf("Value printed is %d\n",value);
            sem_post(&semaphoreEmpty);
            pthread_mutex_unlock(&f);
            sleep(1);
        }
        
    }
    
}

int main()
{
    sem_init(&semaphoreFull,0,0);
    sem_init(&semaphoreEmpty,0,10);
    pthread_mutex_init(&f,NULL);
    srand(time(NULL));
    pthread_t consumer;
    pthread_t producer;
    pthread_create(&consumer,NULL,&generateNumber,NULL);
    pthread_create(&producer,NULL,&printNumber,NULL);
    pthread_join(consumer,NULL);
    pthread_join(producer,NULL);
    sem_destroy(&semaphoreFull);
    sem_destroy(&semaphoreEmpty);
    pthread_mutex_destroy(&f);
    pthread_mutex_destroy(&r);
    return 0;
}
