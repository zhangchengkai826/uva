#include <iostream>
#include <string>
#include <list>

using namespace std;


int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	string s;
	while(getline(cin, s)) {
		list<char> l;
		list<char>::iterator it = l.end();
		for(int i = 0; i < s.length(); ++i) {
			char &c = s[i];
			switch(c) {
				case '[': {
					it = l.begin();
					break;
				} 
				case ']': {
					it = l.end();
					break;
				}
				default: {
					l.insert(it, c);
					break; 
				}
			}
		}
		for(it = l.begin(); it != l.end(); ++it) {
			cout << *it;
		}
		cout << endl;
	}

	return 0;
}
