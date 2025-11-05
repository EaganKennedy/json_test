#include "idata.hpp"

namespace json{
	class Object : public IData {
	public:
		Object(DataMap = {});

		void print(std::ostream& out) const override;
		Data clone() const override;

		bool isObject() const override;
		DataMap& getObject() override;

	protected:
		DataMap data;
	};

	Data toData(DataMap dm);

	template<typename T>
	Data toData(std::map<std::string, T>) {

	}
}