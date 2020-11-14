#include <iostream>
#include <string>
using namespace std;

int main(){
	string a, b, c;
	cin >> a >> b;
	c = "";

	int as = a.size();
	int bs = b.size();
	if (as > bs) {
		swap(as,bs);
		swap(a, b);
	}

	int d = 0;
	int j = bs - 1;

	for (int i = as - 1; i >=0; --i){
		int temp = int(a[i] - '0') + int(b[j]- '0') + d;
		c = char(int('0') + temp % 2) + c;
		d = temp / 2;
		--j;
	}
	if (d == 1) {
		c = '1' + c;
	}
	cout << c;
    return 0;
}
