#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cmath>

int translate(std::string a){
	int b = 0;
	int k = 0;
	for (int i = a.size() - 1; i > 0; --i) {
		b += (int(a[i]) - int('0'))  * pow(10, k);
		++k;
	}
	if (a[0]  == '-') {
		b *= -1;
	}
	else {
		b += (int(a[0]) - int('0'))  * pow(10,k);
	}
	return b;
}

int main() {
	std::string buf;
	getline(std::cin,buf);
    std::istringstream ist(buf);
    std::string tmp;
	std::stack<int> ans;
    while ( ist >> tmp ) {
		if (tmp.size() == 1) {
			if ((tmp == "+") || (tmp == "/") || (tmp == "*") || (tmp == "-")) {
				int a = ans.top();
				ans.pop();
				int b = ans.top();
				ans.pop();
				if (tmp == "+"){
					ans.push(a+b);
				}
				else if (tmp == "*") {
					ans.push(a*b);
				}
				else if (tmp == "-") {
					ans.push(b - a);
				}
				else if (tmp == "/") {
					ans.push(b / a);
				}
			}
			else {
				ans.push(translate(tmp));
			}
		}
		else {
			ans.push(translate(tmp));
		}
    }
	std::cout << ans.top();
	return 0;
}
