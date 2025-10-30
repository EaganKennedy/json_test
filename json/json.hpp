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

	class IValue {
	public:
		IValue() = delete;

		virtual ~IValue() = 0;
	};
}