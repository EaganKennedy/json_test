#include "boolean.hpp"

namespace json {
	Boolean::Boolean(bool input) {
		data = input;
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


	Value toValue(bool input){
		return std::make_shared<Boolean>(input);
	}
}