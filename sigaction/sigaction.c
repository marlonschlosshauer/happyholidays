#include "sigaction.h"

static void loopSignalHandler(int signal) {
		// Only works with C-z
		switch(signal) {
		case SIGTSTP:
				printf("Oh you want to stop ?\n");
				exit(0);
				break;
		}
}

int main() {
		struct sigaction handler;
		handler.sa_handler = loopSignalHandler;


		sigaction(SIGTSTP, &handler, NULL);

		while(1) {
				// Endless void
		}
		return 0;
}
