#include <iostream>
#include <string>
#include <vector>

std::vector<std::pair<double, double>> f(std::vector<std::pair<double, double>> &arr){
	std::vector<std::pair<double, double>> ans;
	ans.resize(1);
	ans[0] = arr[0];
	for(int i = 1; i < arr.size(); ++i) {
		if (arr[i].first > ans[ans.size() - 1].second) {
			ans.push_back(arr[i]);
			continue;
		}
		if(arr[i].second <= ans[ans.size() - 1].second){
			continue;
		}
		if(arr[i].second > ans[ans.size() - 1].second) {
			ans[ans.size() - 1].second = arr[i].second;
		}
	}
	return ans;
}

int main(){
	std::vector<std::pair<double, double>> arr;
	arr.resize(5);
	arr[0] = std::make_pair(1,3);
	arr[1] = std::make_pair(2,6);
	arr[2] = std::make_pair(5,10);
	arr[3] = std::make_pair(15,18);
	arr[4] = std::make_pair(16,17);
	std::vector<std::pair<double, double>> arr2 = f(arr);
	for(int i =0; i < arr2.size(); ++i) {
		std::cout << arr2[i].first << " " << arr2[i].second << std::endl;
	}
	return 0;
}



