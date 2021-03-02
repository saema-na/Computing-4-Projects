// Copyright 2020 Saema Nazar

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include "CircularBuffer.h"
#include <stdint.h>
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(construct_object) {
  BOOST_REQUIRE_THROW(CircularBuffer(0), std::invalid_argument);
  BOOST_REQUIRE_THROW(CircularBuffer(0), std::exception);
  BOOST_REQUIRE_NO_THROW(CircularBuffer(5));
  }

BOOST_AUTO_TEST_CASE(test_enqueue) {
  CircularBuffer test_enq(2);
  BOOST_REQUIRE_NO_THROW(test_enq.enqueue(1));
  test_enq.enqueue(1);
  test_enq.enqueue(2);
  BOOST_REQUIRE(test_enq.peek() == 1);
  BOOST_REQUIRE_THROW(test_enq.enqueue(5), std::runtime_error);
  }

BOOST_AUTO_TEST_CASE(test_dequeue) {
  CircularBuffer test_deq(4);
  BOOST_REQUIRE_THROW(test_deq.dequeue(), std::runtime_error);
  test_deq.enqueue(1);
  test_deq.enqueue(2);
  test_deq.enqueue(3);
  test_deq.enqueue(4);
  BOOST_REQUIRE(test_deq.dequeue() == 1);
  BOOST_REQUIRE(test_deq.dequeue() == 2);

  // lambda expression
  auto test_dQ = [&](int16_t x) {return test_deq.dequeue() == x; };
  BOOST_REQUIRE(test_dQ(3));

  BOOST_REQUIRE_NO_THROW(test_deq.dequeue());
}

BOOST_AUTO_TEST_CASE(test_peek) {
  CircularBuffer test_peek(2);
  BOOST_REQUIRE_THROW(test_peek.peek(), std::runtime_error);
  test_peek.enqueue(1);
  test_peek.enqueue(2);
  BOOST_REQUIRE(test_peek.peek() == 1);
  BOOST_REQUIRE_NO_THROW(test_peek.peek());
}
