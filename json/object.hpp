#include "idata.hpp"

namespace json{
	class Object : public IData {
	public:
		Object(DataMap = {});

		void print(std::ostream& out) const override;
		Data clone() const override;

		bool isObject() const override;
		DataMap& getObject() override;
		const DataMap& getObject() const override;

	protected:
		DataMap data;
	};

	Data toData(DataMap dm);

	template<typename T>
	Data toData(std::map<std::string, T> m) {
		DataMap temp;
		for (const auto& [key, value] : m) {
			temp[key] = toData(value);
		}

		return std::make_shared<Object>(temp);
	}

	std::ostream& operator<<(std::ostream& out, Object const& rhs);
}