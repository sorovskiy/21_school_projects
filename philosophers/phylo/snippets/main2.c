#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/errno.h>
#include <string.h>

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD   -12
#define BAD_MESSAGE         -13
#define SUCCESS               0

typedef struct someArgs_tag {
	int id;
	const char *msg;
	int out;
} someArgs_t;

void* helloWorld(void *args) {
	someArgs_t *arg = (someArgs_t*) args;
	int len;

	if (arg->msg == NULL) {
		return BAD_MESSAGE;
	}

	len = strlen(arg->msg);
	printf("%s\n", arg->msg);
	arg->out = len;

	return SUCCESS;
}

#define NUM_THREADS 4

int main() {
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	int status;
	int i;
	int status_addr = 9876;
	someArgs_t args[NUM_THREADS];
	const char *messages[] = {
			"First",
			"NULL",
			"Third Message",
			"Fourth Message"
	};

	for (i = 0; i < NUM_THREADS; i++) {
		args[i].id = i;
		args[i].msg = messages[i];
	}


	pthread_create(&thread1, NULL, helloWorld, (void*) &args[0]);
	pthread_create(&thread2, NULL, helloWorld, (void*) &args[1]);
	pthread_create(&thread3, NULL, helloWorld, (void*) &args[2]);
	pthread_create(&thread4, NULL, helloWorld, (void*) &args[3]);

	printf("Main Message\n");

//	for (i = 0; i < NUM_THREADS; i++) {
//		status = pthread_join(threads[i], (void**)&status_addr);
//		if (status != SUCCESS) {
//			printf("main error: can't join thread, status = %d\n", status);
//			exit(ERROR_JOIN_THREAD);
//		}
//		printf("joined with address %d, i: %d, status: %d\n", status_addr, i, status);
//	}

	status = pthread_join(thread1, (void**)&status_addr);
	if (status != SUCCESS) {
		printf("main error: can't join thread, status = %d\n", status);
	}
	printf("joined thread1 with address %d, i: %d, status: %d\n", status_addr, i, status);

	status = pthread_join(thread2, (void**)&status_addr);
	if (status != SUCCESS) {
		printf("main error: can't join thread, status = %d\n", status);
	}
	printf("joined thread2 with address %d, i: %d, status: %d\n", status_addr, i, status);

	status = pthread_join(thread3, (void**)&status_addr);
	if (status != SUCCESS) {
		printf("main error: can't join thread, status = %d\n", status);
	}
	printf("joined thread3 with address %d, i: %d, status: %d\n", status_addr, i, status);

	status = pthread_join(thread4, (void**)&status_addr);
	if (status != SUCCESS) {
		printf("main error: can't join thread, status = %d\n", status);
	}
	printf("joined thread4 with address %d, i: %d, status: %d\n", status_addr, i, status);






	for (i = 0; i < NUM_THREADS; i++) {
		printf("thread %d arg.out = %d\n", i, args[i].out);
	}

	return 0;
}