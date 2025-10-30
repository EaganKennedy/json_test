#pragma once
#include "ivalue.hpp"

namespace json {
	class Boolean : public IValue {
	public:
		Boolean(bool b);

		void print(std::ostream&) override;
		Value clone() override;

		bool isBoolean() override;
		bool& getBoolean() override;

	protected:
		bool data;
	};

	Value toValue(bool input);
}