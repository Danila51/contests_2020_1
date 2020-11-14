#include  <iostream>
#include <set>
#include <unordered_set>
class TimeOfDay {
public:
    uint8_t hour, minute, second;

    TimeOfDay(uint8_t h, uint8_t m, uint8_t s) : hour(h), minute(m), second(s) {
    }

    bool IsAM() const {
        return IsValid() && (hour < 12);
    }

    bool IsPM() const {
        return IsValid() && (hour >= 12);
    }

    bool IsValid() const {
        return (hour < 24) && (minute < 60) && (second < 60);
    }

    bool operator== (const TimeOfDay& t) const {
		return ((hour == t.hour)&&(minute == t.minute)&&(second == t.second));
    }

    bool operator< (const TimeOfDay& t) const {
		if (hour < t.hour) {
			return true;
		}
		else if (hour > t.hour) {
			return false;
		}
		else {
			if (minute < t.minute) {
				return true;
			}
			else if (minute > t.minute) {
				return false;
			}
			else {
				if (second < t.second) {
					return true;
				}
				else {
					return false;
				}
			}
		}
    }
};
namespace std
{
    template<> struct hash<TimeOfDay>
    {
        std::size_t operator()(TimeOfDay const& s) const noexcept
        {
            std::size_t h1 = std::hash<uint8_t>{}(s.hour);
            std::size_t h2 = std::hash<uint8_t>{}(s.minute);
			std::size_t h3 = std::hash<uint8_t>{}(s.second);

            return h1 ^ (h2 << 4) ^ (h3 << 8);
        }
    };
}

int main (){
	TimeOfDay t1(12,20,40);
	TimeOfDay t2(12,20,40);

	std::unordered_set <TimeOfDay> s;
	s.insert(t1);
	if  (s.find(t2) != s.end()) {
		std::cout << 2;
	}
	return 0;
}

