# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
all: 5-0-1 5-0-2 5-0-3 5-0-4 5-0-5 5-0-5-test 5-0-6 5-0-7-h 5-0-7-v 5-1 5-2-vector 5-2-list 5-3 5-5 5-6

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

5-0-5-test: 5-0-5-test.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-0-6: 5-0-6.cc string_split.cc frames.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-0-7-h: 5-0-7-h.cc string_split.cc frames.cc concats.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-0-7-v: 5-0-7-v.cc string_split.cc frames.cc concats.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-1: 5-1.cc string_split.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-2-vector: 5-2-vector.cc Grade_check_v4.cc grade.cc Student_info.cc median.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-2-list: 5-2-list.cc Grade_check_v4.cc grade.cc Student_info.cc median.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-3: 5-3.cc Grade_check_v4.cc grade.cc Student_info.cc median.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# 5-4: 5-3.cc Grade_check_v4.cc grade.cc Student_info.cc median.cc
# 	$(CC) $(CFLAGS) $^ -o $@.out

5-5: 5-5.cc
	$(CC) $(CFLAGS) $^ -o $@.out

5-6: 5-6.cc Grade_check_v5.cc grade.cc Student_info.cc median.cc
	$(CC) $(CFLAGS) $^ -o $@.out

# remove all .out files
clean:
	rm *.out
