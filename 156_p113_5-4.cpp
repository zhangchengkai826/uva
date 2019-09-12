#include <bits/stdc++.h>
using namespace std;

struct Stat{
	int x[26];
	Stat() {
		memset(x, 0, sizeof(x));
	}
	bool operator<(const Stat &b) const {
		for(int i = 0; i < 26; i++) {
			if(x[i] < b.x[i])
				return true;
			else if(x[i] > b.x[i])
				return false;
		}
		return false;
	}
	void print() const {
		cout << endl << "( ";
		for(int i = 0; i < 26; i++) {
			cout << x[i] << " ";
		}
		cout << ")" << endl;
	}
};

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	map<Stat, string> m;
	string s;
	while(cin >> s) {
		if(s == "#")
			break;
		Stat st;
		for(int i = 0; i < s.length(); i++) {
			st.x[tolower(s[i]) - 'a']++;
			//st.print();
		}
		if(m.find(st) != m.end()) {
			m[st] = "";
		}	
		else 
			m[st] = s;
	}
	
	set<string> ans;
	for(map<Stat, string>::iterator it = m.begin(); it != m.end(); it++) {
		if(it->second != "")
			ans.insert(it->second);
	}
	
	for(set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
