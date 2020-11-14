#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set<string> S;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			temp[j] = tolower(temp[j]);
		}
		S.insert(temp);
	}
	string *arr = new string [S.size()];
	int k = 0;
	for(auto i : S) {
        arr[k] = i;
        k++;
	}
	for (int i = S.size() - 1; i >= 0; --i) {
		cout << arr[i] << " ";
	}
	delete [] arr;
    return 0;
}
