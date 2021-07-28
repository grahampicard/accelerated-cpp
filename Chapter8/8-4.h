#include <algorithm>

using std::swap;

template <class Bi>
void myreverse(Bi begin, Bi end) {
  while (begin != end) {
    --end;
    if (begin != end) swap(*begin++, *end);
  }
}

template <class Bi>
void myreverse2(Bi begin, Bi end) {
  while (begin != end) {
    --end;
    if (begin != end) {
      Bi interim = end;
      interim = *end;
      *end = *begin++;
      *begin++ = *interim;
    }
  }
}
