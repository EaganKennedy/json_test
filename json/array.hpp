#include "iData.hpp"
#include <vector>

namespace json {
	class Array : public IData {
	public:
		Array(DataVector dv = {});

		void print(std::ostream& out) const override;
		Data clone() const override;

		bool isArray() const override;
		DataVector& getArray() override;

	protected:
		DataVector data;

	};

	DataVector toData(DataVector dv);

	template<typename T>
	DataVector toData(std::vector<T> v) {
		DataVector temp;
		for (const auto& item : v) {
			
		}
	}
	template<typename T>
	std::vector<T> fromJson(DataVector dv, T t) {

	}
}