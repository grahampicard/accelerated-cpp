# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 6-0-1 6-0-2 6-0-3 6-0-4 6-0-5

6-0-1: 6-0-1.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-2: 6-0-2.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-3: 6-0-3.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-4: 6-0-4.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-5: 6-0-5.cc grade.cc Student_info.cc median.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
