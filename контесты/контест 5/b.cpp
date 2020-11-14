#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<vector<pair<int, char>>> arr;
	for (int i = 0; i < 4 * n; ++i) {
		arr.resize(arr.size() + 1);
		arr[i].resize(2);
		cin >> arr[i][0].first >> arr[i][0].second;
		cin >> arr[i][1].first >> arr[i][1].second;
	}
	string input;
	string output = "";
	cin >> input;
	int condition = 1;
	for (int i = 0; i < input.size(); i++){
		for (int j = 0; j < 4 * n; ++j) {
			if (arr[j][1].second == input[i]) {
				if (arr[j][0].first == condition) {
					condition = arr[j][1].first;
					output += arr[j][0].second;
					break;
				}
			}
		}
	}
	cout << output;
	return 0;
}
