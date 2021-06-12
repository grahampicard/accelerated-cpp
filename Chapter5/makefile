# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 5-0-1 5-0-2 5-0-3 5-0-4 5-0-5

5-0-1: 5-0-1.cc grade.cc Student_info.cc median.cc Grade_check.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-0-2: 5-0-2.cc grade.cc Student_info.cc median.cc Grade_check_v2.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-0-3: 5-0-3.cc grade.cc Student_info.cc median.cc Grade_check_v3.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-0-4: 5-0-4.cc grade.cc Student_info.cc median.cc Grade_check_v4.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-0-5: 5-0-5.cc string_split.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
