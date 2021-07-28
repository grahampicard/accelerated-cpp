# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 9-1

8-1: 9-1.cc Student_info.cc grade.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
