#pragma once
#include "idata.hpp"

namespace json {
	class Boolean : public IData {
	public:
		Boolean(bool b = 0);

		void print(std::ostream&) const override;
		Data clone() const override;

		bool isBoolean() const override;
		bool& getBoolean() override;
		const bool& getBoolean() const override;

	protected:
		bool data;
	};

	Data toData(bool input);
}