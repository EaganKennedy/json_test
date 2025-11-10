#include "array.hpp"

namespace json {
	Array::Array(DataVector dv) {
		data = dv;
	}

	void Array::print(std::ostream& out) const{
		out << "[";
		for (size_t i = 0; i < data.size(); ++i) {
			data[i]->print(out);
			if (i < data.size() - 1) {
				out << ",";
			}
		}
		out << "]";
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
	DataVector& Array::getArray() {
		return data;
	}
	const DataVector& Array::getArray() const {
		return data;
	}

	Data toData(DataVector dv) {
		DataVector newDV;

		for (const auto& item : dv) {
			newDV.push_back(item->clone());
		}

		return std::make_shared<Array>(newDV);
	}

	std::ostream& operator<<(std::ostream& out, const Array& rhs) {
		rhs.print(out);
		return out;
	}
}