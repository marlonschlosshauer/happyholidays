#include "rewr.h"

int main() {
		int hello = open("./res/hello.txt", O_RDWR | O_SYNC);
		char * buffer = (char *) malloc(128);
		read(hello, buffer, 128);
		printf("%s\n", buffer);
		strcat(buffer, " Goodbye.");
		write(hello, buffer, 128);
		close(hello);
		return 0;
}
