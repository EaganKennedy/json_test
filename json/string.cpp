#include "string.hpp"
#include "iomanip"

using std::string;

namespace json {
	String::String(string s) {
		data = s;
	}

	void String::print(std::ostream& out) const{
		out << std::quoted(data);
	}
	Value String::clone() const{
		return toValue(data);
	}

	bool String::isString() const {
		return true;
	}
	string& String::getString(){
		return data;
	}

	Value toValue(string s) {
		return std::make_shared<String>(s);
	}
	Value toValue(const char* charptr) {
		string temp(charptr);
		return std::make_shared<String>(temp);
	}
}
