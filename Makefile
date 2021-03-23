useful: buildTest test valgrind_check linter_check
buildMain: Task1.c
	gcc -o Task1 Task1.c -std=c89 -lm

buildTest: test.c
	gcc -o test -Dmain=_main Task1.c test.c -std=c89 -pedantic -lm

test:
	./test
	
valgrind_check:
	echo "1\n2000\n2\n2\n3\n5500\n4\n2453.2\n5\n6\n7" > input.txt
	valgrind ./test < input.txt
	
linter_check:
	cpp Task1.c
	


