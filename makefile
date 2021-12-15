CC = gcc
AR = ar -rcs
FLAGS = -Wall -g
OBJECTS_MAIN = main.o
OBJECT_MY_MAT = functions.o

all: stringProg funcs 

funcs: libclassfunc.a


libclassfunc.a:$(OBJECT_MY_MAT)
		$(AR) libclassfunc.a $(OBJECT_MY_MAT)

stringProg:$(OBJECTS_MAIN) libclassfunc.a
		$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) libclassfunc.a

main.o: functions.c functions.h
		$(CC) $(FLAGS) -c main.c

functions.o: functions.c functions.h
		$(CC) $(FLAGS) -c functions.c

.PHONY: clean all

Clean:
		rm -f *.o *.a stringProg funcs