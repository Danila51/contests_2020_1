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


void rabin_karp(string key, string word, vector<int>& ans) {
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
}


int main()
{
    string key, word;
    cin >> key >> word;
	vector<int> ans;
	rabin_karp(key, word, ans);
	if (ans.size() == 0) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
    return 0;
}
