

#include <iostream>
using namespace std;

class Fraction {
private:
    // Do NOT rename
    int64_t numerator;
    uint64_t denominator;

    // Do NOT delete
    template < class T >
    friend bool operator==(const Fraction& lhs, const T& rhs);

public:
    Fraction() = delete;
    Fraction(const Fraction& rhs) {
		numerator = rhs.numerator;
		denominator = rhs.denominator;
    };
    Fraction& operator=(const Fraction& rhs) {
		numerator = rhs.numerator;
		denominator = rhs.denominator;
		return *this;
    };
    Fraction(int64_t numerator, uint64_t denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
		reduce();
	};
    //  Add operator overloads below
    void reduce() {
    	if (numerator == 0){}
    	else{
			int64_t k = NODplus(numerator, denominator);
			numerator /= k;
			denominator /= k;
    	}
    }
    Fraction& operator+(const Fraction& a) {
    	uint64_t den = NOK(this->denominator, a.denominator);
		uint64_t b = den / this->denominator;
		uint64_t c = den / a.denominator;
		int64_t num = this->numerator * b + a.numerator * c;
		return *new Fraction(num, den);
	}
	Fraction& operator-(const Fraction& a) {
		uint64_t den = NOK(this->denominator, a.denominator);
		uint64_t b = den / this->denominator;
		uint64_t c = den / a.denominator;
		int64_t num = this->numerator * b - a.numerator * c;
		return *new Fraction(num, den);
    }
	Fraction& operator+=(const Fraction& a) {
		uint64_t den = NOK(this->denominator, a.denominator);
		uint64_t b = den / this->denominator;
		uint64_t c = den / a.denominator;
		int64_t num = this->numerator * b + a.numerator * c;
		this->numerator = num;
     	this->denominator = den;
		return *this;
    }
    Fraction& operator-=(const Fraction& a) {
		uint64_t den = NOK(this->denominator, a.denominator);
		uint64_t b = den / this->denominator;
		uint64_t c = den / a.denominator;
		int64_t num = this->numerator * b - a.numerator * c;
		this->numerator = num;
     	this->denominator = den;
		return *this;
    }
    Fraction& operator-() { return *new Fraction(-numerator, denominator); }

    Fraction& operator*(const Fraction& a) {
    	Fraction n1(this->numerator, a.denominator);
    	Fraction n2(a.numerator, this->denominator);
		int64_t num = n1.numerator * n2.numerator;
     	uint64_t den = n2.denominator* n1.denominator;
		return *new Fraction(num, den);
    }
    Fraction& operator*=(const Fraction& a) {
    	Fraction n1(this->numerator, a.denominator);
    	Fraction n2(a.numerator, this->denominator);
    	this->numerator = n1.numerator * n2.numerator;
     	this->denominator = n2.denominator * n1.denominator;
		return *this;
    }
    uint64_t NOD(uint64_t a, uint64_t b) {
		return ((b == 0) ? (a) : NOD(b, a % b));
	}
	uint64_t NOK(uint64_t n1, uint64_t n2) {
		return n1 * (n2 / NOD(n1, n2));
	}
	int64_t NODplus(int64_t a, uint64_t b) {
		a = a > 0 ? a : -a;
		return (a==0) ? b: NODplus(b % a, a);
	}
};


int main() {
	Fraction f1(1, 4);
	Fraction f2(2, 4);
	Fraction f4(2, 5);
	Fraction f3 = f1+f2;
	f3.print();
	f3 *= f4;
	f3.print();
	return 0;
}

	void print() {
		cout << numerator << " " << denominator;
	}
