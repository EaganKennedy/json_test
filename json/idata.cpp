#include "iData.hpp"

namespace json {
	IData::~IData() = default;

	bool IData::isNull() const{
		return false;
	}
	bool IData::isBoolean() const {
		return false;
	}
	bool IData::isNumber() const {
		return false;
	}
	bool IData::isString() const {
		return false;
	}
	bool IData::isArray() const {
		return false;
	}
	bool IData::isObject() const {
		return false;
	}

	bool& IData::getBoolean() {
		throw TypeError("This object is not a boolean");
	}
	double& IData::getNumber() {
		throw TypeError("This object is not a number");
	}
	std::string& IData::getString() {
		throw TypeError("This object is not a string");
	}
	DataVector& IData::getArray() {
		throw TypeError("This object is not an array");
	}
	DataMap& IData::getObject() {
		throw TypeError("This object is not an Object");
	}
}