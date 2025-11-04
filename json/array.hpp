#include "idata.hpp"
#include <vector>
#include <type_traits>

using std::vector;

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

	Data toData(DataVector dv);

	template<typename T>
	Data toData(const vector<T>& v) {
		DataVector temp;
		for (const T& item : v) {
			temp.push_back(toData(item));
		}
		return std::make_shared<Array>(temp);
	}
}