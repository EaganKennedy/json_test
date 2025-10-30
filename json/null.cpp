#include "null.hpp"

namespace json {
	bool null::isNull() {
		return true;
	}
	void null::print(std::ostream& out) {
		out << "null";
	}
	Value null::clone() {
		return Null;
	}

	std::shared_ptr<IValue> Null = std::make_shared<null>();
	Value toValue(){
		return Null;
	}
}