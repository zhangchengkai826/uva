#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

int a, b, maxd;

typedef long long LL;

LL gcd(LL a, LL b) {
  return b == 0 ? a : gcd(b, a%b);
}

// ????1/c <= a/b???c
inline int get_first(LL a, LL b) {
  return b/a+1;
}

const int maxn = 100 + 5;

LL v[maxn], ans[maxn];

// ?????v??????ans??,??ans
bool better(int d) {
  for(int i = d; i >= 0; i--) if(v[i] != ans[i]) {
    return ans[i] == -1 || v[i] < ans[i];
  }
  return false;
}

// ?????d,??????from,???????aa/bb
bool dfs(int d, int from, LL aa, LL bb) {
	for(int i = 0; i < d; i++) {
		printf(" ");
	}
	printf("d=%d, from=%d, aa=%lld, bb=%lld\n", d, from, aa, bb);
	
  if(d == maxd) {
//  	for(int i = 0; i < d; i++) {
//			printf(" ");
//		}
//  	printf("%d\n", bb % aa); 
  	
    if(bb % aa) return false; // aa/bb???????
    v[d] = bb/aa;
    if(better(d)) memcpy(ans, v, sizeof(LL) * (d+1));
    return true;
  }
  
  bool ok = false;
  from = max(from, get_first(aa, bb)); // ?????
  for(int i = from; ; i++) {
    // ??:?????maxd+1-d???????1/i,????????aa/bb,???
    if(bb * (maxd+1-d) <= i * aa) break;
    
    v[d] = i;
    
    // ??aa/bb - 1/i,????a2/b2
    LL b2 = bb*i;
    LL a2 = aa*i - bb;
    LL g = gcd(a2, b2); // ????
    
    if(dfs(d+1, i+1, a2/g, b2/g)) ok = true;
  }
  return ok;
}

int main() {
	freopen("data.in", "r", stdin);
	
  int kase = 0;
  while(cin >> a >> b) {
    int ok = 0;
    
    for(maxd = 1; maxd <= 100; maxd++) {
      memset(ans, -1, sizeof(ans));
      printf("maxd=%d\n", maxd);
      if(dfs(0, get_first(a, b), a, b)) { ok = 1; break; }
    }
    
    cout << "Case " << ++kase << ": ";
    if(ok) {
      cout << a << "/" << b << "=";
      for(int i = 0; i < maxd; i++) cout << "1/" << ans[i] << "+";
      cout << "1/" << ans[maxd] << "\n";
    } else cout << "No solution.\n";
  }
  return 0;
}

