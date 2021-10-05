#include <iostream>

using namespace std;

#include "Range.hpp"

Range::Range(int min, int max) {
  Val = Min = min;
  Max = max;
}

void Range::incVal(void) {
  Val += 1;
  if (Val >= Max) {
    Val = Max - 1;
  }
}

void Range::incVal(int step) {
  Val += step;
  if (Val >= Max) {
    Val = Max - 1;
  }
}

void Range::repr(ostream &s) {
  s << "Range object: " <<  " [" << Min << ", " << Max << "[ = " << Val << endl;
}

void Range::repr(void) {
  cout << "Range object: " << " [" << Min << ", " << Max << "[ = " << Val << endl;
}

void Range::setVal(int val) {
  Val = val;
  if (Val < Min)
    Val = Min;
  if (Val >= Max)
    Val = Max - 1;
}

int Range2::getVal(void) {
  return Val;
}

void Range2::repr(ostream &s) {
  s << "R2: \"" << Name << "\" ";
  Range::repr(s);
}

void Range2::repr(void) {
  cout << "R2: \"" << Name << "\" ";
  Range::repr();
}

