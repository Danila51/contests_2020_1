#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool item_in_array(int a, vector<int>& t) {
	for (int i = 0; i < t.size(); ++i) {
		if (a == t[i]) return true;
	}
	return false;
}

bool word_cheker(int a, int n, int m, int t, vector<vector<vector<int>>>& automat, vector<int>& term, vector<vector<int>>& closed, string word, int cond, bool eps_warp) {
	int condition = cond;
	for (int i = 0; i < word.size(); ++ i) {
		if (word[i] - 'a' >= a) {
			return false;
		}
	}
	if (eps_warp == true) {
		bool flag = false;
		for (int i = 0; i < closed[condition].size(); ++i) {
			if (word_cheker(a, n, m, t, automat, term, closed, word, closed[condition][i], false)) {
				flag = true;
				break;
			}
		}
		if (flag) {
			return true;
		}
	}
	if (word.size() == 1) {
		for (int r = 0; r < automat[condition][int(word[0]) - int('a')].size(); ++ r) {
			int c = automat[condition][int(word[0]) - int('a')][r];
			if (item_in_array(c, term)) {
				return true;
			}
			for (int i = 0; i < closed[c].size(); ++i) {
				if (item_in_array(closed[c][i], term)){
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		string new_word = "";
		for (int r = 1; r < word.size(); ++r) {
			new_word += word[r];
		}
		bool flag1 = false;
		for (int r = 0; r < automat[condition][int(word[0]) - int('a')].size(); ++r) {
			if (word_cheker(a, n, m, t, automat, term, closed, new_word, automat[condition][int(word[0]) - int('a')][r], true)) {
				flag1 = true;
				break;
			}
		}
		return flag1;
	}
}

int main() {
	int A, N, M, T, K;
	cin >> A >> N >> M;
	vector<vector<vector<int>>> automata;
	vector<pair<int,int>> eps;
	automata.resize(N);
	for (int i = 0; i < N; ++i) {
		 automata[i].resize(A);
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		if (c != 'E') {
			automata[a][int(c) - int('a')].push_back(b);
		}
		else {
			eps.push_back(make_pair(a,b));
		}
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
	// end of input

	vector<vector<int>> closed;  // closed[i] is a closure of i - condition
	closed.resize(N);
	for (int i = 0; i < eps.size(); ++i) {
		int a = eps[i].first;
		int b = eps[i].second;
		// a to b
		if (a != b) {
			closed[a].push_back(b);
		}
		for (int j = 0; j < closed[b].size(); ++j) {
			if ((item_in_array(closed[b][j], closed[a]) == false) && (a != closed[b][j])) {
				closed[a].push_back(closed[b][j]);
			}
		}
		for (int j = 0; j < closed.size(); ++j) {
			for (int p = 0; p < closed[j].size(); ++p) {
				if (closed[j][p] == a) {
					for (int k = 0; k < closed[a].size(); ++k) {
						if ((item_in_array(closed[a][k], closed[j]) == false) &&(j != closed[a][k] )) {
							closed[j].push_back(closed[a][k]);
						}
					}
					break;
				}
			}
		}
		/*cout << "i " << i <<endl;
		for (int k = 0; k < closed.size(); ++k) {
		cout << "k= " << k << " closure: ";
		for (int j = 0; j < closed[k].size(); ++j) {
			cout << closed[k][j] << " ";
		}
		cout << endl;
		}
		cout << "PAPA" << endl;*/
	}

	/*for (int i = 0; i < closed.size(); ++i) {
		cout << "i= " << i << " closure: ";
		for (int j = 0; j < closed[i].size(); ++j) {
			cout << closed[i][j] << " ";
		}
		cout << endl;
	}
	cout << "ntcn" << endl;*/

	vector<bool> ans;
	ans.resize(K);

	for (int i = 0; i < K; ++i) {
		ans[i] = word_cheker(A, N, M, T, automata, terminal, closed, str[i], 0, true);
	}

	for (int i = 0; i < K; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}
/*
1
3
2
0 2 a
2 1 E
1
1
1
a


*/
