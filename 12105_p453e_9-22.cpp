// UVa12105 Bigger is Better
// Rujia Liu
// This solution is simpler than the one described in the book

#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 100 + 5;
const int maxm = 3000 + 5;

// dp[i][j=0] is the maximal length of the integer which is the multiple of m (with at most i matches)
// p[i][j] is the maximal most-significant digit for state (i,j)
// dp[i][j] can be regarded as the maximal length of the subpart of some dp[i][j=0]'s integer. the complementary subpart of that integer's remainder is j. (with at most i matches)
int n, m, dp[maxn][maxm], p[maxn][maxm];

int needs[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int main(){
	freopen("data.in", "r", stdin); 
  int kase = 0;
  while(scanf("%d%d", &n, &m) == 2) {
    printf("Case %d: ", ++kase);

    for(int i = 0; i <= n; i++)
      for(int j = 0; j < m; j++){
        int& ans = dp[i][j];
        ans = p[i][j] = -1;
        if (j == 0) ans = 0;
				/* 
				 * initialize: p[i][j] always -1, dp[i][j] = 0 if j == 0 else -1 
				 *             specifically, dp[0][0] = 0 and dp[0][>0] = -1
				 */
				 /* note: d is added on the left */
        for(int d = 9; d >= 0; d--)
          if (i >= needs[d]){
            int t = dp[i - needs[d]][(j * 10 + d) % m];
            if (t >= 0 && t + 1 > ans){
              //printf("\n**(i=%d, j=%d, d=%d, t=%d)**\n", i, j, d, t);
							ans = t + 1;
							//printf("\n**(dp[%d][%d]=dp[%d][%d]+1=%d+1=%d, p[%d][%d]=%d)", i, j, i-needs[d], (j*10+d)%m, t, ans, i, j, d);
              p[i][j] = d;
            }
          }
      }

    if (p[n][0] < 0) printf("-1");
    else {
      int i = n, j = 0;
      for(int d = p[i][j]; d >= 0; d = p[i][j]){
      	//printf("\n**(dp[%d][%d]=%d)**\n", i, j, dp[i][j]);
        printf("%d", d);
        i -= needs[d];
        j = (j * 10 + d) % m;
      }
    }
    printf("\n");
  }
  return 0;
}

