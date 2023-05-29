// Created by Shalev Ben David.

#include "MagicalContainer.hpp"
#include <cmath>
#include <stdexcept>
using namespace std;
using namespace ariel;

// -------------------------------- Class: Magical contained --------------------------------
/**
 * Adds an element to the container.
 * @param element - The element we add.
 */
void MagicalContainer :: addElement (int element) {
    // Insert element to the container.
    _sorted_container.push_back(element);
    // Sort elements in ascending order.
    sort(_sorted_container.begin(), _sorted_container.end());
    // If the number is prime, add to the prime container.
    if (PrimeIterator :: isPrime(element)) {
        _prime_container.push_back(element);
    }
}

/**
 * Removed an element from the container.
 * @param element - The element we remove.
 */
void MagicalContainer :: removeElement (int element) {
    // Flag that tells if element was found in the container.
    bool found = false;
    // If the number is prime, remove from the prime container.
    if (PrimeIterator :: isPrime(element)) {
        // Iterate over the prime container.
        for (auto item = _prime_container.begin(); item != _prime_container.end(); ++item) {
            // If we found element, remove and break.
            if (*item == element) {
                _prime_container.erase(item);
                break;
            }
        }
    }
    // Iterate over the sorted container.
    for (auto item = _sorted_container.begin(); item != _sorted_container.end(); ++item) {
        // If we found element, remove and break.
        if (*item == element) {
            _sorted_container.erase(item);
            found = true;
            break;
        }
    }
    // If element isn't in the container, throw.
    if (!found) {
        throw invalid_argument("Element isn't in the container!\n");
    }
}

/**
 * @return - The size of the container.
 */
size_t MagicalContainer :: size () const {
    return _sorted_container.size();
}

// -------------------------------- Class: AscendingIterator --------------------------------

// Default constructor.
MagicalContainer :: AscendingIterator :: AscendingIterator (MagicalContainer& container, size_t index) : _container(container), _index(index) {
    // If index is out of the containers bound, throw.
    if (index > container._sorted_container.size()) {
        throw invalid_argument("Invalid index.\n");
    }
}

// Copy constructor.
MagicalContainer :: AscendingIterator :: AscendingIterator (const AscendingIterator& other) : _container (other._container), _index (other._index) {}

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator = (const AscendingIterator& other) {
    if (this != &other) {
        _container = other._container;
        _index = other._index;
    }
    return *this;
}

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& MagicalContainer :: AscendingIterator :: operator * () {
    return _container._sorted_container.at(_index);
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator ++ () {
    // Performing ++ will exceed vector bounds.
    if (_index == _container._sorted_container.size()) {
        throw runtime_error ("Exceeding container's size.\n");
    }
    // Iterate over to the next index and return reference.
    _index++;
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator == (const AscendingIterator& other) const {
    // Two iterators are equal if their iterators and i
    return ((&_container == &other._container) && (_index == other._index));
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator != (const AscendingIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator > (const AscendingIterator& other) const {
    return (_index > other._index);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator < (const AscendingIterator& other) const {
    return (_index < other._index);
}

// Begin and end operators.
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: begin () const {
    // Return a AscendingIterator with index to the start.
    return AscendingIterator(_container, 0);
}
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end () const {
    // Return a AscendingIterator with index to the end.
    return AscendingIterator (_container, _container._sorted_container.size());
}

// -------------------------------- Class: SideCrossIterator --------------------------------
MagicalContainer :: SideCrossIterator :: SideCrossIterator (MagicalContainer& container, size_t index) : _container(container), _index(index) {
    // If index is out of the containers bound, throw.
    if (index > container._sorted_container.size()) {
        throw invalid_argument("Invalid index.\n");
    }
}

// Copy constructor.
MagicalContainer :: SideCrossIterator :: SideCrossIterator (const SideCrossIterator& other) : _container (other._container), _index (other._index) {}

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator = (const SideCrossIterator& other) {
    if (this != &other) {
        _container = other._container;
        _index = other._index;
    }
    return *this;
}

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& MagicalContainer :: SideCrossIterator :: operator * () {
    // If the index is even, reduce index by half.
    if (!(_index % 2)) {
        return _container._sorted_container.at(_index / 2);
    }
    // If the index is odd, reduce by 1 and divide by half, and look from the end.
    else {
        return _container._sorted_container.at((_container._sorted_container.size() - (_index - 1 ) / 2));
    }
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator ++ () {
    // Performing ++ will exceed vector bounds.
    if (_index == _container._sorted_container.size()) {
        throw runtime_error ("Exceeding container's size.\n");
    }
    // Iterate over to the next index and return reference.
    _index++;
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator == (const SideCrossIterator& other) const {
    // Two iterators are equal if their iterators and i
    return ((&_container == &other._container) && (_index == other._index));
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator != (const SideCrossIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator > (const SideCrossIterator& other) const {
    return (_index > other._index);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator < (const SideCrossIterator& other) const {
    return (_index < other._index);
}

// Begin and end operators.
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: begin () const {
    // Return a SideCrossIterator with index to the start.
    return SideCrossIterator (_container, 0);
}
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: end () const {
    // Return a SideCrossIterator with index to the end.
    return SideCrossIterator (_container, _container._sorted_container.size());
}

// -------------------------------- Class: PrimeIterator --------------------------------

// Default constructor.
MagicalContainer :: PrimeIterator :: PrimeIterator (MagicalContainer& container, size_t index) : _container(container), _index(index) {
    // If index is out of the containers bound, throw.
    if (index > container._prime_container.size()) {
        throw invalid_argument("Invalid index.\n");
    }
}

// Copy constructor.
MagicalContainer :: PrimeIterator :: PrimeIterator (const PrimeIterator& other) : _container (other._container), _index (other._index) {}

/**
 * Check if a num is prime.
 * @param num - The num we check if is prime.
 * @return - True if num is prime, and false otherwise.
 */
bool MagicalContainer :: PrimeIterator :: isPrime (int num) {
    if (num < 2) { return false; }
    for (int i = 2; i <= sqrt(num); i++) {
        if (!(num % i)) { return false; }
    }
    return true;
}

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator = (const PrimeIterator& other) {
    if (this != &other) {
        _container = other._container;
        _index = other._index;
    }
    return *this;
}

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& MagicalContainer :: PrimeIterator :: operator * () {
    return _container._prime_container.at(_index);
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator ++ () {
    // Performing ++ will exceed vector bounds.
    if (_index == _container._prime_container.size()) {
        throw runtime_error ("Exceeding container's size.\n");
    }
    // Iterate over to the next index and return reference.
    _index++;
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator == (const PrimeIterator& other) const {
    // Two iterators are equal if their iterators and i
    return ((&_container == &other._container) && (_index == other._index));
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator != (const PrimeIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator > (const PrimeIterator& other) const {
    return (_index > other._index);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator < (const PrimeIterator& other) const {
    return (_index < other._index);
}

// Begin and end operators.
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: begin () const {
    // Return a PrimeIterator with index to the start.
    return PrimeIterator (_container, 0);
}
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: end () const {
    // Return a PrimeIterator with index to the end.
    return PrimeIterator (_container, _container._prime_container.size());
}