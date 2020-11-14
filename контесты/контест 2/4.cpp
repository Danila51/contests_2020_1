#include <iostream>
#include <string>
#include <vector>

std::vector<int> f(std::vector<int>  &arr) {
	int i = arr.size() - 1;
	while (true) {
		if ((i == 0) && (arr[i] == 9)) {
			arr[i] = 0;
			arr.insert(arr.begin(), 1);
			break;
		}
		else if(arr[i] != 9) {
			++arr[i];
			break;
		} else {
			arr[i] = 0;
			--i;
		}
	}
	return arr;
}


int main(){
	std::vector<int> arr{9};
	std::vector<int> arr2 = f(arr);
	std::cout << arr2[0] << arr2[1];
	return 0;
}
