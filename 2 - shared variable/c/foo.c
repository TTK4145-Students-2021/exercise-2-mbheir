#include <pthread.h>
#include <stdio.h>

int i = 0;

//Since we want to lock of the variable i when we update it in each thread, and not signal for wait it 
//makes sense to use the mutex lock here. 
pthread_mutex_t lock_i;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (int j = 0; j < 1000000; j++) {
	// TODO: sync access to i
	pthread_mutex_lock(&lock_i);
    i++;
    pthread_mutex_unlock(&lock_i);
    }
    i++;
    return NULL;
}

void* decrementingThreadFunction(){
    for (int j = 0; j < 1000000; j++) {
	// TODO: sync access to i
	pthread_mutex_lock(&lock_i);
    i--;
    pthread_mutex_unlock(&lock_i);
    }
    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;
    
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);

    
    printf("The magic number is: %d\n", i);
    return 0;
}
