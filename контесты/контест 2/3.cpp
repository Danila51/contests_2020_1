#include <iostream>
#include <string>
using namespace std;

int main(){
	string input_string;
	cin >> input_string;
	int answer = 0;
	char first = 'L';
	char second = 'R';
	int first_number = 0;
	int second_number = 0;

	for (int i = 0; i < input_string.size(); ++i){
		char temp = input_string[i];
		if (temp == first) {
			++first_number;
		}
		if (temp == second) {
			++second_number;
		}
		if ((first_number != 0) && (first_number == second_number)) {
			first_number = 0;
			second_number = 0;
			++answer;
		}
	}

	cout << answer << endl;
	return 0;
}
