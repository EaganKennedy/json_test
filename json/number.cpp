#include "number.hpp"

namespace json {
	Number::Number(double d) {
		data = d;
	}

	void Number::print(std::ostream& out) {
		out << data;
	}
	Value Number::clone() {
		return toValue(data);
	}

	bool Number::isNumber() {
		return true;
	}
	double& Number::getNumber() {
		return data;
	}

	Value toValue(int i) {
		return std::make_shared<Number>(double(i));
	}

	Value toValue(double d) {
		return std::make_shared<Number>(d);
	}
}