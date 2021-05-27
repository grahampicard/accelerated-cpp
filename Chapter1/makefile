# Declare compilers that will be used
# := 	#onetime assignment
# = 	#dynamic assignment
CC := g++
CFLAGS := -Wall -g

# These are the references we make to our .cc files and
# the ouptut files that we want to create
SRCS := $(wildcard *.cc)
OBJS := $(patsubst %.cc, %, $(SRCS))

# Make follows the patern
#
# 	Target: Prerequisite
# 		Rule
#
# Make first checks if the prerequisite exists. If it doesn't,
# Then it recursively finds the starting file. At this point,
# Make then generates the "target" based on the rule provided
# below.
#
# In our case, we want `all` to generate outputs for each .cc
# file that we have. 
# 
# make will first check to make sure $(OBJS) files exists.
all:$(OBJS)

# Make will create an object for each source
# $@ #target 
# $< #source
$(OBJS):
	$(CC) $(CFLAGS) -o $@.out $@.cc 

# remove all .out files
clean:
	rm *.out