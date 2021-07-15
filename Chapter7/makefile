# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 7-0-1 7-0-2 7-0-3 7-1 7-2 7-3 7-4 7-7 7-8

7-0-1: 7-0-1.cc
	$(CC) $(CFLAGS) $^ -o $@.out

7-0-2: 7-0-2.cc string_split.cc
	$(CC) $(CFLAGS) $^ -o $@.out

7-0-3: 7-0-3.cc grammar_exercise.cc string_split.cc
	$(CC) $(CFLAGS) $^ -o $@.out

7-1: 7-1.cc
	$(CC) $(CFLAGS) $^ -o $@.out

7-2: 7-2.cc grade.cc median.cc Student_info.cc
	$(CC) $(CFLAGS) $^ -o $@.out

7-3: 7-3.cc string_split.cc
	$(CC) $(CFLAGS) $^ -o $@.out

7-4: 7-4.cc grammar_exercise_list.cc
	$(CC) $(CFLAGS) $^ -o $@.out

7-7: 7-7.cc string_split.cc
	$(CC) $(CFLAGS) $^ -o $@.out

7-8: 7-8.cc urls.cc string_split.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
