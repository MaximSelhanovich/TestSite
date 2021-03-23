useful: buildTest test valgrind_check linter_check
buildMain: Task2.c
	gcc -o Task2 Task2.c -std=c89 -lm

buildTest: test.c
	gcc -o test -Dmain=_main Task2.c test.c -std=c89 -pedantic -lm

test:
	./test
	
valgrind_check:
	echo "2\n30\n1\ny\n3\n60\n2\nn" > input.txt
	valgrind ./test < input.txt
	
linter_check:
	cpp Task2.c