#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>

int raz (int a) {
	int k = 0;
	while (a != 0) {
		a /= 10;
		++k;
	}
	return k;

}
int hash_func(int key, int m) {
	int h = 2139062143;
	int r = raz(key);
	for (int i = 0; i < r; ++i) {
		h = 37 * h + key % 10;
		key /= 10;
	}
	return h % m;
}

int hash_size(int m) {
	int k = 0;
	while (k < m) {
		k
	}

}


using namespace std;
int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<vector<pair<int, uint64_t>>>> table;
	table.resize(n);
	for (int i = 0; i < n; ++i) {
		table[i].resize(2*m);
	}
	for (int i = 0; i < m; ++i) {
		int index, key;
		uint64_t value;
		char op;
		cin >> index >> op >> key >> value;
		if (op == '+') {
			int id = hash_func(key,2* m);
			bool flag = true;
			for (int k = 0; k < table[index][id].size(); ++k) {
				if (table[index][id][k].first == key) {
					table[index][id][k].second = value;
					flag = false;
					break;
				}
			}
			if (flag) {
				table[index][id].push_back(make_pair(key, value));
			}
		}
		if (op == '-') {
			int id = hash_func(key, 2 *m);
			for (int k = 0; k < table[index][id].size(); ++k) {
				if (table[index][id][k].first == key) {
					table[index][id].erase(table[index][id].begin() + k);
					break;
				}
			}
		}
		if (op == '?') {
			int id = hash_func(key, 2 *m);
			bool flag = true;
			for (int k = 0; k < table[index][id].size(); ++k) {
				if (table[index][id][k].first == key) {
					cout << table[index][id][k].second << endl;
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << value << endl;
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
			cout << "i: " << i << endl;
		for (int j = 0; j < m; ++j) {
			cout << "j: " << j << endl;
			for (auto it = table[i][j].begin(); it != table[i][j].end(); ++it)
			  {
				  cout << it->first << " : " << it->second << " ;;; ";
			  }
		}
	}*/




	return 0;
}
