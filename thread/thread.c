#include "thread.h"
int main() {
		int size = 7;
		int * threads = (int *) malloc(sizeof(int) * size);

		int i;
		for (i = 0; i < size; ++i){
				if(pthread_create(&threads[i], NULL, paint, NULL) != 0) {
						exit(1);
				}
		}

		printf("%s\n", "Waiting...");

		for (i = 0; i < size; ++i){
				pthread_join(threads[i], NULL);
				printf("Thread#%d finished.\n", threads[i]);
		}

		printf("%s\n", "Done.");

		exit(0);
}

void * paint(void * nothing) {
		printf("Thread finished working.\n");
		pthread_exit(0);
		printf("This should not be printed.\n");
		return NULL;
}
