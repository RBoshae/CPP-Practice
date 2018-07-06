#include <iostream>
using namespace std;

class Year {// year in [min:max) range]
  static const int min = 1800;
  static const int max = 2200;

  public:
    class Invalid {};
    Year(int x) : y(x){ if (x < min || max < x) throw Invalid();}
    int year() {return y;}

  private:
    int y;
};

// simple Date (use Month type)
class Date {

  public:
    enum Month {
      jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int y, Month m, Year d); // check for valid date and initialize
    void add_day(int n);       // increase the Date by n days.
    int month() {return m;}
    int day() {return d;}
    int year() {return y.year();}

  private:
    Year y;                  // year
    Month m;
    int  d;                 // day
};

Date::Date(int y, Month m, Year d) {
  // check that (y,m,d) is a valid Date and initialize
  if (m > 0 && m <= 12) {
    if (d > 0 && d <= 31) {
      this->y = y;
      this->m = m;
      this->d = d;
      return;
    }
  }
  cout << "Invalid date." << endl;
  this->y = 0; this->m = 0; this->d = 0;
  return;
}; // check for valid date and initialize


void Date::add_day(int n) {
  // increase dd by n days

  // Decided to implement the modulo version.
  d += n;
  if (d > 31) {
    m += d / 31;
    d = d%31;
  }
  if (m > 12) {
    y += m/12;
    m = m%12;
  }

}

ostream& operator<<(ostream& os, Date& d) {
  return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')';
}


int main() {
  // Date today(2018,7,5);  // colloquial style
  Date today =  Date(2018,7,5);     // verbose styles
  cout << today << endl;

  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << tomorrow << endl;

  Date nextYear = today;
  nextYear.add_day(365);
  cout << nextYear << endl;

  Date invalid_date(1900, -5, 100);
  cout << invalid_date << endl;
}
