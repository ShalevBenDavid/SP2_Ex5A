// Created by Shalev Ben David.

#include "MagicalContainer.h"

// -------------------------------- Class: Magical contained --------------------------------
void MagicalContainer :: addElement (int) { }

void MagicalContainer :: removeElement (int) { }

size_t MagicalContainer :: size (int) const { return _container.size(); }

// -------------------------------- Class: AscendingIterator --------------------------------
// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
AscendingIterator& MagicalContainer :: AscendingIterator :: operator = (const AscendingIterator& other);

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& MagicalContainer :: AscendingIterator :: operator * ();

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
AscendingIterator& MagicalContainer :: AscendingIterator :: operator ++ ();

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator == (const AscendingIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator != (const AscendingIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator > (const AscendingIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator < (const AscendingIterator& other) const { return true; }

// Begin and end operators.
AscendingIterator MagicalContainer :: AscendingIterator :: begin () {}
AscendingIterator MagicalContainer :: AscendingIterator :: end () {}

// -------------------------------- Class: SideCrossIterator --------------------------------
// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator = (const SideCrossIterator& other);

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& MagicalContainer :: SideCrossIterator :: operator * ();

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator ++ ();

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator == (const SideCrossIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator != (const SideCrossIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator > (const SideCrossIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator < (const SideCrossIterator& other) const { return true; }

// Begin and end operators.
SideCrossIterator MagicalContainer :: SideCrossIterator :: begin () {}
SideCrossIterator MagicalContainer :: SideCrossIterator :: end () {}

// -------------------------------- Class: PrimeIterator --------------------------------
// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
PrimeIterator& MagicalContainer :: PrimeIterator :: operator = (const PrimeIterator& other);

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
int& MagicalContainer :: PrimeIterator :: operator * ();

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
PrimeIterator& MagicalContainer :: PrimeIterator :: operator ++ ();

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator == (const PrimeIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator != (const PrimeIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator > (const PrimeIterator& other) const { return true; }
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator < (const PrimeIterator& other) const { return true; }

// Begin and end operators.
PrimeIterator MagicalContainer :: PrimeIterator :: begin () {}
PrimeIterator MagicalContainer :: PrimeIterator :: end () {}