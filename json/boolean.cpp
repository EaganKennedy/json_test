#include "boolean.hpp"

namespace json {
	Boolean::Boolean(bool b) {
		data = b;
	}

	void Boolean::print(std::ostream& out)  const {
		out << std::boolalpha << data;
	}
	Data Boolean::clone()  const {
		return toData(data);
	}

	bool Boolean::isBoolean()  const {
		return true;
	}
	bool& Boolean::getBoolean() {
		return data;
	}
	const bool& Boolean::getBoolean() const {
		return data;
	}


	Data toData(bool b){
		return std::make_shared<Boolean>(b);
	}

	std::ostream& operator<<(std::ostream& out, const Boolean& rhs) {
		rhs.print(out);
		return out;
	}
}