#ifndef GUARD_MEDIAN_H
#define GUARD_MEDIAN_H

// median.h
#include <vector>
double median(std::vector<double>);

double median_iter(std::vector<double>::const_iterator first,
                   std::vector<double>::const_iterator last);

#endif  // GUARD_MEDIAN_H