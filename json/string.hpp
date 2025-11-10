#pragma once
#include "iData.hpp"

namespace json {
	class String : public IData {
	public:
		String(std::string s = "");

		void print(std::ostream&) const override;
		Data clone() const override;

		bool isString() const override;
		std::string& getString()override;
	protected:
		std::string data;
	};

	Data toData(std::string s);
	Data toData(const char* charptr);
}