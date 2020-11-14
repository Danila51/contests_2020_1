#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

uint32_t string_hash(string s, vector<uint32_t>& calc) {
    uint32_t sum = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        sum += s[i] * calc[s.size() - 1 - i];
    }
    return sum;
}


int rabin_karp(string key, string word) {
	vector<int> ans;
	uint32_t P = 317;
	int M = key.size();
	vector <uint32_t> calculated_p;
    uint32_t tmp = 1;
    for (int i = 0; i <= M; ++i){
		calculated_p.push_back(tmp);
		tmp *= P;
    }
    uint32_t key_hash = string_hash(key, calculated_p);
    string short_word;
    for (int i = 0; i < M; ++i) {
		short_word += word[i];
    }
    uint32_t word_hash = string_hash(short_word, calculated_p);

    for (int i = M - 1; i < word.size(); ++i) {
		if (word_hash == key_hash) {
			bool flag = true;
			int k = 0;
			for (int j = M - 1; j >= 0; --j) {
				if (key[j] != word[i - M + 1 + j]) {
					flag = false;
					break;
				}
				if (k == 2500) {
					break;
				}
				++k;
			}
			if (flag) {
				ans.push_back(i - M + 1);
			}
		}
		if (i != word.size() - 1) {
			word_hash = word_hash * P - word[i - M + 1] * calculated_p[M] + word[i + 1];
		}
    }
    return ans.size();
}

bool item(string t, vector<string> arr) {
	for (int i = 0; i  < arr.size(); ++ i) {
		if (arr[i] == t) {
			return true;
		}
	}
	return false;
}

int main() {
	string st;
	cin >> st;
	if (st.size() < 10) {
		return 0;
	}
	vector<string> s1;
	for (int i = 0;  i <= st.size() - 10; ++ i) {
		string tmp = {st.begin() + i, st.begin() + i + 10};
		if (rabin_karp(tmp,st) > 1) {
			if (item(tmp,s1) == false) {
				cout << tmp << " ";
				s1.push_back(tmp);
			}
		}
	}
	return 0;
}
/*
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

uint32_t string_hash(string s, uint32_t p) {
    uint32_t sum = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        sum += s[i] pow(p,s.size() - 1 - i);
    }
    return sum;
}


int rabin_karp_word_searcher(string word, int n) {
	vector<uint32_t> table;
	table.resize(word.size() - n + 1);
	uint32_t P = 317;
	uint32_t P_n = pow(P, n);
    string short_word = {word.begin(), word.begin() + n - 1};
    uint32_t word_hash = string_hash(short_word, p);
	table[0] = word_hash;
    for (int i = n; i <= word.size() - 1; ++i) {
		table[i - n + 1] = table[i - n] * P - word[i - n] * P_n + word[i];
    }
    for (int i = 0; i < table.size(); ++i) {
}
}

bool item(string t, vector<string> arr) {
	for (int i = 0; i  < arr.size(); ++ i) {
		if (arr[i] == t) {
			return true;
		}
	}
	return true;
}

int main() {
	string st;
	cin >> st;
	if (st.size() < 10) {
		return 0;
	}
	vector<string> s1;
	for (int i = 0;  i <= st.size() - 10; ++ i) {
		string tmp = {st.begin() + i, st.begin() + i + 9};
		vector<int> ans;
		if (rabin_karp(tmp,st,ans) > 1) {
			if (item(tmp,s1) == false) {
				cout << tmp << " ";
				s1.push_back(tmp);
			}
		}
	}




	return 0;
}

*/
