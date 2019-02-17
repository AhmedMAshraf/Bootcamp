CC = gcc
CFILES = fun1.o fun2.o
CFLAGS = -Wl,-Map,output.map main.o fun1.o fun2.o

sum.exe: main.o $(CFILES)
	$(CC) -o sum.exe main.o $(CFILES)
	$(CC) $(CFLAGS)
main.o: fun1.h fun2.h main.c
	$(CC) -c main.c 
fun1.o: fun1.h fun1.c 
	$(CC) -c fun1.c 
fun2.o: fun2.h fun2.c 
	$(CC) -c fun2.c
clean: fun1.o main.o fun2.o
	del *.o *.map