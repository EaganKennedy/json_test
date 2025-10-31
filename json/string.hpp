#pragma once
#include "ivalue.hpp"

namespace json {
	class String : public IValue {
	public:
		String(std::string s);

		void print(std::ostream&) const override;
		Value clone() const override;

		bool isString() const override;
		std::string& getString()override;
	protected:
		std::string data;
	};

	Value toValue(std::string s);
	Value toValue(const char* charptr);
}