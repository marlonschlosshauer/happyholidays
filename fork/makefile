compile: fork.c
	gcc -o ./bin/fork fork.c

compile-test: fork-test.c
	gcc -o ./bin/fork-test fork-test.c

run: compile
	./bin/fork

test: compile compile-test
	./bin/fork-test

clean:
	rm -rf bin/*
	rm -rf tmp/*

