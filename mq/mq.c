#include "mq.h"

int main() {
		createProcesses();
		printf("Done.\n");
		return 0;
}

int createProcesses() {
		int messageID = msgget(IPC_PRIVATE, IPC_CREAT | S_IRWXU);
		printf("MessageID : %d\n", messageID);
		int processID = fork();

		if(processID == 0) {
				doY(messageID);
				printf("Child done.\n");
		} else {
				doX(messageID);
				printf("Parent done.\n");
				waitpid(processID, NULL, 0);
				printf("Closing mq ... %i\n",msgctl(messageID, IPC_RMID, NULL));
		}

		return 0;
}

int doX(int messageID) {
		struct Message request;
		request.type = 1l;
		strcpy(request.message, "Hello, did you get this message ?");
		msgsnd(messageID, &request, strlen(request.message) + 1, 0);
		msgrcv(messageID, &request, BUFFER_SIZE, 2, 0);
		printf("Parent : %s\n", request.message);
		return 0;
}

int doY(int messageID) {
		struct Message request;
		msgrcv(messageID, &request, BUFFER_SIZE, 1, 0);
		printf("Child : %s\n", request.message);
		request.type = 2;
		strcpy(request.message, "Yes I got the message");
		msgsnd(messageID, &request, strlen(request.message) + 1, 0);
		return 0;
}


