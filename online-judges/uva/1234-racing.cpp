#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define sqr(x)     ((x) * (x))
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
#define _ <<" "<<

typedef unsigned char      uchar;
typedef long long          llong;
typedef unsigned long long ullong;
typedef long double        ldouble;
typedef vector<int>        vi;
typedef vector<vi>         vvi;
typedef vector<double>     vd;
typedef vector<vd>         vvd;
typedef pair<int,int>      pii;

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
  u = get(u);
  v = get(v);
  if( u == v )
    return false;
  if( rand() & 1 )
    swap(u,v);
  p[u] = v;
  return true;
}
}

typedef tuple<int,int,int> Edge;
bool cmp(const Edge& a, const Edge& b) {
  return get<2>(a) > get<2>(b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int cn; cin>>cn;
  forn(ci,cn) {
    int n,m; cin>>n>>m;
    int u,v,c;
    vector<Edge> edges; edges.reserve(m);
    int total = 0;
    forn(e,m) {
      cin>>u>>v>>c;
      --u; --v;
      edges.eb(u,v,c);
      total += c;
    }
    sort(all(edges), cmp);
    DSU::init(n);
    for(Edge e : edges) {
      tie(u,v,c) = e;
      if( DSU::merge(u,v) )
        total -= c;
    }
    cout<<total<<"\n";
  }
  cin>>cn;
  
  TIMESTAMP("end");
  return 0;
}
