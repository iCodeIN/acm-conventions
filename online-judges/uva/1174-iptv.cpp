#include <bits/stdc++.h>

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

int offer(map<string,int>& ntoi, vector<string>& iton, string& name, int& cnt) {
  if( ntoi.count(name) )
    return ntoi[name];
  iton[cnt] = name;
  return ntoi[name] = cnt++;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int cn; cin>>cn;
  forn(ci,cn) {
    int n,m; cin>>n>>m;
    vector< vector< pair<int,int> > > g(n);
    map<string,int> ntoi;
    vector<string> iton(n);
    int cnt = 0;
    forn(edge,m) {
      string a,b; cin>>a>>b;
      int u = offer(ntoi, iton, a, cnt);
      int v = offer(ntoi, iton, b, cnt);
      int cost; cin>>cost;
      g[u].pb(mp(v,cost));
      g[v].pb(mp(u,cost));
    }
    vi dist(n,inf), used(n);
    dist[0] = 0;
    priority_queue< pair<int,int> > pq;
    pq.push(mp(0,0));
    int result = 0;
    while( !pq.empty() ) {
      int u = pq.top().second, ud = -pq.top().first;
      pq.pop();
      if( dist[u] < ud )
        continue;
      used[u] = 1;
      forn(i,sz(g[u])){
        int v = g[u][i].first, cost = g[u][i].second;
        if( !used[v] && dist[v] > cost ) {
          if( dist[v] != inf )
            result -= dist[v];
          dist[v] = cost;
          result += dist[v];
          pq.push(mp(-dist[v], v));
        }
      }
    }
    if( ci )
      cout<<"\n";
    cout<<result<<"\n";
  }
  
  TIMESTAMP("end");
  return 0;
}
