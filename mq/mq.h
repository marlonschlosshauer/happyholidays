#ifndef mq_
#define mq_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 64

struct Message {
		long type;
		char message[BUFFER_SIZE];
};

int createProcesses();
int doX(int messageID);
int doY(int messageID);

#endif
