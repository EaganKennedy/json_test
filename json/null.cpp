#include "null.hpp"

namespace json {

	void Null::print(std::ostream& out) const {
		out << "null";
	}
	Value Null::clone() const {
		return null;
	}

	bool Null::isNull() const {
		return true;
	}

	std::shared_ptr<IValue> null = std::make_shared<Null>();
	Value toValue(){
		return null;
	}
}