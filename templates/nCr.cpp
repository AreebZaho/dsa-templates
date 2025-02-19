// Function for modular exponentiation (base^exp % MOD)
long long modExp(long long base, long long exp, long long mod) {
  long long result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

// Compute nCr % MOD iteratively without precomputing factorials
long long nCr(int n, int r, int mod) {
  if (r > n || r < 0) return 0;

  long long num = 1, den = 1;

  // Compute numerator (n * (n-1) * ... * (n-r+1)) % MOD
  for (int i = 0; i < r; i++) {
    num = (num * (n - i)) % mod;
    den = (den * (i + 1)) % mod; // Compute denominator (r!)
  }

  // Compute modular inverse of denominator
  return (num * modExp(den, mod - 2, mod)) % mod;
}

//-----------------------------------------------OR:
const int MAXN = 1e6; // Adjust based on problem constraints

long long fact[MAXN + 1], invFact[MAXN + 1];

// Function for modular exponentiation (base^exp % MOD)
long long modExp(long long base, long long exp, long long mod) {
  long long result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

// Precompute factorials and inverse factorials
void precomputeFactorials(int n, int mod) {
  fact[0] = invFact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  invFact[n] = modExp(fact[n], mod - 2, mod); // Fermat's theorem for inverse

  // Compute inverse factorials in reverse order
  for (int i = n - 1; i >= 1; i--) {
    invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
  }
}

// Compute nCr % MOD in O(1) using precomputed values
long long nCr(int n, int r, int mod) {
  if (r > n || r < 0) return 0;
  return (fact[n] * invFact[r] % mod * invFact[n - r] % mod) % mod;
}