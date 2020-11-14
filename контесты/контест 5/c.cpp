#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int A, N, M, T, K;
	cin >> A >> N >> M;
	vector<vector<pair<int,char>>> automata;
	for (int i = 0; i < M; ++i) {
		automata.resize(i + 1);
		automata[i].resize(2);
		int a, b;
		char c;
		cin >> a >> b >> c;
		automata[i][0].first = a;
		automata[i][0].second = 'a';
		automata[i][1].first = b;
		automata[i][1].second = c;

	}
	cin >> T;
	vector <int> terminal;
	for (int i = 0; i < T; ++i) {
		int tmp;
		cin >> tmp;
		terminal.push_back(tmp);
	}
	cin >> K;
	vector <string> str;
	for (int i = 0; i < K; ++i) {
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
	}
	vector<bool> ans;
	ans.resize(K);
	for (int i = 0; i < K; ++i) {
		ans[i] = true;
	}

	for (int i = 0; i < K; ++i) {
		int condition = 0;
		for (int j = 0; j < str[i].size(); ++j) {
			if (str[i][j] > char(int('a') + A - 1)) {
				ans[i] = false;
				break;
			}
		}
		if (ans[i] == false) {
			continue;
		}
		for (int j = 0; j < str[i].size(); ++j) {
			bool flag2 = false;
			for (int p = 0; p < M; ++p) {
				if (str[i][j] == automata[p][1].second) {
					if (condition == automata[p][0].first) {
						condition = automata[p][1].first;
						flag2 = true;
						break;
					}
				}
			}
			if (flag2) {
				if (j + 1 == str[i].size()) {
					bool flag1 = false;
					for (int p = 0; p < T; ++p) {
						if (condition == terminal[p]) {
							flag1 = true;
							break;
						}
					}
					if (flag1) {
						ans[i] = true;
					}
					else {
						ans[i] = false;
					}
				}
				continue;
			} else {
				ans[i] = false;
				break;
			}
		}
	}

	for (int i = 0; i < K; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}
