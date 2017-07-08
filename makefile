CC     = gcc
CFLAGS = -g
OBJS = funcoes_extras.o big_num.o funcoes.o tp1.o 
TARGET = tp1

all: $(TARGET)

tp1: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o tp1
	
tp1.o: tp1.c  funcoes_extras.h big_num.h funcoes.h
		$(CC) $(CFLAGS)  -c tp1.c
	
funcoes.o: funcoes.c funcoes.h big_num.c big_num.h funcoes_extras.c funcoes_extras.h
	$(CC) $(CFLAGS)  -c funcoes.c
big_num.o: big_num.c big_num.h funcoes_extras.c funcoes_extras.h
	$(CC) $(CFLAGS)  -c big_num.c
	
funcoes_extras.o: funcoes_extras.c funcoes_extras.h  
	$(CC) $(CFLAGS)  -c funcoes_extras.c
	
clean: 
	rm -rf *.o ./$(TARGET)
		



