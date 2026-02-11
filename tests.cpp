#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using doctest::Approx;

TEST_CASE("Samples"){
  CHECK(getShippingCost(1, 800) == doctest::Approx(80));
  
}