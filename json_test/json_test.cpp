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

TEST(TypeError, Boolean) {
	ASSERT_NO_THROW(Value b = toValue(true));
	Value b = toValue(true);

	ASSERT_THROW(b->getArray(), TypeError);
}
TEST(Identifiers, Boolean) {
	Value b = toValue(true);

	ASSERT_FALSE(b->isNull());
	ASSERT_TRUE(b->isBoolean());
	ASSERT_FALSE(b->isNumber());
	ASSERT_FALSE(b->isString());
	ASSERT_FALSE(b->isArray());
	ASSERT_FALSE(b->isObject());
}
TEST(Getters, Boolean) {
	Value b = toValue(false);

	ostringstream sout;

	b->print(sout);
	ASSERT_EQ(sout.str(), "false");
	sout.str("");

	Value b2 = b->clone();
	b2->print(sout);
	ASSERT_EQ(sout.str(), "false");
	sout.str("");
}