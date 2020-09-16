#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *print_message_function(void *ptr)
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}
int main()
{
     long N = 5; //number of threads
     pthread_t thread_id[100]; //the threads
     int iret[100]; //status of threads, 0 if ok

     for (long i = 0; i < N; i++){
        char* message; //the message to be printed
        sprintf(message, "Thread %ld is being created", i);
        
        iret[i] = pthread_create( &thread_id[i], NULL, print_message_function, (void*) message); //creating a thread
        
	      pthread_join( thread_id[i], NULL); //need this fo ordering threads
        
        printf("Thread %ld returns: %d\n",i, iret[i]); //printing status
	      printf("Thread %ld exits\n", i); //extiting
     }
     
     exit(0);
}
