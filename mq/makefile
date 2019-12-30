compile: mq.c
	gcc -o ./bin/mq mq.c

compile-test: mq-test.c
	gcc -o ./bin/mq-test mq-test.c

run: compile
	./bin/mq

test: compile compile-test
	./bin/mq-test

clean:
	rm -rf bin/*
	rm -rf tmp/*

