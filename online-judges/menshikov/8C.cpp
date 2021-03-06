#define VERBOSE
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <fstream>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#ifndef _DEBUG
# undef VERBOSE
#endif
#ifdef NDEBUG
#define VERBOSE
#endif

#define eps 1e-8
#define inf (1000 * 1000 * 1000)
#define linf (4LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000)
#define sqr(x) ((x) * (x))
#define eq(x, y) (((x) > (y) ? (x) - (y) : (y) - (x)) <= eps)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair

using namespace std;

typedef unsigned uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef long double ldouble;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
struct debug_t {
  template <typename T>
  debug_t& operator<<(const T& value) {
# ifdef VERBOSE
    cout << value;
# endif
    return *this;
  }
} debug;

int dfs(vvi& g, vi& s, int v, int player) {
  vi& to = g[v];
  int opponent = player==1?2:1;

  if( sz(to) == 0 ) {
    if( s[v] == 1 )
      return 1;
    if( s[v] == -1 )
      return 2;
    return 0;
  }
  bool win_possible = false;
  bool tie_possible = false;
  for(int i = 0; i < sz(to); i++) {
    int ret = dfs(g,s,to[i],opponent);
    if( ret == player )
      win_possible = true;
    if( ret == 0 )
      tie_possible = true;
  }
  if( win_possible )
    return player;
  if( tie_possible )
    return 0;
  return opponent;
}

int main() {
  //freopen(TASK ".in", "r", stdin);
  //freopen(TASK ".out", "w", stdout);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //freopen("info.txt", "r", stdin);
  //freopen("info.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while( cin >> n ) {

    --n;
    vvi g(n+1); int cnt = 1;
    vi s(n+1); s[0] = 0;

    while( n-- ) {
      char c; cin >> c;
      if( c == 'N' ) {
       int from; cin >> from;
       g[from-1].push_back(cnt);
       s[cnt] = 0;
       ++cnt;
      } else if( c == 'L' ) {
        int from; string cost;
        cin >> from >> cost;
        g[from-1].push_back(cnt);
        if( cost[0] == '-' )
          s[cnt] = -1;
        else if( cost[0] == '+' )
          s[cnt] = 1;
        else
          s[cnt] = 0;
        ++cnt;
      }
    }

    int result = dfs(g,s,0,1);
    if( result == 1 )
      cout << "+1" << "\n";
    else if( result == 2 )
      cout << "-1" << "\n";
    else
      cout << "0" << "\n";
  }


  return 0;
}
