#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <sstream>
using namespace std;


int n, m;
vector<vector<int> > v;
map<string, int> id2s;
int cnt;

int getId(const string &s) {
	if(!id2s.count(s)) {
		id2s[s] = ++cnt;
	}
	return id2s[s];
}

void find() {
	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			map<pair<int, int>, int> mp;
			for(int r = 0; r < n; r++) {
				pair<int, int> p = make_pair(v[r][i], v[r][j]);
				if(mp.count(p)) {
					printf("NO\n");
					printf("%d %d\n", mp[p]+1, r+1);
					printf("%d %d\n", i+1, j+1);
					return;
				}
				mp[p] = r;
			}
		}
	}
	printf("YES\n");
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif	
	
	string s;
	while(getline(cin, s)) {
		istringstream iss(s);
		if(!(iss >> n >> m))
			break;
		
		cnt = 0;
		id2s.clear();
		
		v.resize(n);
		for(int i = 0; i < n; i++) {
			v[i].resize(m);
			getline(cin, s);
			int last_pos = -1;
			for(int j = 0; j < m; j++) {
				int pos = s.find(',', last_pos+1);
				if(pos == string::npos)
					pos = s.length();
				v[i][j] = getId(s.substr(last_pos+1, pos-last_pos-1));
				//cout << "(" << last_pos << ", " << pos << ", "<< s.substr(last_pos+1, pos-last_pos-1) << ", " << v[i][j] << ")\n";
				last_pos = pos;
			}
		}
		find();
		//cout << "(" << v.size() << ", " << v[0].size() << endl;
	}

	return 0;
}
