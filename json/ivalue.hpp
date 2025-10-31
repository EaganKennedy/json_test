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
		IValue() = default;

		virtual ~IValue() = 0;

		virtual void print(std::ostream& out) const = 0;
		virtual Value clone() const = 0;

		virtual bool isNull() const;
		virtual bool isBoolean() const;
		virtual bool isNumber() const;
		virtual bool isString() const;
		virtual bool isArray() const;
		virtual bool isObject() const;

		virtual bool& getBoolean();
		virtual double& getNumber();
		virtual std::string& getString();
		virtual ValueVector& getArray();
		virtual ValueMap& getObject();
	};
}