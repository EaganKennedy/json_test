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
	Data String::clone() const{
		return toData(data);
	}

	bool String::isString() const {
		return true;
	}
	string& String::getString(){
		return data;
	}

	Data toData(string s) {
		return std::make_shared<String>(s);
	}
	Data toData(const char* charptr) {
		string temp(charptr);
		return std::make_shared<String>(temp);
	}
}
