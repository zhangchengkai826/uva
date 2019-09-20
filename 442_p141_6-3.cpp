#include <iostream>
#include <map>
#include <stack>
using namespace std;

struct Matrix{
	int nr;
	int nc;
}; 

int n;
map<char, Matrix> m;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	cin >> n;
	for(int i = 0; i < n; i++) {
		char c;
		Matrix mat;
		cin >> c >> mat.nr >> mat.nc;
		m[c] = mat;
	}
	
//	cout << m.size();
	
	string s;
	while(getline(cin, s)) {
		if(!s.length())
			continue;
		int cnt = 0;
		stack<Matrix> st;
		for(int i = 0; i < s.length(); i++) {
			switch(s[i]) {
				case '(': {
					break;
				}
				case ')': {
					Matrix mr = st.top();
					st.pop();
					Matrix ml = st.top();
					st.pop();
					Matrix r;
					if(ml.nc != mr.nr) {
						cout << "error" << endl;
						goto lbl_end;
					}
					cnt += ml.nr * ml.nc * mr.nc;
					r.nr = ml.nr; r.nc = mr.nc;
					st.push(r); 
					break;
				}
				default: {
					st.push(m[s[i]]);
					break;
				}
			}
		}
		cout << cnt << endl;
lbl_end:;
	}

	return 0;
}
