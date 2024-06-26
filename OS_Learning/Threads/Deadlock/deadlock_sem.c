#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

sem_t sem1;
sem_t sem2;

void* thread1(void* arg)
{
        sem_wait(&sem1);
        printf("Thread 1 aquires sem1\n");

        sem_wait(&sem2);
        printf("Thread 1 aquires sem2\n");

        sem_post(&sem2);
        sem_post(&sem1);
}

void *thread2(void *arg)
{
        sem_wait(&sem2);
        printf("Thread 2 aquires sem2\n");

        sem_wait(&sem1);
        printf("Thread 2 aquires sem1\n");

        sem_post(&sem1);
        sem_post(&sem2);
}

int main()
{
        pthread_t t1,t2;

	//	sem_init(&sem1, 0, 0);  // Both threads will block
	//	sem_init(&sem2, 0, 0);

		sem_init(&sem1, 1, 1);
		sem_init(&sem2, 0, 1);
        pthread_create(&t1, NULL, thread1, NULL);
        pthread_create(&t2, NULL, thread2, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        return 0;
}
