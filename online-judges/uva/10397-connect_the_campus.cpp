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

namespace DSU {
  vi p;
  void init(int n) {
    p.resize(n);
    forn(i,n)
      p[i] = i;
  }
  int get(int u) {
    if( p[u] == u )
      return u;
    return p[u] = get(p[u]);
  }
  bool merge(int u, int v) {
    u = get(u); v = get(v);
    if( u == v )
      return false;
    if( rand() & 1 )
      swap(u,v);
    p[u] = v;
    return true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<setprecision(2)<<fixed;
  
  int n;
  while( cin>>n ) {
    vector<pii> coord(n);
    forn(i,n)
      cin>>coord[i].first>>coord[i].second;
    DSU::init(n);
    int m; cin>>m;
    forn(i,m) {
      int u,v; cin>>u>>v;
      --u; --v;
      DSU::merge(u,v);
    }
    vector<tuple<int,int,int>> edges; edges.reserve(n*(n-1)/2);
    forn(u,n) forn(v,u)
      edges.eb(u,v,sqr(coord[u].first-coord[v].first)+sqr(coord[u].second-coord[v].second));
    sort(all(edges), 
      [ ] (const tuple<int,int,int>& lhs, const tuple<int,int,int>& rhs) {
        return get<2>(lhs) < get<2>(rhs);
      });
    double result = 0;
    for(auto e : edges) {
      int u,v,c;
      tie(u,v,c) = e;
      if( DSU::merge(u,v) )
        result += sqrt(c);
    }
    cout<<result<<"\n";
  }
  
  TIMESTAMP("end");
  return 0;
}