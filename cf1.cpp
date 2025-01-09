#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define u32 uint32_t
#define u64 uint64_t
#define f32 float
#define f64 double
#define f80 long double
typedef vector<i64> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<i64, i64> pi;
typedef tuple<i64, i64, i64> ti;
typedef pair<char, char> pc;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename S> void smin(S& a, const T& b) { if (a > b) a = b; }
template <typename T, typename S> void smax(S& a, const T& b) { if (a < b) a = b; }
const i32 MOD = 1000000007;
#define f1(i, x, y) for (auto i = x; i < y; i++)
#define f1r(i, y, x) for (auto i = y - 1; i >= x; i--)
#define trav(a, x) for (auto &a : x)
#define ff first
#define ss second
#define pb push_back
#define sz(x) ((i64)(x).size())
#define all(x) (x).begin(), (x).end()
#define yes cout << "Yes\n";
#define no cout << "No\n";
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << #__VA_ARGS__ << " ", _print(__VA_ARGS__), cerr << "\n";
#else
#define dbg(...)
#endif
template<typename T>
void _print(T t) { cerr << t; }
template<typename T, typename... Args>
void _print(T t, Args... args) { cerr << t << ", "; _print(args...); }
template<class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template<class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(vector <vector <T>> v) { trav(a, v) { cerr << endl; _print(a); } }
template<class T> void _print(queue <T> v) { queue<T> t; cerr << "[ "; while (!v.empty()) { _print(v.front()); cerr << " "; t.push(v.front()); v.pop(); } cerr << "]"; while (!t.empty()) { v.push(t.front()); t.pop(); } }
template<class T, class V> void _print(priority_queue <T> pq) { queue<int> q; cerr << "[ "; while (!pq.empty()) { _print(pq.top()); q.push(pq.top()); pq.pop(); cerr << " "; } cerr << "]"; while (!q.empty()) { pq.push(q.front()); q.pop(); } }
template<class T> void _print(unordered_set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(unordered_map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
inline void small_line() { cerr << "--------------------\n"; }
inline void big_line() { cerr << "------------------------------------------\n"; }
template <class T = i64> vector<T> inp(i64 n) { vector<T> v(n); f1(i, 0, n) cin >> v[i]; return v; }
template <class T = i64> vector<vector<T>> inpM(i64 n, i64 m) { vector<vector<T>> v; f1(i, 0, n) v.pb(inp(m)); return v; }
template <class T = i64, class S = i64> vector<pair<T, S>> inpPairs(i64 n) { vector<pair<T, S>> v(n); f1(i, 0, n) { cin >> v[i].ff >> v[i].ss; } return v; }
i64 power(i64 base, i64 exponent) { i64 result = 1; while (exponent > 0) { if (exponent % 2 == 1) { result = (result * base) % MOD; } base = (base * base) % MOD; exponent /= 2; } return result; }
i64 sqrt(i64 x) { i32 i = 0, j = INT_MAX; while (i < j) { i64 mid = (j - i) / 2 + i; if (mid * mid <= x) { i = mid + 1; } else { j = mid; } } return i - 1; }
/********************************************************/
inline void solve() {
  int n; cin >> n;
  vi v = inp(n);
  if (n <= 2) {
    if (n == 2 && v[0] > v[1]) cout << "NO\n";
    else cout << "YES\n";
    return;
  }
  vi d;
  for (int i = 0; i < n - 1; i++) {
    d.pb(v[i + 1] > v[0]);
  }
  int s = 0;
  for (int i = 0, j; i < n; i++) {
    j = i;
    while (j + 1 < n && d[j] == d[j + 1]) j++;
  }
}
/********************************************************/
i32 main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("err.txt", "w", stderr);
#endif
  clock_t start = clock();
  big_line();
  i32 t = 1;
  cin >> t;
  while (t--) {
    solve();
    big_line();
  }
  clock_t end = clock();
  cerr << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "s";
  return 0;
}
