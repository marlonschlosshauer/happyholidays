compile: sigaction.c
	gcc -o ./bin/sigaction sigaction.c

compile-test: sigaction-test.c
	gcc -o ./bin/sigaction-test sigaction-test.c

run: compile
	./bin/sigaction

test: compile compile-test
	./bin/sigaction-test

clean:
	rm -rf bin/*
	rm -rf tmp/*

