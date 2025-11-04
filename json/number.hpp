#pragma once
#include "idata.hpp"

namespace json {
	class Number : public IData {
	public:
		Number(double d = 0);

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