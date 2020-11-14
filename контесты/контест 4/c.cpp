#include <iostream>
using namespace std;
int64_t  NOD(int64_t  n1, uint64_t  n2) {
		int64_t div;
		if (n1 >= 0){
			if (n1 == n2)  return n1;
			int d = n1 - n2;
			if (d < 0) {
				d = -d;
				div = NOD(n1, d);
			}
			else {
				div = NOD(n2, d);
			}
			return div;
		}
		else {
			n1*= -1;
			if (n1 == n2){
				return -n1;
			}
			int d = n1 - n2;
			if (d < 0) {
				d = -d;
				div = NOD(n1, d);
			}
			else {
				div = NOD(n2, d);
			}
			return -div;
		}

}
int64_t NODplus(int64_t a, uint64_t b) {
	a = a > 0 ? a : -a;
	return (a==0) ? b: NODplus(b % a, a);
}
int main() {
	cout << NODplus(-5, 5);
	int64_t a = -5;
	int64_t b = 5;
	cout << a /b;
	return 0;
}
