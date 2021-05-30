#!/usr/bin/env python
def adder(a, b):
    print(f"(adder) a, b: {a, b}")
    a = a + 10
    b = b + 10
    return


if __name__ == "__main__":
    a = 3
    b = 4

    # Ints are immutable
    adder(a, b)
    print(f"(adder) a, b: {a, b}")
