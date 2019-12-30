#include "fork.h"

int main() {
		createProcesses();
		printf("%s\n", "Done.");
		return 0;
}

int createProcesses() {
		int id = fork();

		if(id == 0) {

				printf("This is a child.\n");
				doX();
		} else {
				printf("This is the parent.\n");
				doX();
		}

		return 0;
}

int doX() {
		return 0;
}

int doY() {
		return 0;
}


