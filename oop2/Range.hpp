#ifndef _range_hpp
#define _range_hpp

#include <iostream>

class Range {
protected:
  int Val;
private:
  int Max, Min;
public:
  Range(int min, int max);
  void incVal(void);
  void incVal(int step);
  void repr(std::ostream &s);
  void repr(void);
  void setVal(int val);
  void operator+=(int x) { Val += x; if (Val >= Max) Val = Max -1;};
  void operator+=(Range x) { Val += x.Val; if (Val >= Max) Val = Max -1;};
};

class Range2 : public Range {
protected:
  std::string Name;
 public:
  Range2(int min, int max, std::string name) : Range(min, max) {
    Name = name;
   }
  int getVal(void);
  void repr(std::ostream &s);
  void repr(void);
};

#endif
