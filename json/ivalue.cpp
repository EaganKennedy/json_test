#include "ivalue.hpp"

namespace json {
	IValue::~IValue() = default;

	bool IValue::isNull() {
		return false;
	}
	bool IValue::isBoolean() {
		return false;
	}
	bool IValue::isNumber() {
		return false;
	}
	bool IValue::isString() {
		return false;
	}
	bool IValue::isArray() {
		return false;
	}
	bool IValue::isObject() {
		return false;
	}

	bool& IValue::getBoolean() {
		throw TypeError("This object is not a boolean");
	}
	double& IValue::getNumber() {
		throw TypeError("This object is not a number");
	}
	std::string IValue::getString() {
		throw TypeError("This object is not a string");
	}
	ValueVector& IValue::getArray() {
		throw TypeError("This object is not an array");
	}
	ValueMap& IValue::getObject() {
		throw TypeError("This object is not an Object");
	}
}