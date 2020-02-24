#include <stdio.h>
#include <algorithm>


using namespace std;

const int maxn = 1000 + 5; /* max tree numbers */
const int maxm = 1000 + 5; /* max rounds */

int M, N;
int remainedall, maxrmid, maxrm;
int oricur;
int cur;


int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= M; j++) {
			if(j == 0) {
				scanf("%d", &cur); /* set init */ 
				oricur = cur;
			} else {
				int rm; /* <= 0 */ 
				scanf("%d", &rm);
				cur += rm;
			}
		}
		int rmsum = oricur - cur;
		remainedall += cur;
		if(rmsum > maxrm) {
			maxrm = rmsum;
			maxrmid = i+1;
		}
	}
	printf("%d %d %d", remainedall, maxrmid, maxrm);
}
