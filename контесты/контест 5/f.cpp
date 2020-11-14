#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

bool item_in_array(int a, vector<int>& t) {
	for (int i = 0; i < t.size(); ++i) {
		if (a == t[i]) return true;
	}
	return false;
}
int index ;
bool sort_f(pair<int,vector<string>> s1, pair<int,vector<string>> s2) {
	return(s1.second[index] < s2.second[index]);
}

int main() {
	int n, t, l;
	cin >> n >> t >> l;
	index = l;
	vector<int> term;
	vector<string> equal_class;
	equal_class.resize(n);
	for (int i = 0; i < n; ++i) {
		equal_class[i] = "0";
	}
	for (int i = 0; i < t; ++i) {
		int tmp;
		cin >> tmp;
		term.push_back(tmp);
		equal_class[tmp] = "1";
	}
	vector<vector<int>> automata;
	automata.resize(n);
	for (int i = 0; i < n; ++i) {
		automata[i].resize(l);
	}
	for (int i = 0; i < n * l; ++i) {
		int a, b;
		char c;
		cin >> a >> c >> b;
		automata[a][int(c) - int('a')] = b;
	}
	for (int i = 1; i < n; ++i) {
		vector<pair<int,vector<string>>> for_sort;
		for_sort.resize(n);
		for (int j = 0; j < n; ++j) {
			for_sort[j].second.resize(l + 1);
			for_sort[j].first = j;
		}
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < l + 1; ++k) {
				if (k == 0) {
					for_sort[j].second[0] = equal_class[j];
				}
				else {
					for_sort[j].second[k] = equal_class[automata[j][k - 1]];
				}
			}
		}
		cout << "begin" << endl;
		for (int j = 0; j < n; ++j) {
			cout << for_sort[j].first << " : ";
			for (int k = 0; k < l + 1; ++k) {
				cout  << for_sort[j].second[k] << " ";
			}
			cout << endl;
		}
		cout << "prepare:" << endl;
		for (int k = 0; k < l + 1; ++k) {
			sort(for_sort.begin(),for_sort.end(), sort_f);
			--index;
		}
		for (int j = 0; j < n; ++j) {
			cout << for_sort[j].first << " : ";
			for (int k = 0; k < l + 1; ++k) {
				cout  << for_sort[j].second[k] << " ";
			}
			cout << endl;
		}
		cout << "end" << endl;
		equal_class[for_sort[0].first] += "0";
		int cl = 0;
		for (int j = 1;j < n; ++j) {
			if (for_sort[j] == for_sort[j-1]) {
				equal_class[for_sort[j].first] += char(int('0') + cl);
			}
			else {
				++cl;
				equal_class[for_sort[j].first] += char(int('0') + cl);
			}
		}
	}
	for (int i = 0; i < equal_class.size(); ++i) {
		cout << equal_class[i] << " ";
	}
	return 0;
}
