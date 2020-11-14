#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>


using namespace std;


int main() {

	string input;
	getline(cin,input);
	stack<string> row;
	string new_tag = "";
	int level = 0;
	bool tag = false;
	bool in_tag = false;
	bool global_tag = false;
	for (int i = 0; i < input.size(); ++i){
		if ((in_tag == false) && (tag == false)) {
			cout << "NO";
			return 0;
		}
		if (input[i] == '<') {
			tag = true;
			global_tag = true;
			continue;
		}
		if (input[i] == '>') {
			tag = false;
			if (new_tag[0] == '/') {
				--level;
			} else {
				++level;
			}
			if ((level <= 0) && (i != input.size() - 1)) {
				cout << "NO";
				return 0;
			}
			if (!row.empty()) {
				if ("/" + row.top() == new_tag ) {
					row.pop();
				} else {
					row.push(new_tag);
				}
			} else {
				row.push(new_tag);
			}
			new_tag = "";
			continue;
		}
		if (tag) {
			new_tag += input[i];
			continue;
		}
		else {
			continue;
		}
	}
	if (row.empty() && global_tag) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}
