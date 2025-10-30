#pragma once
#include "ivalue.hpp"

namespace json {
	class Number : public IValue {
	public:
		Number(double d);

		void print(std::ostream& out) override;
		Value clone() override;

		bool isNumber() override;
		double& getNumber() override;

	protected:
		double data;
	};

	Value toValue(int i);
	Value toValue(double d);

}