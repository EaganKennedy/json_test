#include "boolean.hpp"

namespace json {
	Boolean::Boolean(bool b) {
		data = b;
	}

	void Boolean::print(std::ostream& out) {
		out << data;
	}
	Value Boolean::clone() {
		return toValue(data);
	}

	bool Boolean::isBoolean() {
		return data;
	}
	bool& Boolean::getBoolean() {
		return data;
	}


	Value toValue(bool b){
		return std::make_shared<Boolean>(b);
	}
}