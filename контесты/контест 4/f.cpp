#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; ++i) {
		int a, c, b;
		cin >> a >> c >> b;
		vec.push_back(make_pair(a,b));
	}
	for (int i = 0; i < n - 1; ++ i) {
		bool sorted = 1;
		for (int j = 0; j < n - 1; ++j) {
			if (vec[j].first > vec[j + 1].first) {
					swap(vec[j + 1], vec[j]);
					sorted = 0;
			}
		}
		if (sorted == 1) break;
	}
	vector<vector<int>> ans;
	ans.resize(1);
	ans[0].resize(3);
	ans[0][0] = vec[0].first;
	ans[0][1] = 1;
	ans[0][2] = vec[0].second;
	for (int i = 1; i < n; ++i) {
		if (vec[i].first == ans[ans.size() - 1][0]) {
			ans[ans.size() - 1][1] += 1;
			ans[ans.size() - 1][2] += vec[i].second;
		}
		else {
			ans.resize(ans.size() + 1);
			ans[ans.size() - 1].resize(3);
			ans[ans.size() - 1][0] = vec[i].first;
			ans[ans.size() - 1][1] = 1;
			ans[ans.size() - 1][2] = vec[i].second;
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
	}
	return 0;
}
