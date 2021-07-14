#ifndef GUARD_urls_h
#define GUARD_urls_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool not_url_char(char c);

std::string::const_iterator url_end(std::string::const_iterator b,
                                    std::string::const_iterator e);

std::string::const_iterator url_beg(std::string::const_iterator b,
                                    std::string::const_iterator e);
std::vector<std::string> find_urls(const std::string& s);

#endif