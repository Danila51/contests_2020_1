#include <iostream>
using namespace std;

template<typename T>
class Vector2D {
private:
	T x, y;
public:
    // Конструкторы
    Vector2D() {
		x = 0;
		y = 0;
    }
    Vector2D(T x, T y) {
		setX(x);
		setY(y);
    }

    // Деструктор
    ~Vector2D() {
    }

    // Получение координат
    T getX() const { return x; }
    T getY() const { return y; }

    // Задание координат
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }

    // Перегруженные операторы
    bool operator== (const Vector2D& v2) const {
		if ((v2.x == this->x) && (v2.y == this->y)) {
			return true;
		} else {
			return false;
		}
    }
    bool operator!= (const Vector2D& v2) const {
		if ((v2.x == this->x) && (v2.y == this->y)) {
			return false;
		} else {
			return true;
		}
    }
    Vector2D operator+ (const Vector2D& v2) const  {
    	return Vector2D(v2.x + this->x, v2.y + this->y);
    }
    Vector2D operator- (const Vector2D& v2) const  {
    	return Vector2D(-v2.x + this->x, -v2.y + this->y);
    }
    Vector2D operator* (const T a) const {
    	return Vector2D(a * this->x, a * this->y);
    }
  //friend Vector2D operator* (int a, const Vector2D &v);
	friend std::ostream& operator<< (std::ostream &out, const Vector2D& v);
  friend std::istream& operator>> (std::istream &in, Vector2D& v);
};


// Вот тут возник вопрос
/*// Оператор умножения скаляра на вектор
template<typename T>
Vector2D<T> Vector2D<T>::operator*(int a, const Vector2D &v) {
	return Vector2D(a * v.x, a * v.y);
} */

// Вывод вектора, ожидается строго в формате (1; 1)
template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector2D<T>& v) {
	out << "(" << v.x << ";" << v.y << ")";
	return out;
}

// Чтение вектора, читает просто две координаты без хитростей
template<typename T>
std::istream& operator>> (std::istream &in, Vector2D<T> &v) {
	in >> v.x;
	in >> v.y;
	return in;
}

int main() {
	Vector2D<int> v1;
    std::cin >> v1;
    std::cout << "Read vector: " << v1 << std::endl;
    std::cout << "Vector multiplied by 42: " << v1 * 42 << std::endl;

    Vector2D<double> v2;
    std::cin >> v2;
    std::cout << "Read vector: " << v2 << std::endl;
    std::cout << "Vector multiplied by 42: " << v2 * 42<< std::endl;

	return 0;
}
