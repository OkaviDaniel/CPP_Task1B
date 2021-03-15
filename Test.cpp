/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code")
{
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(33232124)) == nospaces("  _  \n /_\\ \n\\(o_O)\n(] [)>\n(   )"));
	CHECK(nospaces(snowman(12222212)) == nospaces("_===_\n\\(o.o)/\n( : )\n(\" \")"));
	CHECK(nospaces(snowman(32443333)) == nospaces("  _  \n /_\\ \n(-.-)\n/(> <)\\\n(___)"));
	CHECK(nospaces(snowman(44444432)) == nospaces("  ___ \n (_*_)\n(- -)\n(> <)\n(\" \")"));
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(22222222)) == nospaces("___\n.....\n\\(o.o)/\n(] [)\n(\" \")"));
	CHECK(nospaces(snowman(33333333)) == nospaces("_\n/_\\\n(O_O)\n/(> <)\\\n(___)"));
	CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
	CHECK(nospaces(snowman(12341214)) == nospaces("_===_\n(O.-)/\n<( : )\n(   )"));
	CHECK(nospaces(snowman(12333321)) == nospaces("_===_\n(O.O)\n/(] [)\\\n( : )"));
	CHECK(nospaces(snowman(44114432)) == nospaces("___\n(_*_)\n(. .)\n(> <)\n(\" \")"));
}
TEST_CASE("Another good snowman code")
{
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(21111111)) == nospaces("___\n.....\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(31111111)) == nospaces("_\n/_\\\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(41111111)) == nospaces("___\n(_*_)\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(42111111)) == nospaces("___\n(_*_)\n(...)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(43111111)) == nospaces("___\n(_*_)\n(._.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44111111)) == nospaces("___\n(_*_)\n(. .)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44211111)) == nospaces("___\n(_*_)\n(o .)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44311111)) == nospaces("___\n(_*_)\n(O .)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44411111)) == nospaces("___\n(_*_)\n(- .)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44421111)) == nospaces("___\n(_*_)\n(- o)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44431111)) == nospaces("___\n(_*_)\n(- O)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44441111)) == nospaces("___\n(_*_)\n(- -)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44442111)) == nospaces("___\n(_*_)\n\\(- -)\n( : )>\n( : )"));
	CHECK(nospaces(snowman(44443111)) == nospaces("___\n(_*_)\n(- -)\n/( : )>\n( : )"));
	CHECK(nospaces(snowman(44444111)) == nospaces("___\n(_*_)\n(- -)\n( : )>\n( : )"));
	CHECK(nospaces(snowman(44444211)) == nospaces("___\n(_*_)\n(- -)/\n( : )\n( : )"));
	CHECK(nospaces(snowman(44444311)) == nospaces("___\n(_*_)\n(- -)\n( : )\\\n( : )"));
	CHECK(nospaces(snowman(44444411)) == nospaces("___\n(_*_)\n(- -)\n( : )\n( : )"));
	CHECK(nospaces(snowman(44444421)) == nospaces("___\n(_*_)\n(- -)\n(] [)\n( : )"));
	CHECK(nospaces(snowman(44444431)) == nospaces("___\n(_*_)\n(- -)\n(> <)\n( : )"));
	CHECK(nospaces(snowman(44444441)) == nospaces("___\n(_*_)\n(- -)\n(   )\n( : )"));
	CHECK(nospaces(snowman(44444442)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(\" \")"));
	CHECK(nospaces(snowman(44444443)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(___)"));
	CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
}

TEST_CASE("Bad snowman code")
{
	CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(12));
	CHECK_THROWS(snowman(123));
	CHECK_THROWS(snowman(1234));
	CHECK_THROWS(snowman(12341));
	CHECK_THROWS(snowman(123412));
	CHECK_THROWS(snowman(1234123));
	CHECK_THROWS(snowman(123412341));
}

TEST_CASE("Bad positive numbers")
{
	CHECK_THROWS(snowman(51111111));
	CHECK_THROWS(snowman(15111111));
	CHECK_THROWS(snowman(11511111));
	CHECK_THROWS(snowman(11151111));
	CHECK_THROWS(snowman(11115111));
	CHECK_THROWS(snowman(11111511));
	CHECK_THROWS(snowman(11111151));
	CHECK_THROWS(snowman(11111115));
	CHECK_THROWS(snowman(55555555));
}

TEST_CASE("Bad negative numbers")
{
	CHECK_THROWS(snowman(-11111111));
	CHECK_THROWS(snowman(-22222222));
	CHECK_THROWS(snowman(-33333333));
	CHECK_THROWS(snowman(-44444444));
	CHECK_THROWS(snowman(-12341234));
	CHECK_THROWS(snowman(-43214321));
	CHECK_THROWS(snowman(-24243131));
}