#ifndef pipe_
#define pipe_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 64

int createProcesses();
void send(char * buffer, int size);
void receive(char * buffer, int size);

#endif
