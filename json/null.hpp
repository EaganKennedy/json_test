#pragma once
#include "ivalue.hpp"

namespace json {
	class null : public IValue {
	public:
		null() = default;

		void print(std::ostream& out) const override;
		Value clone() const override;

		bool isNull() const override;
	};

	Value toValue();
	extern std::shared_ptr<IValue> Null;
}