#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string v1, v2;
	cin >> v1 >> v2;
	vector<string> ver1;
	vector<string> ver2;

	int i = 0;
	string temp = "";
	bool flag = 0;


	while(true) {
		if(i == v1.size()) {
			ver1.push_back(temp);
			break;
		}
		if(v1[i] == '.') {
			if (flag == 1) {
				ver1.push_back(temp);
			}
			else {
				temp = '0';
				ver1.push_back(temp);
			}
			flag = 0;
			temp = "";
			++i;
			continue;
		}

		if(int(v1[i]) - int('0') != 0) {
			flag = 1;
		}
		if(flag == 1){
			temp += v1[i];
		}
		++i;
	}

	i = 0;
	flag = 0;
	temp = "";
	while(true) {
		if(i == v2.size()) {
			ver2.push_back(temp);
			break;
		}
		if(v2[i] == '.') {
			if (flag == 1) {
				ver2.push_back(temp);
			}
			else {
				temp = '0';
				ver2.push_back(temp);
			}
			flag = 0;
			temp = "";
			++i;
			continue;
		}

		if(int(v2[i]) - int('0') != 0) {
			flag = 1;
		}
		if(flag == 1){
			temp += v2[i];
		}
		++i;
	}

	int sz = min(ver1.size(), ver2.size());
	for (int k = 0; k <sz; ++k){
			if (ver1[k] < ver2[k]) {
				cout << -1;
				return 0;
			}
			else if (ver1[k] > ver2[k]) {
				cout << 1;
				return 0;
			}
			else if (k == sz - 1){
				cout << 0;
				return 0;
			} else {
				continue;
			}
	}
	return 0;
}
