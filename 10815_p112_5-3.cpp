#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	set<string> dic;
	string s;
	while(cin >> s) {
		string s2;
		for(int i = 0; i < s.length(); i++) {
			if(isalpha(s[i])) {
				s[i] = tolower(s[i]);
			} else {
				s[i] = ' ';
			}
		}
		istringstream ss(s);
		while(ss >> s2)
			dic.insert(s2);
	} 
	
	for(set<string>::iterator it = dic.begin(); it != dic.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}
