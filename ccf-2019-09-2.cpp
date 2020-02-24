#include <stdio.h>
#include <algorithm>


using namespace std;

const int maxn = 1000 + 5; /* max tree numbers */

int N, M;
long long remainedall, droptrn, drop3;
long long oricur;
long long cur;
bool dropn[maxn];

int main() {
	freopen("data.in", "r", stdin);
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		/* for tree i */
		bool drop = false;
		scanf("%d", &M); /* num numbers */
		scanf("%lld", &oricur);
		cur = oricur; /* init */
		for(int j = 2; j <= M; j++) { /* remained ops */
			long long op;
			scanf("%lld", &op);
			if(op > 0) {
				/* re-calc */
				if(op != cur) {
					drop = true; /* drops :( */ 
				}
				cur = op;
			} else {
				cur += op; /* rm */
			}
		}
		remainedall += cur;
		if(drop) {
			droptrn++;
			dropn[i] = true;
		}
	}
	long long ndrop = 0;
	for (int i = 0; i < N; i++) {
		ndrop += (dropn[i] && dropn[(i+1)%N] && dropn[(i+2)%N]);
	}
	printf("%lld %lld %lld", remainedall, droptrn, ndrop);
}
