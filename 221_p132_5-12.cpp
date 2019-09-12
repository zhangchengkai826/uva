#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 105
struct Building{
	int id;
	double x, y, w, d, h;
	bool operator<(const Building &b) {
		return (x < b.x) || (x == b.x && y < b.y);
	}
} b[MAX_N];
int n;

double x[2*MAX_N];

bool cover(int i, double mx) {
	//printf("Building %d: (%lf, %lf) covers %lf?", b[i].id, b[i].x, b[i].x + b[i].w, mx);
//	bool res = b[i].x <= mx && b[i].x + b[i].w >= mx;
//	if(res)
//		printf(" YES\n");
//	else
//		printf(" NO\n");
//	return res;
	return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

bool visible(int i, double mx) {
	//printf("is building %d visible on segment %lf?\n", b[i].id, mx);
	if(!cover(i, mx)) {
		//printf("Building %d not cover %lf, segment invisible\n", b[i].id, mx);
		return false;
	}
		
	for(int j = 0; j < n; j++) {
		if(b[j].y < b[i].y && b[j].h >= b[i].h && cover(j, mx)) {
			//printf("Building %d (y: %lf, h: %lf) covered by building %d (y: %lf, h: %lf), segment invisible\n", b[i].id, b[i].y, b[i].h, b[j].id, b[j].y, b[j].h);
			return false;
		} 
	} 
	//printf("segment visible\n", b[i].id, mx);
	return true;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif	
	
	int kase = 0;
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
			x[i*2] = b[i].x; x[i*2+1] = b[i].x + b[i].w;
			b[i].id = i+1;
		}
		sort(b, b+n);
		sort(x, x+2*n);
		int m = unique(x, x+2*n) - x;
//		printf("\nm=%d\n", m);
//		printf("unique x: ");
//		for(int i = 0; i < m; i++) {
//	    	printf("%lf ", x[i]);
//		}
//		printf("\n");
		
		if(kase++)
			printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n%d", kase, b[0].id);
		for(int i = 1; i < n; i++) {
			//printf("\ncheck building %d...\n", b[i].id);
			bool vis = false;
			for(int j = 0; j < m-1; j++) {
				if(visible(i, (x[j] + x[j+1])/2)) {
					vis = true;
					break;
				}
			}
			if(vis) 
				printf(" %d", b[i].id);
		}
		printf("\n");
	}

	return 0;
}

//#include<cstdio>
//#include<algorithm>
//using namespace std;
//
//const int maxn = 100 + 5;
//
//struct Building {
//  int id;
//  double x, y, w, d, h;
//  bool operator < (const Building& rhs) const {
//    return x < rhs.x || (x == rhs.x && y < rhs.y);
//  }
//} b[maxn];
//
//int n;
//double x[maxn*2];
//
//bool cover(int i, double mx) {
//  printf("Building %d: (%lf, %lf) covers %lf?", b[i].id, b[i].x, b[i].x + b[i].w, mx);
//  bool res = b[i].x <= mx && b[i].x+b[i].w >= mx;
//  if(res)
//	printf(" YES\n");
//  else
//	printf(" NO\n");
//  return res;
//}
//
//bool visible(int i, double mx) {
//  printf("is building %d visible on segment %lf?\n", b[i].id, mx);
//  if(!cover(i, mx)) {
//    printf("Building %d not cover %lf, segment invisible\n", b[i].id, mx);
//    return false;
//  }
//  for(int k = 0; k < n; k++) {
//    if(b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx)) {
//      printf("Building %d (y: %lf, h: %lf) covered by building %d (y: %lf, h: %lf), segment invisible\n", b[i].id, b[i].y, b[i].h, b[k].id, b[k].y, b[k].h);
//	  return false;
//	}
//  } 
//  printf("segment visible\n", b[i].id, mx);
//  return true;
//}
//
//int main() {
//	freopen("data.in", "r", stdin);
//  int kase = 0;
//  while(scanf("%d", &n) == 1 && n) {
//    for(int i = 0; i < n; i++) {
//      scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
//      x[i*2] = b[i].x; x[i*2+1] = b[i].x + b[i].w;
//      b[i].id = i+1;
//    }
//    sort(b, b+n);
//    sort(x, x+n*2);
//    int m = unique(x, x+n*2) - x; // x坐标排序后去重，得到m个坐标
//    printf("unique x: ");
//	for(int i = 0; i < m; i++) {
//    	printf("%lf ", x[i]);
//	}
//	printf("\n");
//
//    if(kase++) printf("\n");
//    printf("For map #%d, the visible buildings are numbered as follows:\n%d", kase, b[0].id);
//    for(int i = 1; i < n; i++) {
//      printf("\ncheck building %d...\n", b[i].id);
//      bool vis = false;
//      for(int j = 0; j < m-1; j++)
//        if(visible(i, (x[j] + x[j+1]) / 2)) { vis = true; break; }
//      if(vis) printf(" %d", b[i].id);
//    }
//    printf("\n");
//  }
//  return 0;
//}
