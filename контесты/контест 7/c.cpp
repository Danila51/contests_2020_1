#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <vector>

using namespace std;

int translate(string a) {
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

template <typename T>
T calculate(char oper, T a, T b) {
	T value;
	if (oper == '+') {
		value = a + b;
	}
	if (oper == '-') {
		value = a - b;
	}
	if (oper == '*') {
		value = a * b;
	}
	if (oper == '/') {
		value = a / b;
	}
	return value;
}

template <typename T>
T max_in_array(vector<T>& v) {
	T tmp = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] > tmp) tmp = v[i];
	}
	return tmp;
}

template <typename T>
T min_in_array(vector<T>& v) {
	T tmp = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] < tmp) tmp = v[i];
	}
	return tmp;
}

int number_of_br (string s){
	int a = 0;
	for (auto i: s) {
		if ((i == ')') || (i == '(')) {
			++a;
		}
	}
	return a;
}

bool good_br (string s) {
	int a = 1;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '(') {
			a++;
		}
		if (s[i] == ')') {
			a--;
		}
		if ((a == 0)&&( i != s.size() - 1)) {
			return false;
		}
	}
	if (a == 0) {
		return true;
	}
	else {
		return false;
	}
}


class Token {
public:
	string st;
	int64_t value;
	int type;  //1 = number, 2 = expression, 3 = unary minus
	bool error = false;
	string error_description;
	char oper;
	vector<int> priority;

	Token(string input) {
		this->st = input;
		set_type();
		if ((error == false) && (type != 1)) {
			if (type == 2) {
				priority.resize(st.size());
				for (int i = 0; i < priority.size(); ++i) {
					priority[i] = 0;
				}
				solve_expression();
				if (error == false) {
					create_new(find_operator());
				}
			}
			else if (type == 3) {
				create_new(0);
			}
			else {
				error = true;
				error_description = "type?";
			}
		}
	}

	void set_type() {
		bool brackets = false;
		while ((st[0] == '(') && good_br(st)) {
			if (st[st.size() - 1] == ')') {
				brackets = true;
				st = {st.begin() + 1, st.end() - 1};
			}
		}
		if (st.size() == 0) {
			error = true;
			error_description = "size = 0";
			return;
		}
		bool number_flag = true;
		int number_of_operators = 0;
		int number_of_left_br = 0;
		int number_of_right_br = 0;
		for (int i = 1; i < st.size(); ++i) {
			if (isdigit(st[i]) != true) {
				number_flag = false;
				if ((st[i] == '+') ||(st[i] == '*') || (st[i] == '-')||(st[i] == '/')) {
					number_of_operators++;
				}
				if (st[i] == ')') {
					number_of_right_br++;
				}
				if (st[i] == '(') {
					number_of_left_br++;
				}
			}
		}
		if (st[0] == '(') {
			number_of_left_br++;
		}
		if (number_of_left_br - number_of_right_br != 0) {
			error = true;
			error_description = "(()";
			return;
		}
		if (number_flag) {
			if (((st[0] == '-') || (isdigit(st[0]))) && (st != "-")  ) {
				value = translate(st);
				type = 1;
				return;
			}
			else {
				error_description = "?1234567890";
				error = true;
			}
		}
		if (number_of_operators >= 1) {
			type = 2;
		}
		if (st[0] == '-') {
			string tmp = {st.begin() +1, st.end()};
			if  ((st[1] == '(') && (st[st.size() - 1] == ')') && good_br(tmp) || (st[1] == '-')) {
				type = 3;
				return;
			}
		}
	}

	void solve_expression() {
		int level_of_brackets = 0;
		for (int i = 0; i < st.size(); ++i) {
			if (st[i] == '(') {
				++level_of_brackets;
				continue;
			}
			if (st[i] == ')') {
				--level_of_brackets;
				continue;
			}
			if (level_of_brackets < 0) {
				error = true;
				error_description = "())(";
				return;
			}
			if (isdigit(st[i]) == false) {
				if (st[i] == '+') {
					priority[i] = 1 + 2 * level_of_brackets;
				}
				if (st[i] == '-') {
					if (i == 0) {
						priority[i] = 0;
					}
					else {
						if ((st[i-1] == '*') || (st[i-1] == '/') || (st[i-1] == '+') ||  (st[i-1] == '-')) {
							priority[i] = 0;
						}
						else {
							priority[i] = 1 + 2 * level_of_brackets;
						}
					}
				}
				if ((st[i] == '*') || (st[i] == '/')) {
					priority[i] = 2 + 2 * level_of_brackets;
				}
			}
		}
	}

	int find_operator() {
		int max_item = max_in_array(priority);
		for (int i = 0; i < priority.size(); ++i) {
			if (priority[i] == 0) {
				priority[i] = max_item + 10;
			}
		}
		/*cout << "Priority in: " << st<< "________";
		for (int i = 0; i < priority.size(); ++i) {
			cout << priority[i] << " ";
		}
		cout << endl;*/
		int min_item = min_in_array(priority);
		int index_operator;
		for (int i = priority.size() - 1; i >= 0; --i) {
			if (priority[i] == min_item) {
				index_operator = i;
				break;
			}
		}
		return index_operator;
	}

	void create_new(int index) {
		if (type == 3) {
			string right_str;
			if (st[1] == '(') {
				right_str = {st.begin()+2, st.end() - 1};
			}
			if (st[1] == '-') {
				right_str = {st.begin()+1, st.end()};
			}
			oper = '*';
			Token b(right_str);
			//b.print();
			if (b.error == false) {
				value = (-1) * b.value;
			} else {
				error = true;
				error_description = "unary minus child has error";
			}
			return;
		}
		string left_str = {st.begin(), st.begin() + index};
		string right_str = {st.begin() + index + 1, st.end()};
		oper = st[index];
		Token a(left_str);
		Token b(right_str);
		//a.print();
		//b.print();
		if ((a.error == false) && (b.error==false)) {
			if ((oper == '/') && (b.value == 0)) {
				error = true;
				error_description = "a/0";
			} else {
				value = calculate(oper, a.value, b.value);
			}
		} else {
			error = true;
			error_description = "child has error";
		}
	}

	void print() {
		cout << "st: " << st << " type: " << type << " error: " << error ;
		if (type == 1) {
			cout <<" value: " << value << endl;
		} else {
			cout << endl;
		}
	}
};


bool arifm_string(string s, string allow) {
	for (auto i: s) {
		auto found = allow.find(i);
		if (found == std::string::npos) {
			return false;
		}
	}
	return true;
}

int main() {
	string input;
	string allowed_characters = "+-/*()1234567890";
	getline(cin, input);
	string format_input = "";
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] != ' ') {
			format_input += input[i];
		}
	}
	if (arifm_string(format_input, allowed_characters)) {
		Token a(format_input);
		if (a.error == false) {
			cout << a.value;
		} else {
			cout << "ERROR";
			//cout << endl << a.error_description;
		}
	} else {
		cout << "ERROR";
	}
	return 0;
}
