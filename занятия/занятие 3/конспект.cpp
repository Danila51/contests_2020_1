#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;


void PrintSet(set <vector<int>> s){
	cout << "Size = " << s.size() << endl;
	for (auto i = s.begin(); i != s.end();++i) {
			for (auto j = 0; j < (*i).size(); ++j) {
				cout << (*i)[j] << " ";
			}
			cout << endl;
	}
}


void PrintVector(vector<int> s){
	cout << "Size = " << s.size() << endl;
	for (auto i : s) {
		cout << i << endl;
	}
}



void PrintMap(map<string, int> m) {
	for (auto i : m) {
		cout << i.first << ": " <<  i.second << endl;
	}

}

map <int, string> ReverseMap (map<string, int> m) {
	map <int, string> result;
	for (auto i : m) {
		result[i.second] = i.first;
	}
	return result;
}

class Student {
	//private;
	public:
	string name;
	int age;
	void PrintSt(){
		cout << name << ", " << age << endl;
	}

	void Set_name(string value) {
		name = value;
	}
	void Set_age(int value) {
		age = value;
	}


};




int raz (int a) {
	int k = 0;
	while (a != 0) {
		a /= 10;
		++k;
	}
	return k;

}
int hash_func(int key, int m) {
	int h = 2139062143;
	int r = raz(key);
	for (int i = 0; i < r; ++i) {
		h = 37 * h + key % 10;
		key /= 10;
	}
	return h % m;
}

int main() {
	/*for (int i =0; i < 100; ++i) {
		cout << hash_func(i, 7) << endl;
	}
	return 0;
}/*	/* vector <int> v={3,7,9,2,-4,3,9};
	set <int> s = {begin(v), end(v)};
	PrintSet(s);
	vector <int> v2={begin(s), end(s)};
	PrintVector(v2);
	*/


	map <int, bool> m;
	m[5] = true;
	m[6] = false;
	vector<int> v1;
	v1.push_back(5);
	v1.push_back(4);
	vector<int> v2;
	v2.push_back(6);
	v2.push_back(0);
	set <vector<int>> st;
		st.insert(v2);

	st.insert(v1);
	PrintSet(st);

/*
	Student st1;
	//st1.age = 17;
	//st1.name = "Nickita";

	st1.PrintSt();*/
	return 0;
}
