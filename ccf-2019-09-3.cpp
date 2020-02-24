#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

int m, n; /* width, height */
int p, q; /* sub-width, sub-height */
struct Pixel {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

const int maxm = 1920+5;
const int maxn = 1080+5;
Pixel pxl[maxn][maxm]; /* row - col */
string os;

void addbk() {
	os += "\\x20";
}

void addnl() {
	os += "\\x0A";
}

void reset() {
	os += "\\x1B\\x5B\\x30\\x6D";
}

void getbuf(char *buf, unsigned char c) {
	int d;
	char cs[4];
	int nc = 0;
	do{
		cs[nc++] = '0' + c % 10;
	} while(c /= 10);
	
	int bufi = 0;
	for(int i = nc-1; i >= 0; i--) {
		buf[bufi++] = '\\';
		buf[bufi++] = 'x';
		buf[bufi++] = '3';
		buf[bufi++] = cs[i];
	}
	buf[bufi++] = '\0';
}

void chgc(Pixel *p) {
	char buf[16];
	
	os += "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";
	getbuf(buf, p->r);
	os += buf;
	os += "\\x3B";
	getbuf(buf, p->g);
	os += buf;
	os += "\\x3B";
	getbuf(buf, p->b);
	os += buf;
	os += "\\x6D";
}

bool shdreset(Pixel *p) {
	return !p->r && !p->g && !p->b; 
}

bool shdnochg(int r, int c, Pixel *p) {
	if(c == 0 && shdreset(p)) {
		return true;
	} else {
		Pixel *lp = &pxl[r][c-1];
		if(p->r == lp->r && p->g == lp->g && p->b == lp->b) {
			return true;
		}
	}
	return false;
}

int main() {
	//printf("%x", '9');
	//freopen("data.in", "r", stdin);
	scanf("%d%d%d%d", &m, &n, &p, &q);
	char buf[8], *hex;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			Pixel &p = pxl[i][j];
			scanf("%s", buf);
			hex = buf+1;
			int len = strlen(hex);
			if(len == 1) {
				int c;
				sscanf(hex, "%1x", &c);
				p.r = p.g = p.b = c*17;
			} else {
				int r,g,b;
				if(len == 3) {
					sscanf(hex, "%1x%1x%1x", &r, &g, &b);
					r *= 17, g *= 17, b *= 17;
				} else {
					sscanf(hex, "%2x%2x%2x", &r, &g, &b);
				}
				p.r = r;
				p.g = g;
				p.b = b;
			}
		}
	}
	
	int nr = n / q;
	int nc = m / p;
	int area = p*q;
	for(int r = 0; r < nr; r++) {
		for(int c = 0; c < nc; c++) {
			unsigned sr = 0, sg = 0, sb = 0;
			for(int j = 0; j < q; j++) {
				for(int i = 0; i < p; i++) {
					Pixel &cp = pxl[r*q+j][c*p+i];
					sr += cp.r, sg += cp.g, sb += cp.b;
				}
			}
			Pixel &cp = pxl[r][c];
			cp.r = sr / area, cp.g = sg / area, cp.b = sb / area;
		}
	}
	
	for(int r = 0; r < nr; r++) {
		bool neednlreset = false;
		for(int c = 0; c < nc; c++) {
			Pixel *cp = &pxl[r][c];
			//printf("%02x%02x%02x\n", cp->r, cp->g, cp->b);
			if(!shdnochg(r, c, cp)) {
				if(shdreset(cp)) {
					reset();
					neednlreset = false;
				} else {
					chgc(cp);
					neednlreset = true;
				}
			}
			addbk();
		}
		if(neednlreset) {
			reset();
		}
		addnl();
	}
	printf(os.c_str());
}
