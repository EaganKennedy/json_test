#pragma once
#include "iData.hpp"

namespace json {
	class Null : public IData {
	public:
		Null() = default;

		void print(std::ostream& out) const override;
		Data clone() const override;

		bool isNull() const override;
	};

	Data toData();
	extern std::shared_ptr<IData> null;
}