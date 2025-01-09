auto lb = lower_bound(a.begin(), a.end(), make_pair(new_el, 0),
  [] (const pi& a, const pi& b) {
    return a.ff < b.ff;
  });