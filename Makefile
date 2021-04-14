useful: buildMain valgrind_check linter_check
buildMain: Task2.c
	gcc -std=c89 -o Task2 Task2.c -lm

buildTest: test.c
	gcc -std=c89 -o test -Dmain=_main Task2.c test.c -pedantic -lm

test:
	./Task2
	
valgrind_check:
	echo "qwe\n\n" > input.txt
	valgrind --track-origins=yes ./Task2 < input.txt
	
linter_check:
	cpplint Task2.c
