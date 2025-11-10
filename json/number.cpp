#include "number.hpp"

namespace json {
	Number::Number(double d) {
		data = d;
	}

	void Number::print(std::ostream& out)  const {
		out << data;
	}
	Data Number::clone() const {
		return toData(data);
	}

	bool Number::isNumber() const {
		return true;
	}
	double& Number::getNumber() {
		return data;
	}
	const double& Number::getNumber() const {
		return data;
	}

	Data toData(int i) {
		return std::make_shared<Number>(double(i));
	}
	Data toData(double d) {
		return std::make_shared<Number>(d);
	}

	std::ostream& operator<<(std::ostream& out, const Number& rhs) {
		rhs.print(out);
		return out;
	}
}