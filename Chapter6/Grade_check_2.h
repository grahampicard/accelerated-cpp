#ifndef GUARD_Grade_check_2_h
#define GUARD_Grade_check_2_h

#include <vector>

#include "Student_info.h"

bool fgrade(const Student_info& s);

bool pgrade(const Student_info& s);

std::vector<Student_info> extract_fails(std::vector<Student_info>& students);

#endif
