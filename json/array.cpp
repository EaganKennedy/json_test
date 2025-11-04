#include "array.hpp"

namespace json {
	Array::Array(DataVector dv) {
		data = dv;
	}

	void Array::print(std::ostream& out) const{

	}
	Data Array::clone() const {
		std::shared_ptr clone = std::make_shared<Array>();

		for (const auto& item : data) {
			clone->data.push_back(item->clone());
		}

		return clone;
	}

	bool Array::isArray() const{
		return true;
	}
	DataVector& Array::getArray(){
		return data;
	}

	Data toData(DataVector dv) {
		DataVector newDV;

		for (const auto& item : dv) {
			newDV.push_back(item->clone());
		}

		return std::make_shared<Array>(newDV);
	}
}