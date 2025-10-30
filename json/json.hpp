#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

namespace json {
	class IValue;
	using Value = std::shared_ptr<IValue>;
	using ValueVector = std::vector<Value>;
	using ValueMap = std::map<std::string, Value>;

	class TypeError : public std::exception {
		using std::exception::exception;
	};

	class IValue {
	public:
		IValue() = delete;

		virtual ~IValue() = 0;

		virtual void print(std::ostream& out) = 0;
		virtual Value clone() = 0;

		virtual bool isNull();
		virtual bool isBoolean();
		virtual bool isNumber();
		virtual bool isString();
		virtual bool isArray();
		virtual bool isObject();

		virtual bool& getBool();
		virtual double& getNumber();
		virtual std::string getString();
		virtual ValueVector& getArray();
		virtual ValueMap& getObject();
	};
}