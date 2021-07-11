# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 6-0-1 6-0-2 6-0-3 6-0-4 6-0-5 6-0-6 6-1 6-2 6-3 6-4 6-6

6-0-1: 6-0-1.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-2: 6-0-2.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-3: 6-0-3.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-4: 6-0-5.cc grade.cc median.cc Student_info.cc analysis.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-5: 6-0-6.cc grade.cc median.cc Student_info.cc Grade_check.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-0-6: 6-0-7.cc grade.cc median.cc Student_info.cc Grade_check_2.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-1: 6-1.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-2: 6-1.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-3: 6-3.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-4: 6-4.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-6: 6-6.cc Student_info.cc grade.cc analysis_v2.cc median.cc
	$(CC) $(CFLAGS) $^ -o $@.out

6-9: 6-9.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
