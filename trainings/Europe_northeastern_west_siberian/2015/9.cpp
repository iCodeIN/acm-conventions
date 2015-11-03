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
#include <assert.h>
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



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while( cin>>n ) {
    vector<pair<llong,llong>> a(n);
    llong sum_left = 0, sum_right = 0;
    forn(i,n) 
      cin>>a[i].first, a[i].second = i, sum_right += a[i].first;
    sort(all(a));
    vector<pair<llong,llong>> result(n);
    forn(i,n) {
      int ind = a[i].second;
      
      llong left_square = i * a[i].first;
      result[ind].first = sum_left - left_square;
      sum_left += a[i].first;
      
      llong right_square = (n - i) * a[i].first;
      result[ind].second = sum_right - right_square;
      sum_right -= a[i].first;
    }
    for(auto p : result)
      cout<<p.first<<" "<<p.second<<"\n";
    DOUT("");
  }
  
  TIMESTAMP("end");
  return 0;
}