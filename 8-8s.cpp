// UVa1471 Defense Lines
// Rujia Liu
// Algorithm 1: use STL set to maintain the candidates.
// This is a little bit more intuitive, but less efficient (than algorithm 2)
#include<cstdio>
#include<set>
#include<cassert>
using namespace std;

const int maxn = 200000 + 5;
int n, a[maxn], f[maxn], g[maxn];

struct Candidate {
  int a, g;
  Candidate(int a, int g):a(a),g(g) {}
  bool operator < (const Candidate& rhs) const {
    return a < rhs.a;
  }
};

set<Candidate> s;

int main() {
	freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    if(n == 1) { printf("1\n"); continue; }

    // g[i] is the length of longest increasing continuous subsequence ending at i
    g[0] = 1;
    for(int i = 1; i < n; i++) {
    	if(a[i-1] < a[i]) g[i] = g[i-1] + 1;
      else g[i] = 1;
		}

    // f[i] is the length of longest increasing continuous subsequence starting from i
    f[n-1] = 1;
    for(int i = n-2; i >= 0; i--) {
    	if(a[i] < a[i+1]) f[i] = f[i+1] + 1;
      else f[i] = 1;
		}
		
		printf("a = [ ");
		for(int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("]\n");
		
		printf("g = [ ");
		for(int i = 0; i < n; i++) {
			printf("%d ", g[i]);
		}
		printf("]\n");
		
		printf("f = [ ");
		for(int i = 0; i < n; i++) {
			printf("%d ", f[i]);
		}
		printf("]\n\n");

    s.clear();
    s.insert(Candidate(a[0], g[0]));
    
    printf("s.insert(%d, %d)\n", a[0], g[0]);
    
    int ans = 1;
    for(int i = 1; i < n; i++) {
    	printf("\n");
    	
      Candidate c(a[i], g[i]);
      
      printf("c = (%d, %d)\n", a[i], g[i]);
      
      set<Candidate>::iterator it = s.lower_bound(c); // first one that is >= c
      
      if(it == s.end()) {
      	printf("it == s.end()\n");
			} else {
				printf("*it = (%d, %d)\n", it->a, it->g);
			}
			
      printf("it != s.begin()...%s\n", it != s.begin() ? "YES" : "NO");
      
			bool keep = true;
      if(it != s.begin()) {
        Candidate last = *(--it); // (--it) points to the largest one that is < c
        
        printf("last = (%d, %d)\n", last.a, last.g);
        
        int len = f[i] + last.g; 
        
        printf("len = %d + %d = %d\n", f[i], last.g, len);
        
        ans = max(ans, len);
        
        printf("ans = %d\n", ans);
        
        
        printf("c.g <= last.g...%s\n", c.g <= last.g ? "YES" : "NO");
        
        if(c.g <= last.g) keep = false;
      }

			printf("keep...%s\n", keep ? "YES" : "NO");
			
      if(keep) {
        s.erase(c); // if c.a is already present, the old g must be <= c.g
        
        printf("s.size() = %d\n", s.size());
        
        s.insert(c);
        it = s.find(c); // this is a bit cumbersome and slow but it's clear    
        it++;
        
        while(it != s.end() && it->g <= c.g) {
        	printf("erasing *it = (%d, %d)\n", it->a, it->g);
        	s.erase(it++);
				}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

