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
		return data;
	}
	bool& Boolean::getBoolean(){
		return data;
	}


	Data toData(bool b){
		return std::make_shared<Boolean>(b);
	}
}