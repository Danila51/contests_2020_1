#include <iostream>
#include <string>
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

double max_in_array(vector<double>& v) {
	double tmp = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] > tmp) tmp = v[i];
	}
	return tmp;
}

double min_in_array(vector<double>& v) {
	double tmp = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] < tmp) tmp = v[i];
	}
	return tmp;
}


int number_of_br (string s){
	int a = 0;
	for (int i =0; i < s.size(); ++i) {
		if ((s[i] == ')') || (s[i] == '(')) {
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
	int value;
	int type;  //1 = number, 2 = expression, 3 = unary minus
	bool error = false;
	bool times;
	char oper;
	vector<double> priority;

	Token(string input, bool times) {
		this->st = input;
		this->times = times;
		priority.resize(st.size());
		for (int i =0; i < st.size(); ++i) {
			priority[i] = 0;
		}
		set_type();
		if ((error == false) && (type != 1)) {
			if (type == 2) {
				solve_expression();
				if (error == false) {
					create_new(find_operator());
				}
			}
			else {
				create_new(0);
			}
		}
	}

	void set_type() {
		bool brackets = false;
		while ((st[0] == '(') && good_br(st)) {
			if (st[st.size() - 1] == ')') {
				brackets = true;
				string tmp = "";
				for (int i = 1; i < st.size() - 1; ++i) {
					tmp += st[i];
				}
				st = tmp;
			}
		}
		if (st.size() == 0) {
			error = true;
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
		}
		if (number_flag) {
			if ((st[0] == '-') || (isdigit(st[0]) ) ) {
				value = translate(st);
				type = 1;
				return;
			}
			else {
				error = true;
				return;
			}
		}
		if (number_of_operators >= 1) {
			type = 2;
		}
		if (st[0] == '-') {
			string tmp = "";
			for (int i = 1; i < st.size(); ++i) {
				tmp+=st[i];
			}
			if  ((st[1] == '(') && (st[st.size() - 1] == ')') && good_br(tmp)) {
				type = 3;
				return;
			}
		}
		if ((number_of_operators == 0) && ((number_of_left_br!= 0) || (number_of_right_br != 0)) ) {
			error = true;
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
				return;
			}
			if (isdigit(st[i]) == false) {
				if (st[i] == '+') {
					priority[i] = 1 + 2 * level_of_brackets;
				}
				if (st[i] == '-') {
					if (i == 0) {
						priority[i] = 1;
					}
					else {
						if ((st[i-1] == '*') || (st[i-1] == '/') || (st[i-1] == '-') || (st[i-1] == '+')) {
							priority[i] = 0;
						}
						else if (i  < st.size() - 1) {
							if ((st[i+1] == '(')) {
								priority[i] = 0;
							}
							else {
								priority[i] = 1 + 2 * level_of_brackets;
							}
						}
					}
				}
				if ((st[i] == '*') || (st[i] == '/')) {
					priority[i] = 2 + 2 * level_of_brackets;
				}
			}
		}
		/*cout << "Priority in: " << st<< "________";
		for (int i = 0; i <priority.size(); ++i) {
			cout << priority[i] << " ";
		}
		cout << endl;*/
	}

	int find_operator() {
		double max_item = max_in_array(priority);
		for (int i = 0; i < priority.size(); ++i) {
			if (priority[i] == 0) {
				priority[i] = max_item + 10;
			}
		}

		double min_item = min_in_array(priority);
		int index_operator;
		for (int i = priority.size() - 1; i >=0; --i) {
			if (priority[i] == min_item) {
				index_operator = i;
				break;
			}
		}
		return index_operator;
	}

	void create_new(int index) {
		if (type == 3) {
			string right_str = "";
			for (int i = 2; i < st.size() -1; ++i) {
				right_str += st[i];
			}
			oper = '*';
			Token b(right_str, true);
			//b.print();
			if (b.error == false) {
				value = (-1) * b.value;
			} else {
				error = true;
			}
			return;
		}
		string left_str = "";
		string right_str = "";
		for (int i = 0; i < index; ++i) {
			left_str += st[i];
		}
		for (int i = index + 1; i < st.size(); ++i) {
			right_str += st[i];
		}
		oper = st[index];
		if ((oper == '*') || (oper == '/')) {
			Token a(left_str, true);
			Token b(right_str, true);
			//a.print();
			//b.print();
			if ((a.error == false) && (b.error==false)) {
				if (oper == '+') {
					value = a.value + b.value;
				}
				if (oper == '-') {
					value = a.value - b.value;
				}
				if (oper == '*') {
					value = a.value * b.value;
				}
				if (oper == '/') {
					value = a.value / b.value;
				}
			} else {
				error = true;
			}
		} else {
			Token a(left_str, false);
			Token b(right_str, false);
			//a.print();
			//b.print();
			if ((a.error == false) && (b.error==false)) {
				if (oper == '+') {
					value = a.value + b.value;
				}
				if (oper == '-') {
					value = a.value - b.value;
				}
				if (oper == '*') {
					value = a.value * b.value;
				}
				if (oper == '/') {
					value = a.value / b.value;
				}
			} else {
				error = true;
			}
		}

	}

	void print() {
		cout << "st: " << st << " type: " << type << " error: " << error << endl;
	}

};


bool arifm_string(string s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != '+') {
			if (s[i] != '-') {
				if (s[i] != '*') {
					if (s[i] != '/') {
						if (s[i] != '(') {
							if (s[i] != ')') {
								if ((int(s[i]) - int('0') < 0) || (int(s[i]) - int('0') > 9)){
									return false;
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}

int main() {
	string input;
	getline(cin, input);
	//input = "-(1 + 1)";
	string format_input = "";
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] != ' ') {
			format_input += input[i];
		}
	}
	if (arifm_string(format_input)) {
		Token a(format_input, false);
		//cout << "type: " << a.type <<endl;
		if (a.error == false) {
			cout << a.value;
		} else {
			cout << "ERROR";
		}
	} else {
		cout << "ERROR";
	}
	return 0;
}
