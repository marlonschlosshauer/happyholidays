compile: script.c
	gcc -o ./bin/script script.c

compile-test: script-test.c
	gcc -o ./bin/script-test script-test.c

run: compile
	./bin/script

test: compile compile-test
	./bin/script-test

clean:
	rm -rf bin/*
	rm -rf tmp/*

