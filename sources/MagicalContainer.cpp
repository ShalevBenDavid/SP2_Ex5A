// Created by Shalev Ben David.

#include "MagicalContainer.h"
#include <cmath>
using namespace std;

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
    // If the number is prime, remove from the prime container.
    if (PrimeIterator :: isPrime(element)) {
        // Iterate over the prime container.
        for (size_t i = 0; i < _prime_container.size(); i++) {
            // If we found element, remove and break.
            if (_prime_container.at(i) == element) {
                _prime_container.erase(_prime_container.begin() + i);
                break;
            }
        }
    }
    // Iterate over the sorted container.
    for (size_t i = 0; i < _sorted_container.size(); i++) {
        // If we found element, remove and break.
        if (_sorted_container.at(i) == element) {
            _sorted_container.erase(_sorted_container.begin() + i);
            break;
        }
    }
    // If element isn't in the container, throw.
    throw invalid_argument("Element isn't in the container!\n");
}

/**
 * @return - The size of the container.
 */
size_t MagicalContainer :: size (int) const {
    return _sorted_container.size();
}

// -------------------------------- Class: AscendingIterator --------------------------------

// Default constructor.
AscendingIterator :: AscendingIterator (MagicalContainer* container, size_t index = 0) {
    // If index is negative or out of the containers bound, throw.
    if (index < 0 || index > _container -> _sorted_container.size()) {
        throw invalid_argument("Invalid index.\n");
    }
    // Initialize iterator.
    _container = container;
    _index = index;
}

// Copy constructor.
AscendingIterator :: AscendingIterator (const AscendingIterator& other) : _container(other._container), _index(other.index) {}

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
AscendingIterator& AscendingIterator :: operator = (const AscendingIterator& other) {
    if (this != &other) {
        _iterator = other._iterator;
        _index = other._index;
    }
    return *this;
}

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& AscendingIterator :: operator * () {
    return _container -> _sorted_container.at(_index);
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
AscendingIterator& AscendingIterator :: operator ++ () {
    // Performing ++ will exceed vector bounds.
    if (_index == _container -> _sorted_container.size()) {
        throw runtime_error ("Exceeding container size.\n");
    }
    // Iterate over to the next index and return reference.
    index++;
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool AscendingIterator :: operator == (const AscendingIterator& other) const {
    // Two iterators are equal if their iterators and i
    return ((&_container == &other._container) && (_index == other._index);
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool AscendingIterator :: operator != (const AscendingIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool AscendingIterator :: operator > (const AscendingIterator& other) const {
    return (_index > other._index);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool AscendingIterator :: operator < (const AscendingIterator& other) const {
    return (_index < other._index);
}

// Begin and end operators.
AscendingIterator AscendingIterator :: begin () const {
    // Return a AscendingIterator iterator with index to the start.
    return AscendingIterator (&this, 0);
}
AscendingIterator AscendingIterator :: end () const {
    // Return a AscendingIterator iterator with index to the end.
    return AscendingIterator (&this, _container -> _sorted_container.size());
}

// -------------------------------- Class: SideCrossIterator --------------------------------

// Default constructor.
SideCrossIterator :: SideCrossIterator (MagicalContainer* container, size_t index = 0) {
    // If index is negative or out of the containers bound, throw.
    if (index < 0 || index > _container -> _sorted_container.size()) {
        throw invalid_argument("Invalid index.\n");
    }
    // Initialize iterator.
    _container = container;
    _index = index;
}

// Copy constructor.
SideCrossIterator :: SideCrossIterator (const SideCrossIterator& other) : _container(other._container), _index(other.index) {}

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
SideCrossIterator& SideCrossIterator :: operator = (const SideCrossIterator& other) {
    if (this != &other) {
        _container = other._container;
        _index = other._index;
    }
    return *this;
}

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& SideCrossIterator :: operator * () {
    // If the index is even, reduce index by half.
    if (!(_index % 2)) {
        return _container -> _sorted_container.at(_index / 2);
    }
    // If the index is odd, reduce by 1 and divide by half, and look from the end.
    else {
        return _container -> _sorted_container.at((_container -> _sorted_container.size() - (_index - 1 ) / 2));
    }
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
SideCrossIterator& SideCrossIterator :: operator ++ () {
    // Performing ++ will exceed vector bounds.
    if (_index == _container -> _sorted_container.size()) {
        throw runtime_error ("Exceeding container size.\n");
    }
    // Iterate over to the next index and return reference.
    index++;
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool SideCrossIterator :: operator == (const SideCrossIterator& other) const {
    // Two iterators are equal if their iterators and i
    return ((&_container == &other._container) && (_index == other._index);
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool SideCrossIterator :: operator != (const SideCrossIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool SideCrossIterator :: operator > (const SideCrossIterator& other) const {
    return (_index > other._index);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool SideCrossIterator :: operator < (const SideCrossIterator& other) const {
    return (_index < other._index);
}

// Begin and end operators.
SideCrossIterator SideCrossIterator :: begin () const {
    // Return a SideCrossIterator iterator with index to the start.
    return SideCrossIterator (&this, 0);
}
SideCrossIterator SideCrossIterator :: end () const {
    // Return a SideCrossIterator iterator with index to the end.
    return SideCrossIterator (&this, _container -> _sorted_container.size());
}

// -------------------------------- Class: PrimeIterator --------------------------------

// Default constructor.
PrimeIterator :: PrimeIterator (MagicalContainer* container, size_t index = 0) {
    // If index is negative or out of the containers bound, throw.
    if (index < 0 || index > _container -> _prime_container.size()) {
        throw invalid_argument("Invalid index.\n");
    }
    // Initialize iterator.
    _container = container;
    _index = index;
}

// Copy constructor.
PrimeIterator :: PrimeIterator (const PrimeIterator& other) : _container(other._container), _index(other.index) {}

/**
 * Check if a num is prime.
 * @param num - The num we check if is prime.
 * @return - True if num is prime, and false otherwise.
 */
static bool isPrime (int num) {
    if (num < 2) { return false; }
    for (int i = 2; i <= sqrt(num); i++) {
        if (!(num % i)) { return false; }
    }
    return true;
}

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
PrimeIterator& PrimeIterator :: operator = (const PrimeIterator& other) {
    if (this != &other) {
        _container = other._container;
        _index = other._index;
    }
    return *this;
}

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& PrimeIterator :: operator * () {
    return _container -> _prime_container.at(_index);
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
PrimeIterator& PrimeIterator :: operator ++ () {
    // Iterate over to the next index and return reference.
    index++;
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool PrimeIterator :: operator == (const PrimeIterator& other) const {
    // Two iterators are equal if their iterators and i
    return ((&_container == &other._container) && (_index == other._index);
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool PrimeIterator :: operator != (const PrimeIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool PrimeIterator :: operator > (const PrimeIterator& other) const {
    return (_index > other._index);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool PrimeIterator :: operator < (const PrimeIterator& other) const {
    return (_index < other._index);
}

// Begin and end operators.
PrimeIterator PrimeIterator :: begin () const {
    // Return a prime iterator with index to the start.
    return PrimeIterator (&this, 0);
}
PrimeIterator PrimeIterator :: end () const {
    // Return a prime iterator with index to the start.
    return PrimeIterator (&this, _container -> _prime_container.size());
}