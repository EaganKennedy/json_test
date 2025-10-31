#pragma once
#include "ivalue.hpp"

namespace json {
	class Boolean : public IValue {
	public:
		Boolean(bool b);

		void print(std::ostream&) const override;
		Value clone() const override;

		bool isBoolean() const override;
		bool& getBoolean()override;

	protected:
		bool data;
	};

	Value toValue(bool input);
}