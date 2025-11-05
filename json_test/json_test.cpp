#include <string>
#include <sstream>
#include <iomanip>

#include "gtest/gtest.h"
#include "json.hpp"

using namespace json;
using std::string;
using std::ostringstream;
using std::quoted;
using std::vector;

vector<int> testV{ 1,2,3 };
vector<string> testVS{ "ein","zwei","drei" };

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
	std::shared_ptr temp = null;
}
TEST(Print, Null) {
	Data v = toData();

	ostringstream sout;
	v->print(sout);
	ASSERT_EQ(sout.str(), "null");
	sout.str("");
}
TEST(Clone, Null) {
	Data v = toData();

	ostringstream sout;

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
	ASSERT_NO_THROW(bool b = v->getBoolean());
}
TEST(Print, Boolean) {
	Data v = toData(false);

	ostringstream sout;

	v->print(sout);
	ASSERT_EQ(sout.str(), "false");
	sout.str("");
}
TEST(Clone, Boolean) {
	Data v = toData(false);

	ostringstream sout;

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

	ASSERT_NO_THROW(int i = v->getNumber());
}
TEST(Print, Number) {
	Data v = toData(3.14);

	ostringstream sout;

	v->print(sout);
	ASSERT_EQ(sout.str(), "3.14");
	sout.str("");

	
}
TEST(Clone, Number) {
	Data v = toData(3.14);

	ostringstream sout;

	Data v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), "3.14");
	sout.str("");
}

TEST(Constructors, String) {
	ASSERT_NO_THROW(String s("Life before death"));
	ASSERT_NO_THROW(String s);
}
TEST(toData, String) {
	ASSERT_NO_THROW(Data s = toData("Strength before weakness"));
}
TEST(TypeError, String) {
	Data s = toData("Journey before destination");

	ASSERT_THROW(s->getBoolean(), TypeError);
}
TEST(Identifiers, String) {
	Data v = toData("These words are accepted");

	ASSERT_FALSE(v->isNull());
	ASSERT_FALSE(v->isBoolean());
	ASSERT_FALSE(v->isNumber());
	ASSERT_TRUE(v->isString());
	ASSERT_FALSE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, String) {
	Data v = toData("Honor is dead,");
	ASSERT_NO_THROW(string s = v->getString());
}
TEST(Print, String) {
	Data v = toData("but I'll see what I can do");

	ostringstream sout;
	string answer = "\"but I'll see what I can do\"";

	v->print(sout);
	ASSERT_EQ(sout.str(), answer);
	sout.str("");

	
}
TEST(Clone, String) {
	Data v = toData("but I'll see what I can do");

	ostringstream sout;
	string answer = "\"but I'll see what I can do\"";

	Data v2 = v->clone();
	v2->print(sout);
	ASSERT_EQ(sout.str(), answer);
	sout.str("");
}

TEST(Constructors, Array) {
	ASSERT_NO_THROW(Array a(DataVector{toData(1),toData(2) ,toData(3) }));
	ASSERT_NO_THROW(Array a());
}
TEST(toData, Array) {
	ASSERT_NO_THROW(Data a = toData(testV));
}
TEST(TypeError, Array) {
	Data a = toData(testV);

	ASSERT_THROW(a->getString(), TypeError);
}
TEST(Identifiers, Array) {
	Data v = toData(testV);

	ASSERT_FALSE(v->isNull());
	ASSERT_FALSE(v->isBoolean());
	ASSERT_FALSE(v->isNumber());
	ASSERT_FALSE(v->isString());
	ASSERT_TRUE(v->isArray());
	ASSERT_FALSE(v->isObject());
}
TEST(Getters, Array) {
	Data a = toData(testV);
	ASSERT_NO_THROW(DataVector dv = a->getArray());
}
TEST(Print, Array) {
	Data a = toData(testV);
	
	ostringstream sout;
	string answer = "[1,2,3]";
	
	a->print(sout);
	ASSERT_EQ(sout.str(), answer);
	sout.str("");

	a = toData(testVS);
	answer = R"([ein,zwei,drei])";
	answer = "[\"ein\",\"zwei\",\"drei\"]";
	a->print(sout);
	ASSERT_EQ(sout.str(), answer);
}
TEST(Clone, Array) {
	Data a = toData(testV);

	ostringstream sout;
	string answer = "[1,2,3]";

	Data a2 = a->clone();
	a2->print(sout);
	ASSERT_EQ(sout.str(), answer);
}

TEST(Constructors, Object) {
	DataMap dmT;
	dmT["ein"] = toData(1);

	ASSERT_NO_THROW(Object o(dmT));
	ASSERT_NO_THROW(Object o());
}
TEST(toData, Object) {
	
}