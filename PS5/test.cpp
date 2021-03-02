// Copyright 2020 Saema Nazar

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include "MModel.h"
#include <stdint.h>
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(construct_object) {
  BOOST_REQUIRE_THROW(MModel("abc", 8), std::invalid_argument);
  BOOST_REQUIRE_NO_THROW(MModel("abcde", 2));
  }


BOOST_AUTO_TEST_CASE(test_freq_1_2) {
  MModel test("abcdef", 2);

  // one arg freq tests
  BOOST_REQUIRE_NO_THROW(test.freq("ab"));
  BOOST_REQUIRE_THROW(test.freq("a"), std::invalid_argument);
  BOOST_REQUIRE(test.freq("ab") == 1);

  // two arg freq tests
  BOOST_REQUIRE_NO_THROW(test.freq("ab", 'c'));
  BOOST_REQUIRE_THROW(test.freq("a"), std::invalid_argument);
  BOOST_REQUIRE(test.freq("ab", 'c') == 1);
  }


BOOST_AUTO_TEST_CASE(test_rand) {
  MModel test("abcdef", 2);
  BOOST_REQUIRE_THROW(test.kRand("a"), std::invalid_argument);
  BOOST_REQUIRE_THROW(test.kRand("xa"), std::invalid_argument);
  BOOST_REQUIRE_NO_THROW(test.kRand("ab"));

  BOOST_REQUIRE(test.kRand("ab") == 'c');
}

BOOST_AUTO_TEST_CASE(test_generate) {
  MModel test("abcdef", 2);
  BOOST_REQUIRE_THROW(test.generate("a", 4), std::invalid_argument);

  BOOST_REQUIRE(test.generate("ab", 3) == "abc");
  BOOST_REQUIRE_NO_THROW(test.generate("ab", 3));
  }

BOOST_AUTO_TEST_CASE(test_kOrder) {
  MModel test("abc", 2);

  BOOST_REQUIRE(test.kOrder() == 2);
}
