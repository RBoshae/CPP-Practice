#include <iostream>
using namespace std;

// simple Date (too simple?)
struct Date {
  int y; // year
  int m; // month in year
  int d; // day of month
};

Date today; // a Date variable


// helper functions:
void init_day(Date& dd, int y, int m, int d) {
  // check that (y,m,d) is a valid Date
  // if it is, use it to initialize dd
  if (m > 0 && m <= 12) {
    if (d > 0 && d <= 31) {
      dd.y = y;
      dd.m = m;
      dd.d = d;
      return;
    }
  }
  cout << "Invalid date." << endl;
  dd.y = 0; dd.m = 0; dd.d = 0;
  return;
}

void add_day(Date& dd, int n) {
  // increase dd by n days

  // For loop version.
  for (int i = 0; i < n; i++) {
    dd.d++;
    if (dd.d>31){
      dd.d = 1;
      dd.m = (dd.m==12) ? 1 : dd.m+1; // month wrap around
      if (dd.m==1) ++dd.y;
    }
  }



}

ostream& operator<<(ostream& os, const Date& d) {
  return os << '(' << d.y
            << ',' << d.m
            << ',' << d.d << ')';
}

int main() {
  Date today;
  init_day(today, 1978, 6, 25);
  cout << today << endl;

  Date tomorrow = today;
  add_day(tomorrow,1);
  cout << tomorrow << endl;

  Date nextYear = today;
  add_day(nextYear,365);
  cout << nextYear << endl;

  Date invalid_date;
  init_day(invalid_date, 1900, -5, 100);
  cout << invalid_date << endl;
}
