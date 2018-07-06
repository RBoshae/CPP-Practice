#include <iostream>
using namespace std;

// simple Date (use Month type)
class Date {

  public:
    enum Month {
      jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int y, Month m, int d); // check for valid date and initialize
    void add_day(int n);       // increase the Date by n days.
    Month month() {return m;}
    int day() {return d;}
    int year() {return y;}

  private:
    int y;                  // year
    Month m;
    int  d;                 // day


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
  this->y = 0; this->m = Date::jan; this->d = 0;
  return;
}; // check for valid date and initialize


void Date::add_day(int n) {
  // increase by n days

  // Modulo hybrid version.
  d += n;
  for (int i = 0; i < n; i++) {
    d++;
    if (d>31){
      d = 1;
      ++m;
      if (m==Date::jan) ++y;
    }
  }

}

// helper functions
ostream& operator<<(ostream& os, Date& d) {
  return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')';
}

Date::Month Date::operator++(Month& m){
  m = (m==dec) ? jan : Date::Month(m+1);
  return m;
}

// Month& operator+=(Month& m, int n){
//   m = (m==dec) ? jan : Month(m+n);
// }

int main() {
  // Date today(2018,7,5);  // colloquial style
  Date today =  Date(1978,Date::jun,25);     // verbose styles
  cout << today << endl;

  Date tomorrow = today;
  today.add_day(1);
  cout << tomorrow << endl;

  Date nextYear = today;
  nextYear.add_day(365);
  cout << nextYear << endl;

  Date invalid_date(1900, Date::jan, 100);
  cout << invalid_date << endl;
}
