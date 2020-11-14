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

bool word_cheker(int a, int n, int m, int t, vector<vector<vector<int>>>& automat, vector<int>& term, string word, int cond) {
	int condition = cond;
	for (int i = 0; i < word.size(); ++ i) {
		if (word[i] - 'a' >= a) {
			return false;
		}
	}
	if (word.size() == 1) {
		for (int r = 0; r < automat[condition][int(word[0]) - int('a')].size(); ++ r) {
			if (item_in_array(automat[condition][int(word[0]) - int('a')][r], term)) {
				return true;
			}
		}
		return false;
		} else {
		string new_word = "";
		for (int r = 1; r < word.size(); ++r) {
			new_word += word[r];
		}
		bool flag1 = false;
		for (int r = 0; r < automat[condition][int(word[0]) - int('a')].size(); ++r) {
			if (word_cheker(a, n,m,t, automat,term,new_word, automat[condition][int(word[0]) - int('a')][r])) {
				flag1 = true;
			}
		}
		return flag1;
	}
}


int main() {
	int A, N, M, T, K;
	cin >> A >> N >> M;
	vector<vector<vector<int>>> automata;
	automata.resize(N);
	for (int i = 0; i < N; ++i) {
		 automata[i].resize(A);
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		automata[a][int(c) - int('a')].push_back(b);
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
		ans[i] = word_cheker(A,N,M,T,automata, terminal,str[i], 0);
	}

	for (int i = 0; i < K; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}

