int nCr(int n, int r) {
  //nCr = n! / (r! * (n - r)!) = n * (n - 1) * (n - 2) * ... * (n - r + 1) / r!
  if (r > n - r) r = n - r;
  int ans = 1;
  for (int i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}