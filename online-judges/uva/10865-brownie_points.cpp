#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define sqr(x)     ((x) * (x))
#define eq(x, y)   (((x) > (y) ? (x) - (y) : (y) - (x)) <= eps)
#define sz(x)      int((x).size())
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()
#define fst        first
#define snd        second
#define pb         push_back
#define mp         make_pair
#define eb         emplace_back
#define ef         emplace_front
#define mt         make_tuple
#define eps        1e-8
#define inf        int(1e9)
#define linf       llong(4e18)
using namespace std;

struct debug_t {
  template<typename T>
  debug_t& operator << (const T& o) {
#   ifdef LOCAL_DEBUG
    cout<<o<<flush;
#   endif
    return *this;
  }
} debug;

#define TIMESTAMP(msg) debug << "[" msg "] Time = " << clock() * 1.0 / CLOCKS_PER_SEC << '\n' 
#define DBG(x) debug << "[" #x "] = " << x << '\n'
#define DOUT(x) debug << x << '\n'
#define _ << " " <<

typedef unsigned char       uchar;
typedef basic_string<uchar> ustring;
typedef long long           llong;
typedef unsigned long long  ullong;
typedef long double         ldouble;
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef vector<double>      vd;
typedef vector<vd>          vvd;
typedef pair<int,int>       pii;

struct Point {
  double x,y;
  Point() { }
  Point(double x, double y) : x(x), y(y) { }
  Point operator + (const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator - (const Point& p) const { return Point(x - p.x, y - p.y); }
  double operator * (const Point& p) const { return x * p.y - y * p.x; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while( cin>>n, n ) {
    Point center;
    vector<Point> p;
    forn(i,n)
      if( i == n - i - 1 )
        cin>>center.x>>center.y;
      else
        p.eb(), cin>>p.back().x>>p.back().y;
    n = sz(p);
    int stan = 0, ollie = 0;
    forn(i,n) {
      double s1 = Point(0, 1) * (p[i] - center);
      double s2 = Point(1, 0) * (p[i] - center);
      if( eq(s1,0) || eq(s2, 0) )
        continue;
      bool left = s1 > 0;
      bool up = s2 > 0;
      if( (left && up) || (!left && !up) )
        ++ollie;
      else
        ++stan;
    }
    cout<<stan<<" "<<ollie<<"\n";
  }
  
  TIMESTAMP("end");
  return 0;
}


