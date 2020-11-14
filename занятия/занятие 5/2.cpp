#include <iostream>
#include <string>


template <typename T>
bool check_them(T& x, T& y, T& z) {
	if ((x.id_number_string==y.id_number_string)
		 && (y.id_number_string == z.id_number_string)) {
		return true;
	}
	else {
		return false;
	}
}


struct student {
	std::string name;
	std::string id_number_string;
};

int main() {
	student a = {"Andy", "1234 123123"};
	student b = {"Andrew", "1234 123123"};
	student c = {"Andy", "1234123123"};
	std::cout  << check_them(a, b, c);
	return 0;
}
