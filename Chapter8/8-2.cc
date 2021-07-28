#include "8-2.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// using std::accumulate;
// using std::copy;
// using std::equal;
// using std::find;
// using std::find_if;
// using std::partition;
// using std::remove;
// using std::remove_copy;
// using std::remove_copy_if;
// using std::search;
// using std::transform;

int tra(int x) { return 8; }

bool greaterThanTwenty(int x) { return x > 20; }

int main() {
  // equal test
  std::string t1 = "thisq39847re78r9ad7fa89";
  std::string t2 = "thisq39847re78r9ad7fa89";
  std::string t3 = "thisq39847re78r9ad7fa88";

  // positive match
  bool test_equal_1a = std::equal(t1.begin(), t1.end(), t2.begin());
  bool test_equal_1b = _8_2_equal(t1.begin(), t1.end(), t2.begin());

  if (test_equal_1a != test_equal_1b) {
    return 1;
  }

  // netgative match
  bool test_equal_2a = std::equal(t1.begin(), t1.end(), t3.begin());
  bool test_equal_2b = _8_2_equal(t1.begin(), t1.end(), t3.begin());

  if (test_equal_2a != test_equal_2b) return 1;

  // search test
  std::string str = "thisstring";
  char r = 'r', z = 'z';

  std::string::iterator test_search_1a = std::find(str.begin(), str.end(), r);
  std::string::iterator test_search_1b = _8_2_find(str.begin(), str.end(), r);

  if (test_search_1a != test_search_1b) return 1;

  std::string::iterator test_search_2a = std::find(str.begin(), str.end(), z);
  std::string::iterator test_search_2b = _8_2_find(str.begin(), str.end(), z);

  if (test_search_2a != test_search_2b) return 1;

  // copy test
  std::string a = "okay", b = "    ", c = "    ", d, e;

  std::copy(a.begin(), a.end(), b.begin());
  _8_2_copy(a.begin(), a.end(), c.begin());

  if (b != c) return 1;

  std::copy(a.begin(), a.end(), std::back_inserter(d));
  _8_2_copy(a.begin(), a.end(), std::back_inserter(e));

  if (d != e) return 1;

  // remove_copy_if(b, e, d, p)
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> target_vec1, target_vec2;

  // remove_copy_if(iterator begin, iterator end, target, condition)
  std::remove_copy_if(vec.begin(), vec.end(), std::back_inserter(target_vec1),
                      IsOdd);

  _8_2_remove_copy_if(vec.begin(), vec.end(), std::back_inserter(target_vec2),
                      IsOdd);

  if (target_vec1 != target_vec2) return 1;

  //  transform
  std::vector<int> trans_vec1, trans_vec2;
  std::transform(vec.begin(), vec.end(), std::back_inserter(trans_vec1), tra);
  _8_2_transform(vec.begin(), vec.end(), std::back_inserter(trans_vec2), tra);

  if (trans_vec1 != trans_vec2) return 1;

  // accumulate
  int number_base = 100;
  std::string string_base = "abc";
  std::vector<std::string> strs{"d", "e", "f"};

  number_base = std::accumulate(vec.begin(), vec.end(), number_base);
  string_base = std::accumulate(strs.begin(), strs.end(), string_base);

  if (string_base != "abcdef") return 1;
  if (number_base != 155) return 1;

  // search
  std::string search_str = "this is the correct pattern";
  std::string search_pattern_true = "correct";
  std::string search_pattern_false = "corret";

  std::string::iterator ret =
      std::search(search_str.begin(), search_str.end(),
                  search_pattern_true.begin(), search_pattern_true.end());
  std::string::iterator ret2 =
      _8_2_search(search_str.begin(), search_str.end(),
                  search_pattern_true.begin(), search_pattern_true.end());

  if (ret != ret2) return 1;

  std::string::iterator ret3 =
      std::search(search_str.begin(), search_str.end(),
                  search_pattern_false.begin(), search_pattern_true.end());
  std::string::iterator ret4 =
      _8_2_search(search_str.begin(), search_str.end(),
                  search_pattern_false.begin(), search_pattern_true.end());

  if (ret3 != ret4) return 1;

  // find_if
  std::vector<int> find_vec_pass{0, 10, 20, 30, 40, 30, 20, 10, 0};
  std::vector<int> find_vec_fail{0, 1, 2, 3, 4, 3, 2, 1, 0};
  std::vector<int>::iterator find_ret_pass1, find_ret_fail1, find_ret_pass2,
      find_ret_fail2;

  find_ret_pass1 = std::find_if(find_vec_pass.begin(), find_vec_pass.end(),
                                greaterThanTwenty);
  find_ret_fail1 = std::find_if(find_vec_fail.begin(), find_vec_fail.end(),
                                greaterThanTwenty);

  find_ret_pass2 = _8_2_find_if(find_vec_pass.begin(), find_vec_pass.end(),
                                greaterThanTwenty);
  find_ret_fail2 = _8_2_find_if(find_vec_fail.begin(), find_vec_fail.end(),
                                greaterThanTwenty);

  if (find_ret_pass1 != find_ret_pass2) return 1;
  if (find_ret_fail1 != find_ret_fail2) return 1;

  // remove_copy
  std::vector<int> remove_copy_vec1, remove_copy_vec2;
  std::remove_copy(vec.begin(), vec.end(), std::back_inserter(remove_copy_vec1),
                   4);
  _8_2_remove_copy(vec.begin(), vec.end(), std::back_inserter(remove_copy_vec2),
                   4);

  if (remove_copy_vec1 != remove_copy_vec2) return 1;

  // remove
  std::vector<int> remove_vec1{0, 1, 2, 3, 4, 5};
  std::vector<int> remove_vec2{0, 1, 2, 3, 4, 5};
  std::remove(remove_vec1.begin(), remove_vec1.end(), 4);
  _8_2_remove(remove_vec2.begin(), remove_vec2.end(), 4);

  for (std::vector<int>::size_type i = 0; i < remove_vec2.size(); ++i) {
    if (remove_vec1[i] != remove_vec2[i]) return 1;
  }

  // partition
  std::vector<int> partition_vec1{0, 10, 20, 30, 40, 50};
  std::vector<int> partition_vec2{0, 10, 20, 30, 40, 50};
  std::partition(partition_vec1.begin(), partition_vec1.end(), greaterThanTwenty);
  _8_2_partition(partition_vec2.begin(), partition_vec2.end(), greaterThanTwenty);

  for (std::vector<int>::iterator i = partition_vec1.begin(); i != partition_vec1.end(); ++i) {
    std::cout << *i << std::endl;
  }

  for (std::vector<int>::iterator i = partition_vec2.begin(); i != partition_vec2.end(); ++i) {
    std::cout << *i << std::endl;
  }

  return 0;
}
