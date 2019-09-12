#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	set<unsigned long long> q;
	q.insert(1);
	vector<unsigned long long> u;
	while(u.size() < 1500) {
		int t = *(q.begin());
		q.erase(q.begin());
		q.insert(t * 2);
		q.insert(t * 3);
		q.insert(t * 5);
		u.push_back(t);
		//cout << "(" << t << ")" << endl;
	}

	printf("The 1500'th ugly number is %d.\n", u[u.size()-1]);
	return 0;
}
