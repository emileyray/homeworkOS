#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct {
	int count;
	int capacity;
	int *cookies;
} bank;

void* producer(void *vararg)
{
	while(1)
	{
		while(bank.count >= bank.capacity); // bank is full. wait
		
		if(bank.count >= bank.capacity) // if race condition happens, stop
		{
			printf("Error");
			exit(1);
		}
    
		bank.cookies[bank.count] = bank.count; // insert cookie
		sbanktr.count++;
	}
}
void* consumer(void *vararg)
{
	while(1)
	{
		while(bank.count <= 0); // bank is empty, wait
	
		if(bank.count <= 0) // if race condition happens, stop
		{
			printf("Error");
			exit(1);
		}

		bank.cookies[bank.count] = 0; // consume cookie
		bank.count--;
	}
}

int main()
{
	bank.capacity = 5;
	bank.count = 0;
	bank.cookies = (int*) malloc(bank.capacity * sizeof(int));
	
	pthread_t prod, cons;
	
	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&cons, NULL, consumer, NULL);
	
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);
	
	return 0;
}
