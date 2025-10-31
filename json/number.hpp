#pragma once
#include "iData.hpp"

namespace json {
	class Number : public IData {
	public:
		Number(double d);

		void print(std::ostream& out) const override;
		Data clone() const override;

		bool isNumber() const override;
		double& getNumber()override;

	protected:
		double data;
	};

	Data toData(int i);
	Data toData(double d);

}