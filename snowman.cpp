#include "snowman.hpp"
#include <array>
#include <stdexcept>
#include <string>

namespace ariel {
namespace snowmanBody {
std::array<std::string, 4> hat = {{"\n _===_\n", "  ___\n .....\n",
                                   "   _\n  /_\\\n", "  ___\n (_*_)\n"}}; // H
std::array<std::string, 4> nose = {{",", ".", "_", " "}};                 // N
std::array<std::string, 4> eye = {{".", "o", "O", "-"}};                  // L/R
std::array<std::string, 4> LArm = {{" <", "\\ ", " /", "  "}};            // X
std::array<std::string, 4> RArm = {{" >", "/ ", " \\", "  "}};            // Y
std::array<std::string, 4> torso = {{" : ", "] [", "> <", "   "}};        // T
std::array<std::string, 4> base = {{" : ", "\" \"", "___", "   "}};       // B
} // namespace snowmanBody
void checkIfOK(int build) {
  const int MIN_INPUT = 11111111;
  const int MAX_INPUT = 44444444;
  if (build < MIN_INPUT || build > MAX_INPUT) {
    std::exception e;
    throw e;
  }
  const int MAX_LOOP = 100000000;
  const int TEN = 10;
  const int MAX_SINGLE_NUM = 5;
  const int MIN_SINGLE_NUM = 0;

  for (int i = 1; i < MAX_LOOP; i *= TEN) {
    if (!((build / i) % TEN < MAX_SINGLE_NUM &&
          (build / i) % TEN > MIN_SINGLE_NUM)) {
      std::exception e;
      throw e;
    }
  }
}
using namespace snowmanBody;
std::string snowman(int build) {
  checkIfOK(build);
  const int HAT_POS = 10000000;
  const int LARM_POS = 1000;
  const int LEYE_POS = 100000;
  const int REYE_POS = 10000;
  const int NOSE_POS = 1000000;
  const int RARM_POS = 100;
  const int TORSO_POS = 10;
  const int BASE_POS = 1;
  const int TEN = 10;
  std::string snowman = hat.at(build / HAT_POS - 1);
  snowman += LArm.at((build / LARM_POS - 1) % TEN).at(0);
  snowman += "(";
  snowman += eye.at((build / LEYE_POS - 1) % TEN);
  snowman += nose.at((build / NOSE_POS - 1) % TEN);
  snowman += eye.at((build / REYE_POS - 1) % TEN) + ")";
  snowman += RArm.at((build / RARM_POS - 1) % TEN).at(0);
  snowman += "\n";
  snowman += LArm.at((build / LARM_POS - 1) % TEN).at(1);
  snowman += "(";
  snowman += torso.at((build / TORSO_POS - 1) % TEN) + ")";
  snowman += RArm.at((build / RARM_POS - 1) % TEN).at(1);
  snowman += "\n";
  snowman += " (" + base.at((build / BASE_POS - 1) % TEN) + ")";
  return snowman;
}

} // namespace ariel
  // HNLRXYTB

//  HHHHH
//  HHHHH
// X(LNR)Y
// X(TTT)Y
//  (BBB)