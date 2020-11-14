#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> v;
	for (int i =0; i < n; ++i){
		int k;
		cin >> k;
		v.push_back(k);
	}
	set <int> s = {begin(v), end(v)};

	vector <int> v2 = {begin(s), end(s)};
	cout << v2.size();
	return 0;
}
