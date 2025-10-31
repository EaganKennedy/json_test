#include "boolean.hpp"

namespace json {
	Boolean::Boolean(bool b) {
		data = b;
	}

	void Boolean::print(std::ostream& out)  const {
		out << data;
	}
	Value Boolean::clone()  const {
		return toValue(data);
	}

	bool Boolean::isBoolean()  const {
		return data;
	}
	bool& Boolean::getBoolean(){
		return data;
	}


	Value toValue(bool b){
		return std::make_shared<Boolean>(b);
	}
}