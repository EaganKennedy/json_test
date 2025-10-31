#include "null.hpp"

namespace json {

	void null::print(std::ostream& out) const {
		out << "null";
	}
	Value null::clone() const {
		return Null;
	}

	bool null::isNull() const {
		return true;
	}

	std::shared_ptr<IValue> Null = std::make_shared<null>();
	Value toValue(){
		return Null;
	}
}