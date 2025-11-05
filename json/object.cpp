#include "object.hpp"

namespace json {
	Object::Object(DataMap dm) {
		data = dm;
	}

	void Object::print(std::ostream& out) const {
		out << "{";
		bool first = true;

		for (const auto& [key, value] : data) {
			if (!first) {
				out << ",";
			}

			out << "\"" << key << "\":";
			value->print(out);
			first = false;
		}

		out << "}";
	}
	Data Object::clone() const{
		std::shared_ptr clone = std::make_shared<Object>();

		for (const auto& [key, value] : data) {
			clone->data[key] = value->clone();
		}
		return clone;
	}

	bool Object::isObject() const {
		return true;
	}
	DataMap& Object::getObject() {
		return data;
	}

	Data toData(DataMap dm) {
		DataMap newDM;

		for (const auto& [key, value] : dm) {
			newDM[key] = value->clone();
		}

		return std::make_shared<Object>(newDM);
	}
}