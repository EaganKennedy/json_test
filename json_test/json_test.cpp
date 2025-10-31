#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "json.hpp"

using namespace json;
using std::string;
using std::ostringstream;

TEST(TypeError, Null) {
	ASSERT_NO_THROW(Value v = toValue());
	Value v = toValue();

	ASSERT_THROW(v->getNumber(), TypeError);
	
	
}
TEST(Identifiers, Null) {
	Value v = toValue();

	ASSERT_TRUE(v->isNull());
	ASSERT_FALSE(v->isBoolean());
	ASSERT_FALSE(v->isNumber());
	ASSERT_FALSE(v->isString());
	ASSERT_FALSE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, Null) {
	Value v = toValue();

	ostringstream sout;
	v->print(sout);
	ASSERT_EQ(sout.str(), "null");
	sout.str("");

	Value v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), "null");
	sout.str("");
}