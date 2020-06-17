ASSIGNMENT=mystack
CALC_TEST=calc_test
MYSTACK_SHARED=mystack_shared

UNITY_FOLDER=lib/Unity
INC_DIRS=-Iinc
TEST_INC_DIRS=$(INC_DIRS) -I$(UNITY_FOLDER)

SHARED_FILES=src/PostfixCalc.c

MAIN = src/main.c

MYSTACK_FILES=$(SHARED_FILES) \
	      $(MAIN)

CALC_TEST_FILES=$(SHARED_FILES) \
	           $(UNITY_FOLDER)/unity.c \
	           test/PostfixCalc_test.c

HEADER_FILES=inc/*.h

CC=gcc

#SYMBOLS=-g  -O0 -std=c99 -Wall -Werror -pedantic
SYMBOLS=-g  -O0 -std=c99
TEST_SYMBOLS=$(SYMBOLS) -DTEST

.PHONY: clean test mystack

all: $(ASSIGNMENT)

$(ASSIGNMENT): Makefile $(MYSTACK_FILES) $(HEADER_FILES)
	$(CC) $(INC_DIRS) $(SYMBOLS) $(MYSTACK_FILES) -o $(ASSIGNMENT)

$(CALC_TEST): Makefile $(CALC_TEST_FILES)  $(HEADER_FILES)
	$(CC) $(TEST_INC_DIRS) $(TEST_SYMBOLS) $(CALC_TEST_FILES) -o $(CALC_TEST) -L. -lmystack -lm

$(MYSTACK_SHARED): $(MAIN)
	$(CC) $(INC_DIRS) $(MYSTACK_FILES) -g  -O0 -o mystack_shared -L. -lmystack -lm

clean:
	@rm -f $(ASSIGNMENT) $(CALC_TEST) $(MYSTACK_SHARED)

test: $(CALC_TEST)
	  @./$(CALC_TEST)
