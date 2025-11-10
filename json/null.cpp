#include "null.hpp"

namespace json {

	void Null::print(std::ostream& out) const {
		out << "null";
	}
	Data Null::clone() const {
		return std::make_shared<Null>();
	}

	bool Null::isNull() const {
		return true;
	}

	//std::shared_ptr<IData> null = std::make_shared<Null>();
	Data toData(){
		return std::make_shared<Null>();
	}

	std::ostream& operator<<(std::ostream& out, const Null& rhs) {
		rhs.print(out);
		return out;
	}
}