test:test.o list.o stack.o queue.o
	gcc -g -o  test test.o list.o stack.o queue.o
test.o:test.c 
	gcc -g -c  test.c
list.o:list.c
	gcc -g -c  list.c
stack.o:stack.c
	gcc -g -c  stack.c
queue.o:queue.c
	gcc -g -c  queue.c
clean:
	rm test *.o
