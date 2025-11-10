#include "idata.hpp"

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
	const bool& IData::getBoolean() const {
		throw TypeError("This object is not a boolean");
	}
	double& IData::getNumber() {
		throw TypeError("This object is not a number");
	}
	const double& IData::getNumber() const {
		throw TypeError("This object is not a number");
	}
	std::string& IData::getString() {
		throw TypeError("This object is not a string");
	}
	const std::string& IData::getString() const {
		throw TypeError("This object is not a string");
	}
	DataVector& IData::getArray() {
		throw TypeError("This object is not an array");
	}
	const DataVector& IData::getArray() const {
		throw TypeError("This object is not an array");
	}
	DataMap& IData::getObject() {
		throw TypeError("This object is not an Object");
	}
	const DataMap& IData::getObject() const {
		throw TypeError("This object is not an Object");
	}

	std::ostream& operator<<(std::ostream& out, const Data& rhs) {
		rhs->print(out);
		return out;
	}
	std::ostream& operator<<(std::ostream& out, const IData& rhs) {
		rhs.print(out);
		return out;
	}
}