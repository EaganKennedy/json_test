#pragma once
#include "iData.hpp"

namespace json {
	class Boolean : public IData {
	public:
		Boolean(bool b);

		void print(std::ostream&) const override;
		Data clone() const override;

		bool isBoolean() const override;
		bool& getBoolean()override;

	protected:
		bool data;
	};

	Data toData(bool input);
}