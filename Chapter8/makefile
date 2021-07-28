# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 8-0-1 8-1 8-2 8-3

8-0-1: 8-0-1.cc template_functions.h
	$(CC) $(CFLAGS) $^ -o $@.out

8-1: 8-1.cc analysis.cc median.cc Student_info.cc grade.cc
	$(CC) $(CFLAGS) $^ -o $@.out

8-2: 8-2.cc
	$(CC) $(CFLAGS) $^ -o $@.out

8-3: 8-3.cc median.cc analysis.cc grade.cc Student_info.cc
	$(CC) $(CFLAGS) $^ -o $@.out

8-4: 8-4.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
