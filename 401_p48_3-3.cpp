#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	string str;
	char ref1[] = "AEHIJLMOSTUVWXYZ12358";
	char ref2[] = "A3HILJMO2TUVWXY51SEZ8";
	while(cin >> str){
		bool isP = true, isM = true;
		/* cout << str.length() << endl; */
		for(int i = 0; i < str.length() / 2 + 1; i++) {
			char left = str[i];
			char right = str[str.length() - i - 1];
			/* cout << left << " -- " << right << endl; */
			if(left != right) {
				isP = false;
			}
			char *p;
			if(p = strchr(ref1, left)) {
				int index = p - ref1;
				if(right != ref2[index]) {
					isM = false;
				}
			} else {
				isM = false;
			}
			if(!isP && !isM)
				break;
		}
		cout << str << " -- ";
		if(!isP && !isM) {
			cout << "is not a palindrome.";
		} else if(isP && isM) {
			cout << "is a mirrored palindrome.";
		} else if(!isP && isM) {
			cout << "is a mirrored string.";
		} else {
			cout << "is a regular palindrome.";
		}
		cout << endl << endl;
	}

	return 0;
}
