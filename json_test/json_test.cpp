#include <string>
#include <sstream>
#include <iomanip>

#include "gtest/gtest.h"
#include "json.hpp"

using namespace json;
using std::string;
using std::ostringstream;
using std::quoted;

TEST(Constructors, Null) {
	ASSERT_NO_THROW(Null v);
}
TEST(toData, Null) {
	ASSERT_NO_THROW(Data v = toData());
}
TEST(TypeError, Null) {
	Data v = toData();

	ASSERT_THROW(v->getNumber(), TypeError);
}
TEST(Identifiers, Null) {
	Data v = toData();

	ASSERT_TRUE(v->isNull());
	ASSERT_FALSE(v->isBoolean());
	ASSERT_FALSE(v->isNumber());
	ASSERT_FALSE(v->isString());
	ASSERT_FALSE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, Null) {
	Data v = toData();

	ostringstream sout;
	v->print(sout);
	ASSERT_EQ(sout.str(), "null");
	sout.str("");

	Data v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), "null");
	sout.str("");
}


TEST(Constructors, Boolean) {
	ASSERT_NO_THROW(Boolean b(true));
	ASSERT_NO_THROW(Boolean b);
}
TEST(toData, Boolean) {
	ASSERT_NO_THROW(Data b = toData(true));
}
TEST(TypeError, Boolean) {
	Data b = toData(true);

	ASSERT_THROW(b->getArray(), TypeError);
}
TEST(Identifiers, Boolean) {
	Data v = toData(true);

	ASSERT_FALSE(v->isNull());
	ASSERT_TRUE(v->isBoolean());
	ASSERT_FALSE(v->isNumber());
	ASSERT_FALSE(v->isString());
	ASSERT_FALSE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, Boolean) {
	Data v = toData(false);

	ostringstream sout;

	v->print(sout);
	ASSERT_EQ(sout.str(), "false");
	sout.str("");

	ASSERT_EQ(false, v->getBoolean());

	Data v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), "false");
	sout.str("");
}

TEST(Constructors, Number) {
	ASSERT_NO_THROW(Number n(5));
	ASSERT_NO_THROW(Number n);
}
TEST(toData, Number) {
	ASSERT_NO_THROW(Data n = toData(5));
}
TEST(TypeError, Number) {
	Data n = toData(5);

	ASSERT_THROW(n->getObject(), TypeError);
}
TEST(Identifiers, Number) {
	Data v = toData(2000);

	ASSERT_FALSE(v->isNull());
	ASSERT_FALSE(v->isBoolean());
	ASSERT_TRUE(v->isNumber());
	ASSERT_FALSE(v->isString());
	ASSERT_FALSE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, Number) {
	Data v = toData(3.14);

	ostringstream sout;

	v->print(sout);
	ASSERT_EQ(sout.str(), "3.14");
	sout.str("");

	ASSERT_EQ(3.14, v->getNumber());

	Data v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), "3.14");
	sout.str("");
}

TEST(toData, String) {
	ASSERT_NO_THROW(String s("Life before death"));
	ASSERT_NO_THROW(String s);
}
TEST(Constructors, String) {
	ASSERT_NO_THROW(Data s = toData("Strength before weakness"));

	Data s = toData("Journey before destination");
}
TEST(TypeError, String) {
	Data s = toData("These words are accepted");

	ASSERT_THROW(s->getBoolean(), TypeError);
}
TEST(Identifiers, String) {
	Data v = toData("Honor is dead,");

	ASSERT_FALSE(v->isNull());
	ASSERT_FALSE(v->isBoolean());
	ASSERT_FALSE(v->isNumber());
	ASSERT_TRUE(v->isString());
	ASSERT_FALSE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, String) {
	Data v = toData("but I'll see what I can do");

	ostringstream sout;
	string answer = "\"but I'll see what I can do\"";

	v->print(sout);
	ASSERT_EQ(sout.str(), answer);
	sout.str("");

	ASSERT_EQ("but I'll see what I can do", v->getString());

	Data v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), answer);
	sout.str("");
}