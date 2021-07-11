# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 7-0-1

7-0-1: 7-0-1.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
