#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

namespace json {
	class IData;
	using Data = std::shared_ptr<IData>;
	using DataVector = std::vector<Data>;
	using DataMap = std::map<std::string, Data>;

	class TypeError : public std::exception {
		using std::exception::exception;
	};

	class IData {
	public:
		IData() = default;

		virtual ~IData() = 0;

		virtual void print(std::ostream& out) const = 0;
		virtual Data clone() const = 0;

		virtual bool isNull() const;
		virtual bool isBoolean() const;
		virtual bool isNumber() const;
		virtual bool isString() const;
		virtual bool isArray() const;
		virtual bool isObject() const;

		virtual bool& getBoolean();
		virtual double& getNumber();
		virtual std::string& getString();
		virtual DataVector& getArray();
		virtual DataMap& getObject();
	};


	template<typename T>
	vector<T> fromJson(Data d, T t) {
		vector<T> temp;

	}
}