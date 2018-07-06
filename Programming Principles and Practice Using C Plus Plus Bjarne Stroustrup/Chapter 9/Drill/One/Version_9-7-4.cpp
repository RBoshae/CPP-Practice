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

    Date(int y, Month m, int d); // check for valid date and initialize

    int day() const {return d;}
    Month month() const {return m;}
    int year() const {return y;}

    void add_day(int n);         // increase the Date by n days.
    void add_month(int n);       // increase the Date by n months.
    void add_year(int n);        // increase the Date by n days.
  private:
    int y;                  // year
    Month m;
    int  d;                 // day of month
};

Date::Date(int y, Month m, int d) {
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
  this->y = 0; this->m = jan; this->d = 0;
  return;
}; // check for valid date and initialize


void Date::add_day(int n) {
  // increase by n days

  // For loop version.
  for (int i = 0; i < n; i++) {
    d++;
    if (d>31){
      d = 1;
      m = (m==dec) ? jan : Date::Month(m+1); // month wrap around
      if (m==Date::jan) ++y;
    }
  }

}

void Date::add_month(int n) {
  // increase by n months

  // For loop version.
  for (int i = 0; i < n; i++) {
    m = (m==dec) ? jan : Date::Month(m+1); // month wrap around
    if (m==Date::jan) ++y;
  }
}

void Date::add_year(int n) {
  // increase by n years
  y+=n;
}

ostream& operator<<(ostream& os, Date& d) {
  return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')';
}


int main() {
  // Date today(2018,7,5);  // colloquial style
  Date today =  Date(1978,Date::jun,28);     // verbose styles
  cout << today << endl;

  Date tomorrow = today;
  tomorrow.add_day(1);
  cout << tomorrow << endl;

  Date nextYear = today;
  nextYear.add_day(365);
  cout << nextYear << endl;

  Date invalid_date(1900, Date::jan, 100);
  cout << invalid_date << endl;
}
