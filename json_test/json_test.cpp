#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "json.hpp"

TEST(TypeError, Null) {
	std::ostringstream sout;
	sout << json::toValue();
}