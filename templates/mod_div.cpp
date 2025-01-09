i64 gcd(i64 a, i64 b) {
  while (b != 0) {
    i64 temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
i64 modInverse(i64 a, i64 m) {
  i64 m0 = m, t, q;
  i64 x0 = 0, x1 = 1;
  if (m == 1)
    return 0;
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0)
    x1 += m0;
  return x1;
}
long long ab = (static_cast<long long>(a) * b) % m;
i64 inv_ab = modInverse(ab, m);
p = (static_cast<long long>(p) * inv_ab) % m;