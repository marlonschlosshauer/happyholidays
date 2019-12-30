compile: rewr.c
	gcc -o ./bin/rewr rewr.c

compile-test: rewr-test.c
	gcc -o ./bin/rewr-test rewr-test.c

run: compile
	./bin/rewr

test: compile compile-test
	./bin/rewr-test

clean:
	rm -rf bin/*
	rm -rf tmp/*

