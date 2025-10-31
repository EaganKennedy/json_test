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
	Value v = toValue(true);

	ASSERT_FALSE(v->isNull());
	ASSERT_TRUE(v->isBoolean());
	ASSERT_FALSE(v->isNumber());
	ASSERT_FALSE(v->isString());
	ASSERT_FALSE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, Boolean) {
	Value v = toValue(false);

	ostringstream sout;

	v->print(sout);
	ASSERT_EQ(sout.str(), "false");
	sout.str("");

	ASSERT_EQ(false, v->getBoolean());

	Value v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), "false");
	sout.str("");
}

TEST(TypeError, Number) {
	ASSERT_NO_THROW(Value n = toValue(5));

	Value n = toValue(5);

	ASSERT_THROW(n->getObject(), TypeError);
}
TEST(Identifiers, Number) {
	Value v = toValue(2000);

	ASSERT_FALSE(v->isNull());
	ASSERT_FALSE(v->isBoolean());
	ASSERT_TRUE(v->isNumber());
	ASSERT_FALSE(v->isString());
	ASSERT_FALSE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, Number) {
	Value v = toValue(3.14);

	ostringstream sout;

	v->print(sout);
	ASSERT_EQ(sout.str(), "3.14");
	sout.str("");

	ASSERT_EQ(3.14, v->getNumber());

	Value v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), "3.14");
	sout.str("");
}