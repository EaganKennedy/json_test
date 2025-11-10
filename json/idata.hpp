#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <type_traits>
#include <ostream>

namespace json {
	class IData;
	using Data = std::shared_ptr<IData>;
	using DataVector = std::vector<Data>;
	using DataMap = std::map<std::string, Data>;

	class TypeError : public std::runtime_error {
	public:
		using std::runtime_error::runtime_error;
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
		virtual const bool& getBoolean() const;
		virtual double& getNumber();
		virtual const double& getNumber() const;
		virtual std::string& getString();
		virtual const std::string& getString()const;
		virtual DataVector& getArray();
		virtual const DataVector& getArray()const;
		virtual DataMap& getObject();
		virtual const DataMap& getObject()const;
	};

	template<typename T>
	void fromJson(Data d, T& t) {
		if constexpr(std::is_same_v <T, int> || std::is_same_v <T, double>) {
			t = d->getNumber();
		}
		else if constexpr(std::is_same_v<T, bool>) {
			t = d->getBoolean();
		}
		else if constexpr(std::is_same_v<T, std::string>) {
			t = d->getString();
		}
	}

	template<typename T>
	void fromJson(const Data& d, std::vector<T>& t) {
		DataVector& dv = d->getArray();
		t.clear();

		for (const auto& item : dv) {
			T temp{};
			fromJson(item, temp);

			t.push_back(std::move(temp));
		}
	}
	template<typename T>
	void fromJson(const Data& d, std::map<std::string, T>& t) {
		DataMap& dm = d->getObject();
		t.clear();

		for (const auto& [key, value] : dm) {
			T temp{};
			fromJson(value, temp);

			t[key] = std::move(temp);
		}
	}

	std::ostream& operator<<(std::ostream& out, Data const& rhs);
	std::ostream& operator<<(std::ostream& out, const IData& rhs);
}