.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN=pool
OBJS=condition.o threadpool.o main.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread -lrt
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
clean:
	rm -f *.o $(BIN)
