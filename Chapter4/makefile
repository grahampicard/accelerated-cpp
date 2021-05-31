# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 4-0-1 4-0-2 4-2 4-3 4-4 4-5-1 4-5-2

4-0-1: 4-0-1.cc
	$(CC) $(CFLAGS) $^ -o $@.out

4-0-2: 4-0-2.cc grade.cc Student_info.cc median.cc
	$(CC) $(CFLAGS)  $^ -o $@.out

4-2: 4-2.cc
	$(CC) $(CFLAGS) $^ -o $@.out

4-3: 4-3.cc
	$(CC) $(CFLAGS) $^ -o $@.out

4-4: 4-4.cc
	$(CC) $(CFLAGS) $^ -o $@.out

4-5-1: 4-5-1.cc inputs.cc
	$(CC) $(CFLAGS) $^ -o $@.out

4-5-2: 4-5-2.cc inputs.cc
	$(CC) $(CFLAGS) $^ -o $@.out

4-6: 4-6.cc grade_v2.cc Student_info_v2.cc median.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
