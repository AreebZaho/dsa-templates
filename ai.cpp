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
#define sz(x) ((i32)(x).size())
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
void small_line() { cerr << "--------------------\n"; }
void big_line() { cerr << "------------------------------------------\n"; }
template <class T = i64> vector<T> inp(i64 n) { vector<T> v(n); f1(i, 0, n) cin >> v[i]; return v; }
template <class T = i64> vector<vector<T>> inpM(i64 n, i64 m) { vector<vector<T>> v; f1(i, 0, n) v.pb(inp(m)); return v; }
template <class T = i64, class S = i64> vector<pair<T, S>> inpPairs(i64 n) { vector<pair<T, S>> v(n); f1(i, 0, n) { cin >> v[i].ff >> v[i].ss; } return v; }
i64 power(i64 base, i64 exponent) { i64 result = 1; while (exponent > 0) { if (exponent % 2 == 1) { result = (result * base) % MOD; } base = (base * base) % MOD; exponent /= 2; } return result; }
i64 sqrt(i64 x) { i32 i = 0, j = INT_MAX; while (i < j) { i64 mid = (j - i) / 2 + i; if (mid * mid <= x) { i = mid + 1; } else { j = mid; } } return i - 1; }
/********************************************************/

inline void solve() {}
struct Vector2DHash {
  size_t operator()(const vector<vector<int>>& vec2D) const {
    size_t hash = 0;
    std::hash<int> hashFn;
    for (const auto& row : vec2D) {
      size_t rowHash = 0;
      for (int val : row) {
        rowHash ^= hashFn(val) + 0x9e3779b9 + (rowHash << 6) + (rowHash >> 2);
      }
      hash ^= rowHash + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    }
    return hash;
  }
};
class Node {
  public:
  int zero_i, zero_j;
  vector<vector<int>> board;
  unordered_set<Node*> next;
  Node(vector<vector<int>>& board, int zero_i, int zero_j) {
    this->zero_i = zero_i;
    this->zero_j = zero_j;
    this->board = board;
  }
};
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
int n, m, zero_i, zero_j;
unordered_map<vector<vector<int>>, Node*, Vector2DHash> nodes;
vector<vector<int>> board, final_board;
void all_states(int i) {
  if (i == n * m) {
    // dbg(board);
    int zero_i, zero_j;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
      if (board[i][j] == 0) zero_i = i, zero_j = j;
    Node* p;
    if (nodes.find(board) == nodes.end()) {
      nodes[board] = p = new Node(board, zero_i, zero_j);
    } else p = nodes[board];
    for (int k = 0; k < 4; k++) {
      int new_i = zero_i + dx[k], new_j = zero_j + dy[k];
      if (min(new_i, new_j) < 0 || new_i == n || new_j == m) continue;
      swap(board[zero_i][zero_j], board[new_i][new_j]);
      Node* c;
      if (nodes.find(board) == nodes.end()) {
        nodes[board] = c = new Node(board, new_i, new_j);
      } else c = nodes[board];
      swap(board[zero_i][zero_j], board[new_i][new_j]);
      p->next.insert(c);
      c->next.insert(p);
    }
    return;
  }
  int r = i / m, c = i % m;
  // dbg(r, c);
  for (int j = i; j < n * m; j++) {
    int row = j / m, col = j % m;
    // dbg(row, col);
    swap(board[r][c], board[row][col]);
    all_states(i + 1);
    swap(board[r][c], board[row][col]);
  }
}
/********************************************************/
i32 main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("err.txt", "w", stderr);
#endif
  big_line();
  clock_t start = clock();
  cin >> n >> m;
  board = vector<vector<int>>(n, vector<int>(m)),
    final_board = vector<vector<int>>(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) zero_i = i, zero_j = j;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> final_board[i][j];
    }
  Node* root = new Node(board, zero_i, zero_j);
  nodes[board] = root;
  all_states(0);
  dbg(nodes.size());
  // for (auto i : nodes) dbg(i.first);
  small_line();
  unordered_set<Node*> vis, dest = { nodes[final_board] };
  queue<Node*> q;
  q.push(root);
  int levels = 0, total_nodes = 0;
  while (!q.empty()) {
    levels++;
    int sz = q.size();
    // dbg(sz);
    while (sz--) {
      auto t = q.front(); q.pop();
      auto board = t->board; int curr_i = t->zero_i, curr_j = t->zero_j;
      // dbg(curr_i, curr_j);
      // dbg(board);
      if (vis.find(t) != vis.end()) continue;
      total_nodes++;
      vis.insert(t);
      for (auto neighbor : t->next) {
        if (vis.find(neighbor) == vis.end()) q.push(neighbor);
      }
      // small_line();
    }
    // big_line();
  }
  dbg(levels, total_nodes);
  clock_t end = clock();
  cerr << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << "s";
  return 0;
}
