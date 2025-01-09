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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
TreeNode* createTree(vi& v) {
  if (v.empty()) return nullptr;
  TreeNode* root = new TreeNode(v[0]);
  queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (!q.empty() && i < v.size()) {
    TreeNode* curr = q.front();
    q.pop();
    if (v[i] != -1) {
      curr->left = new TreeNode(v[i]);
      q.push(curr->left);
    }
    i++;
    if (i < v.size() && v[i] != -1) {
      curr->right = new TreeNode(v[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}
void printTree(TreeNode* root) {
  if (!root) return;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();
    if (curr) {
      cerr << curr->val << " ";
      q.push(curr->left);
      q.push(curr->right);
    } else {
      cerr << "null ";
    }
  }
  cerr << endl;
}

// int dfsLeftOR(vector<int>& v, int i, int k, int cnt, int val) {
//   if (leftK == 0 && rightK == 0) return leftOR ^ rightOR;
//   if (i == v.size()) return 0;
//   int c = dfs(v, i + 1, leftK, leftOR, rightK, rightOR);
//   int a = 0, b = 0;
//   if (leftK != 0) b = dfs(v, i + 1, leftK - 1, leftOR | v [i], rightK, rightOR);
//   if (rightK != 0) a = dfs(v, i + 1, leftK, leftOR, rightK - 1, rightOR | v [i]);
//   return max({a, b, c});
// }
// int maxValue(vector<int>& v, int k) {
//   dfsLeftOR(v, 0, );
// }
TreeNode* dfs(string s, int* i, int* depth) {
  if (*i == s.length()) return nullptr;
  //always lands at number
  int val = 0;
  while (*i < s.length() && s[*i] != '-') {
    val = val * 10 + s[*i] - '0';
    (*i)++;
  }
  TreeNode* root = new TreeNode(val);
  int d = 0;
  while (*i < s.length() && s[*i] == '-') {
    d++;
    (*i)++;
  }
  if (d > *depth) {
    *depth = d;
    root->left = dfs(s, i, depth);
  }

  if (d == *depth) root->right = dfs(s, i, depth);
  return root;
}
TreeNode* recoverFromPreorder(string traversal) {
  int i = 0, depth = 0;
  return dfs(traversal, &i, &depth);
}
/********************************************************/
i32 main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("err.txt", "w", stderr);
#endif
  big_line();
  // vi v = { 2,6,7 };
  // TreeNode* x = recoverFromPreorder("1-2--3--4-5--6--7");
  // printTree(x);
  // x = recoverFromPreorder("1-2--3---4-5--6---7");
  // printTree(x);

  // dbg(diffWaysToCompute("2-1-1"));

  big_line();
  return 0;
}
