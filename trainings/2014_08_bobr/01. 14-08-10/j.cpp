#define VERBOSE
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
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
#ifdef _DEBUG
#   include <conio.h>
#endif

#ifndef _DEBUG
#   undef VERBOSE
#endif

#define eps      1e-8
#define inf      (1000 * 1000 * 1000)
#define linf     (4LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000)
#define sqr(x)   ((x) * (x))
#define eq(x, y) (((x) > (y) ? (x) - (y) : (y) - (x)) <= eps)
#define sz(x)    int((x).size())
#define all(x)   (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()
#define mp       make_pair

using namespace std;

typedef unsigned           uint;
typedef long long          llong;
typedef unsigned long long ullong;
typedef long double        ldouble;
typedef vector<int>        vi;
typedef vector<vi>         vvi;
typedef vector<double>     vd;
typedef vector<vd>         vvd;

struct debug_t {
    template <typename T>
    debug_t& operator<<(const T& value) {
#       ifdef VERBOSE
            cout << value;
#       endif
        return *this;
    }
} debug;

struct Prize {
    bool requirements[30];
    int cash;
};

Prize prizes[10];
int stickers[30];



int main() {
#   ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen(TASK ".in", "r", stdin);
        //freopen(TASK ".out", "w", stdout);  
        //freopen("info.txt", "r", stdin);
        //freopen("info.txt", "w", stdout);
#   else
        freopen("b.in", "r", stdin);
        freopen("b.out", "w", stdout);
#   endif
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL);
    int tests;
    cin >> tests;
    int i, j;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        memset(prizes, 0x00, sizeof prizes);
        for (i = 0; i < n; i++) {
            int rqrCount;
            cin >> rqrCount;
            for (j = 0; j < rqrCount; j++) {
                int x;
                cin >> x;
                prizes[i].requirements[x - 1] = true;
            }
            cin >> prizes[i].cash;
        }
        for (i = 0; i < m; i++)
            cin >> stickers[i];
        
    }
#   ifdef _DEBUG
        _getch();
#   endif
    return 0;
}
