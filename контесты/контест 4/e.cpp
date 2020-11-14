#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	vector <int> v;
	int k;
	while (true) {
		cin >> k;
		if (k == 0) {
			break;
		}
		if (k > 0) {
			v.push_back(k);
			continue;
		}
		if ((k < 0) && (v.size() != 0)) {
			if (k * k < v[v.size() - 1] * v[v.size() - 1]) {
				v[v.size() - 1] += k;
				continue;
			}
			else {
				v.pop_back();
				continue;
			}

		}
		else {
			continue;
		}

	}
	if (v.size() != 0) {
		cout << v.size() << " " << v[v.size() - 1];
	}
	else {
		cout << 0  << " "<<  -1  ;
	}
	return 0;
}
