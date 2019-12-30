compile: thread.c
	gcc -o ./bin/thread thread.c

compile-test: thread-test.c
	gcc -o ./bin/thread-test thread-test.c

run: compile
	./bin/thread

test: compile compile-test
	./bin/thread-test

clean:
	rm -rf bin/*
	rm -rf tmp/*

