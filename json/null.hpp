#pragma once
#include "ivalue.hpp"

namespace json {
	class Null : public IValue {
	public:
		Null() = default;

		void print(std::ostream& out) const override;
		Value clone() const override;

		bool isNull() const override;
	};

	Value toValue();
	extern std::shared_ptr<IValue> null;
}