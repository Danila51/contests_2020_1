#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<vector<int>> find3(vector<int> &nums) {
	map<int, pair<bool,int>> m;

 	for (int i = 0; i < nums.size(); ++i) {
		m[nums[i]].first = true;
		m[nums[i]].second = 0;
 	}
 	for (int i = 0; i < nums.size(); ++i) {
		++m[nums[i]].second;
 	}
 	set<vector<int>> s;
 	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (m[0 - nums[i] - nums[j]].first == true) {
				if (nums[i] == nums[j]) {
					if (nums[i] == 0) {
						if (m[0].second < 3) {
								continue;
						}

					}
				}
				if (((0 - nums[i] - nums[j] == nums[i]) || (0 - nums[i] - nums[j] == nums[j])) && (m[0 - nums[i] - nums[j]].second < 2)) {
					continue;
				}
				vector<int> arr;
				arr.resize(3);
				arr[0] = nums[i];
				arr[1] = nums[j];
				arr[2] = 0 - nums[i] - nums[j];
				if (arr[0] > arr[1]) {
					swap(arr[0],arr[1]);
				}
				if (arr[1] > arr[2]) {
					swap(arr[1],arr[2]);
				}
				if (arr[0] > arr[1]) {
					swap(arr[0],arr[1]);
				}
				s.insert(arr);
			}
		}
 	}
 	vector<vector<int>> ans = {begin(s),end(s)};
 	return ans;
}

int main() {
	vector<int> arr;
	int n;
	cin >> n;
	for (int i =0; i < n; ++i) {
		int k;
		cin >> k;
		arr.push_back(k);
	}
	vector<vector<int>> rrr = find3(arr);
	for (int i = 0; i < rrr.size(); ++i) {
		cout << rrr[i][0] << " " << rrr[i][1] << " " << rrr[i][2] << " ";
	}
}

