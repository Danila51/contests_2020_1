#include <iostream>
#include <string>
#include <vector>

class Checker {
private:
	std::vector<bool> arr;
	const unsigned int sz = 60000000;
	const unsigned int h[3] = {7, 11, 13};

	unsigned long long int st_hash(std::string s, unsigned int a)
	 {
		unsigned long long int sum = 0;
		for (auto i : s) {
			sum +=  i - 'a' + 1;
			sum *= a;
		}
		return sum;
    }
public:
	Checker() : arr(sz) {}
    void Add(const std::string& s) {
    	for (int i = 0; i < 3; ++i){
			arr[st_hash(s, h[i]) % sz] = true;
    	}
    }
    bool Exists(const std::string& s) {
    	bool flag = true;
    	for (int i = 0; i < 3; ++i) {
			if (arr[st_hash(s, h[i]) % sz] == false) {
				flag = false;
			}
    	}
    	return flag;
    }
};

int main() {
	std::string st1, st2;
	std::cin >> st1 >> st2;
	Checker k;
	k.Add(st1);
	std::cout << k.Exists(st2);
	return 0;
}
