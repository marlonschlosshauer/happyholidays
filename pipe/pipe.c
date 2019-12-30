#include "pipe.h"

int main() {
		createProcesses();
		printf("%s\n", "Done.");
		return 0;
}

int createProcesses() {

		int fd[2][2];

		pipe(fd[0]);
		pipe(fd[1]);

		int id = fork();

		if(id == 0) {
				char * buffer = (char * ) malloc(BUFFER_SIZE);
				char * message = "Hello, anybody out there ?";
				int size = strlen(message);

				memmove(buffer, message, size);
				write(fd[0][1], message, size);
				printf("Child sent : %s\n", buffer);

				memset(buffer, '\0', BUFFER_SIZE);

				read(fd[1][0], buffer, BUFFER_SIZE);
				printf("Child received : %s\n", buffer);
				free(buffer);

		} else {
				int size = BUFFER_SIZE;
				char * message = (char *) malloc(sizeof(char) * size);
				read(fd[0][0], message, size);
				printf("Parent received : %s\n", message);
				free(message);

				message = "Yes I'm here.";
				size = strlen(message);
				write(fd[1][1], message, size);
				printf("Parent sent : %s\n", message);
				waitpid(id, NULL, 0);
		}

		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);

		return 0;
}
