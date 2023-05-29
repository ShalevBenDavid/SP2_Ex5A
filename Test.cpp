// Created by Shalev Ben David.
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;

TEST_CASE("Case 1: Adding Elements To The Container.") {
    MagicalContainer container;

    // ---- Testing: Adding the same element a couple of times.
    // ---- Expecting: Should work.
    container.addElement(1);
    CHECK_NOTHROW(container.addElement(1));
    CHECK_NOTHROW(container.addElement(1));

    // ---- Testing: Adding double type.
    // ---- Expecting: Should cast element to int and work.
    double num = 1.2;
    CHECK_NOTHROW(container.addElement(num));
}

TEST_CASE("Case 2: Removing Elements From The Container.") {
    MagicalContainer container;

    // ---- Testing: Removing item front an empty container.
    // ---- Expecting: Should throw exception.
    CHECK_THROWS(container.removeElement(-1));

    // Add elements to the container.
    container.addElement(1);
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    // ---- Testing: Removing 1 completely from the container.
    // ---- Expecting: Should work.
    CHECK_NOTHROW(container.removeElement(1));
    CHECK_NOTHROW(container.removeElement(1));
    // ---- Testing: Removing a number which isn't in the container.
    // ---- Expecting: Should throw exception.
    CHECK_THROWS(container.removeElement(1));
    CHECK_THROWS(container.removeElement(100));
}