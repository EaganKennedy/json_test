#pragma once
#include "idata.hpp"

namespace json {
	class Null : public IData {
	public:
		Null() = default;

		void print(std::ostream& out) const override;
		Data clone() const override;

		bool isNull() const override;
	};

	Data toData();

	std::ostream& operator<<(std::ostream& out, Null const& rhs);
}