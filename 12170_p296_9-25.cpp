// UVa12170 Easy Climb
// Rujia Liu
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;

const int maxn = 100 + 5;
const int maxx = maxn*maxn*2;
const LL  INF = (1LL << 60);

LL h[maxn], x[maxx], dp[2][maxx];

int main () {
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
  int T;
  cin >> T;
  while(T--) {
    int n;
    LL d;
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> h[i];
    if(abs(h[0] - h[n-1]) > (n-1)*d) {
      cout << "impossible\n";
      continue;
    }

    // useful heights
    int nx = 0;
    for(int i = 0; i < n; i++)
      for(int j = -n+1; j <= n-1; j++) {
      	//cout << "(** " << h[i] + j*d << endl;
        x[nx++] = h[i] + j*d;
			}	
    sort(x, x+nx);
    
    nx = unique(x, x+nx) - x;
//    for(int i = 0; i < nx; i++) {
//    	cout << "(* x[" << i << "]=" << x[i] << endl;
//		}
//		cout << endl << endl;
    
    // dp
    int t = 0;
    for(int i = 0; i < nx; i++) {
      dp[0][i] = INF;
      if(x[i] == h[0]) dp[0][i] = 0;
    }
    /* 
		 * regard dp[t][x] as a function to x, where 0 <= x < nx
     * after 0th round, dp[t][x] is a function that has only 1 point less than INF and all other points equal to INF
     * it's a 'V' shape function (dp[t][x] first increases than decreases when x increases)
     */
    for(int i = 1; i < n; i++) {
    	// in ith round, we calulate dp[t^1][...] considering first (i+1)th mountains using dp[t][...] considering first ith (t) mountains
//    	cout << "(* i=" << i << endl;
      int k = 0;
      for(int j = 0; j < nx; j++) {
//      	cout << "\t(* j=" << j << endl;
//      	for(int m = 0; m < nx; m++) {
//      		if(dp[t][m] != INF) {
//      			cout << "\t\t(* dp[t][" << m << "]=" << dp[t][m] << endl;
//					}		
//				}
        while(k < nx && x[k] < x[j]-d) k++;
        while(k+1 < nx && x[k+1] <= x[j]+d && dp[t][k+1] <= dp[t][k]) k++; // min in sliding window (as dp[t][x] is a 'V' shape function)
//        cout << "\t\t(* k=" << k << endl;
        if(dp[t][k] == INF) dp[t^1][j] = INF; // (t, k) is not reachable
        else dp[t^1][j] = dp[t][k] + abs(x[j] - h[i]);
        // as k only increases in one round, dp[t][k] is a 'V' shape function on variable k
        // as j only increases in one round, abs(x[j] - h[i]) is a 'V' shape function on variable j
        // adding two 'V' shape function still gets a 'V' shape function (f is 'V' shape <-> f' >= 0, (f+g)' = f' + g')
				// so if dp[t][x] is a 'V' shape function on variable x, dp[t^1][x] is a 'V' shape function on variable x 
      }
      t ^= 1;
    }
    for(int i = 0; i < nx; i++)
      if(x[i] == h[n-1]) cout << dp[t][i] << "\n";
  }
  return 0;
}

