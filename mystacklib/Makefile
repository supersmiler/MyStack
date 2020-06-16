# Makefile for shared library

CC = gcc 
LD = gcc
CPPFLAGS = -DDEBUG=1
CFLAGS =  -fPIC -Wall -Wextra -std=c11 -O -g 
LDFLAGS = -shared  
RM = rm -f  
TARGET_LIB = libmystack.so 

SRCS = mystack.c \
	linked_list.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean 
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(LD) ${LDFLAGS} -o $@ $^
	cp $@ ../mystack

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)
