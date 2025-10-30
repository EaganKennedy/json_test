#pragma once
#include "ivalue.hpp"

namespace json {
	class null : public IValue {
	public:
		null() = default;

		bool isNull() override;
		void print(std::ostream& out) override;
		Value clone() override;
	};

	Value toValue();
	extern std::shared_ptr<IValue> Null;
}