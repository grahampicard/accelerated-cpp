#ifndef GUARD_8_2_h
#define GUARD_8_2_h

#include <algorithm>

// bool equal(s.begin(), s.end(), t.start());
template <class Input1, class Input2>
bool _8_2_equal(Input1 a, Input1 b, Input2 c) {
  while (a != b) {
    if (*a != *c) return false;
    ++a;
    ++c;
  }
  return true;
}

// iterator find(s.begin(), s.end(), char);
template <class Input, class Pattern>
Input _8_2_find(Input start, Input end, Pattern p) {
  while (start != end) {
    if (*start == p) return start;
    ++start;
  }
  return end;
}

// copy(begin, end, out)
template <class Input, class Output>
Output _8_2_copy(Input start, Input end, Output out) {
  for (; start != end; ++start) {
    *out++ = *start;
  }
  return out;
}

// remove_copy_if
bool IsOdd(int i) { return ((i % 2) == 1); }

// remove_copy_if(iterator begin, iterator end, target, condition)
template <class Input, class Output, class Condition>
Output _8_2_remove_copy_if(Input start, Input end, Output target,
                           Condition func) {
  for (; start != end; ++start) {
    if (!func(*start)) {
      *target = *start;
    }
    ++target;
  }
  return target;
}

template <class Input, class Output, class Transformer>
Output _8_2_transform(Input start, Input end, Output target, Transformer func) {
  for (; start != end; ++start) {
    *target = func(*start);
    ++target;
  }
  return target;
}

template <class Input, class Pattern>
Input _8_2_search(Input start, Input end, Pattern pstart, Pattern pend) {
  if (pstart == pend) return start;

  while (start != end) {
    Input it1 = start;
    Pattern it2 = pstart;

    while (*it1 == *it2) {
      ++it1, ++it2;

      if (it2 == pend) return start;
      if (it1 == end) return end;
    }
    ++start;
  }
  return end;
}

template <class Input, class Condition>
Input _8_2_find_if(Input inputStart, Input inputEnd, Condition boolFunc) {
  for (; inputStart != inputEnd; ++inputStart) {
    if (boolFunc(*inputStart)) return inputStart;
  }
  return inputEnd;
}

template <class Input, class Output, class Val>
Output _8_2_remove_copy(Input start, Input end, Output target, Val value) {
  for (; start != end; ++start) {
    if (*start != value) {
      *target = *start;
    }
    ++target;
  }
  return target;
}

template <class Iter, class Value>
Iter _8_2_remove(Iter start, Iter end, Value val) {
  Iter result = start;
  while (start != end) {
    if (!(*start == val)) {
      if (result != start) *result = *start;
      ++result;
    }
    ++start;
  }
  return result;
}

template <class Iter, class Func>
Iter _8_2_partition(Iter start, Iter end, Func conditional) {
  while (start != end) {
    // let's first take care of the case where all is true
    while (conditional(*start)) {
      ++start;
      if (start == end) return start;
    }
    do {
      --end;
      if (start == end) return start;
    } while (!conditional(*end));
    std::swap(*start, *end);
    ++start;
  }
  return start;
}

#endif