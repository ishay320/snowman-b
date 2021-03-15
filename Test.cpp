#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <algorithm>
#include <string>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline
 * and tab. Requires std=c++2a.
 */
string nospaces(string input) {
  std::erase(input, ' ');
  std::erase(input, '\t');
  std::erase(input, '\n');
  std::erase(input, '\r');
  return input;
}

TEST_CASE("Good snowman code") {
  CHECK(nospaces(snowman(11114411)) ==
        nospaces("\n_===_\n(.,.)\n( : )\n( : )"));
  CHECK(nospaces(snowman(43214321)) == nospaces(" ___(_*_)(o_.)(][)\\(:)"));
  CHECK(nospaces(snowman(12341214)) ==
        nospaces("\n _===_\n (O.-)/\n<( : )\n (   )"));
  CHECK(nospaces(snowman(12344321)) ==
        nospaces("\n _===_\n (O.-) \n (] [)\\\n ( : )"));
  CHECK(nospaces(snowman(12333321)) ==
        nospaces("\n _===_\n (O.O) \n/(] [)\\\n ( : )"));
  CHECK(nospaces(snowman(33232124)) ==
        nospaces("   _\n  /_\\\n\\(o_O) \n (] [)>\n (   )"));

  CHECK(nospaces(snowman(11111111)) ==
        nospaces("\n _===_\n (.,.) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(22222222)) ==
        nospaces("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \")"));
  CHECK(nospaces(snowman(33333333)) ==
        nospaces("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___)"));
  CHECK(nospaces(snowman(44444444)) ==
        nospaces("  ___  \n (_*_) \n (- -) \n (   ) \n (   )"));

  CHECK(nospaces(snowman(11111112)) ==
        nospaces("\n _===_\n (.,.) \n<( : )>\n (\" \")"));
  CHECK(nospaces(snowman(11111113)) ==
        nospaces("\n _===_\n (.,.) \n<( : )>\n (___)"));
  CHECK(nospaces(snowman(11111114)) ==
        nospaces("\n _===_\n (.,.) \n<( : )>\n (   )"));
  CHECK(nospaces(snowman(11111121)) ==
        nospaces("\n _===_\n (.,.) \n<(] [)>\n ( : )"));
  CHECK(nospaces(snowman(11111131)) ==
        nospaces("\n _===_\n (.,.) \n<(> <)>\n ( : )"));
  CHECK(nospaces(snowman(11111141)) ==
        nospaces("\n _===_\n (.,.) \n<(   )>\n ( : )"));
  CHECK(nospaces(snowman(11111211)) ==
        nospaces("\n _===_\n (.,.)/\n<( : ) \n ( : )"));
  CHECK(nospaces(snowman(11111311)) ==
        nospaces("\n _===_\n (.,.) \n<( : )\\\n ( : )"));
  CHECK(nospaces(snowman(11111411)) ==
        nospaces("\n _===_\n (.,.) \n<( : ) \n ( : )"));
  CHECK(nospaces(snowman(11112111)) ==
        nospaces("\n _===_\n\\(.,.) \n ( : )>\n ( : )"));
  CHECK(nospaces(snowman(11113111)) ==
        nospaces("\n _===_\n (.,.) \n/( : )>\n ( : )"));
  CHECK(nospaces(snowman(11114111)) ==
        nospaces("\n _===_\n (.,.) \n ( : )>\n ( : )"));
  CHECK(nospaces(snowman(11121111)) ==
        nospaces("\n _===_\n (.,o) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(11131111)) ==
        nospaces("\n _===_\n (.,O) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(11141111)) ==
        nospaces("\n _===_\n (.,-) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(11211111)) ==
        nospaces("\n _===_\n (o,.) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(11311111)) ==
        nospaces("\n _===_\n (O,.) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(11411111)) ==
        nospaces("\n _===_\n (-,.) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(12111111)) ==
        nospaces("\n _===_\n (...) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(13111111)) ==
        nospaces("\n _===_\n (._.) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(14111111)) ==
        nospaces("\n _===_\n (. .) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(21111111)) ==
        nospaces("  ___\n .....\n (.,.) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(31111111)) ==
        nospaces("   _\n  /_\\\n (.,.) \n<( : )>\n ( : )"));
  CHECK(nospaces(snowman(41111111)) ==
        nospaces("  ___\n (_*_)\n (.,.) \n<( : )>\n ( : )"));
}

TEST_CASE("Bad snowman code") {

  // diffrent sizes
  CHECK_THROWS(snowman(1));
  CHECK_THROWS(snowman(11));
  CHECK_THROWS(snowman(111));
  CHECK_THROWS(snowman(1111));
  CHECK_THROWS(snowman(11111));
  CHECK_THROWS(snowman(111111));
  CHECK_THROWS(snowman(1111111));
  CHECK_THROWS(snowman(111111111));
  // diffrent numbers
  CHECK_THROWS(snowman(91111111));
  CHECK_THROWS(snowman(01111111));
  CHECK_THROWS(snowman(19111111));
  CHECK_THROWS(snowman(10111111));
  CHECK_THROWS(snowman(11911111));
  CHECK_THROWS(snowman(11011111));
  CHECK_THROWS(snowman(11191111));
  CHECK_THROWS(snowman(11101111));
  CHECK_THROWS(snowman(11119111));
  CHECK_THROWS(snowman(11110111));
  CHECK_THROWS(snowman(11111911));
  CHECK_THROWS(snowman(11111011));
  CHECK_THROWS(snowman(11111191));
  CHECK_THROWS(snowman(11111101));
  CHECK_THROWS(snowman(11111119));
  CHECK_THROWS(snowman(11111110));
  // minus
  CHECK_THROWS(snowman(-11111111));
  CHECK_THROWS(snowman(-1111));
  CHECK_THROWS(snowman(-55555555));
}
