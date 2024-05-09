CC = gcc
CFLAGS = -O2 -Wall -I .
LIBS = -lpthread

all: echoclient echoserver

echoclient: echoclient.c csapp.c
	$(CC) $(CFLAGS) -o echoclient echoclient.c csapp.c $(LIBS)

echoserver: echoserver.c csapp.c
	$(CC) $(CFLAGS) -o echoserver echoserver.c csapp.c $(LIBS)

clean:
	rm -f *.o echoclient echoserver
