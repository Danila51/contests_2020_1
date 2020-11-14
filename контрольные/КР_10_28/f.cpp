#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


using namespace std;

vector<vector<int>> find4(vector<int> &nums, int number) {
	vector<vector<int>> ans;
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n ; ++j) {
			for (int k = j + 1; k < n; ++k) {
				for (int l = k + 1; l < n; ++l) {
					if (nums[l] + nums[k] + nums[i] + nums[j] == number) {
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[k]);
						tmp.push_back(nums[l]);
						sort(tmp.begin(), tmp.end());
						ans.push_back(tmp);
 					}
				}
			}
		}
	}
	set<vector<int>> tmp_set = {ans.begin(), ans.end()};
	vector<vector<int>> ans2 = {tmp_set.begin(), tmp_set.end()};

	return ans2;
}

int main() {
	vector<int> arr;
	int n, num;
	cin >> n;
	for (int i =0; i < n; ++i) {
		int k;
		cin >> k;
		arr.push_back(k);
	}
	cin >> num;
	vector<vector<int>> answer = find4(arr, num);
	for (int i = 0; i < answer.size(); ++i) {
		for (int k = 0; k < 4; ++k ) {
			cout << answer[i][k] << " ";
		}
		cout << endl;
	}
}

