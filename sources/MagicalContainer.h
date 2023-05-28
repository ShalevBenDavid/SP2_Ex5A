// Created by Shalev Ben David.

#ifndef SP2_EX5A_MAGICALCONTAINER_H
#define SP2_EX5A_MAGICALCONTAINER_H

#include <vector>

class MagicalContainer {
    // Private attributes.
    std :: vector <int> _sorted_container;
    std :: vector <int> _prime_container;

public:
    // Constructors.
    MagicalContainer () {};

    // Methods.
    void addElement (int);
    void removeElement (int);
    size_t size () const;

    // Iterators.
    friend class AscendingIterator;
    friend class SideCrossIterator;
    friend class PrimeIterator;
};

// --------------------------- Class: AscendingIterator ---------------------------
class AscendingIterator {
private:
    // Private attributes.
    MagicalContainer* _container;
    size_t _index;

public:
    // Constructors.
    AscendingIterator (MagicalContainer* container, size_t index = 0); // Default constructor.
    AscendingIterator (const AscendingIterator& other); // Copy constructor.

    // Destructor.
    ~AscendingIterator ();

    // <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
    AscendingIterator& operator = (const AscendingIterator& other);

    // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
    int& operator * ();

    // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
    AscendingIterator& operator ++ ();

    // Compare operators.
    // <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
    bool operator == (const AscendingIterator&) const;
    // <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
    bool operator != (const AscendingIterator&) const;
    // <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
    bool operator > (const AscendingIterator&) const;
    // <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
    bool operator < (const AscendingIterator&) const;

    // Begin and end operators.
    AscendingIterator begin () const;
    AscendingIterator end () const;
};

// --------------------------- Class: SideCrossIterator ---------------------------
class SideCrossIterator {
private:
    MagicalContainer* _container;
    size_t _index;

public:
    // Constructors.
    SideCrossIterator (MagicalContainer* container, size_t index = 0); // Default.
    SideCrossIterator (const SideCrossIterator& other); // Copy.

    // Destructor.
    ~SideCrossIterator ();

    // <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
    SideCrossIterator& operator = (const SideCrossIterator& other);

    // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
    int& operator * ();

    // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
    SideCrossIterator& operator ++ ();

    // Compare operators.
    // <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
    bool operator == (const SideCrossIterator& other) const;
    // <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
    bool operator != (const SideCrossIterator& other) const;
    // <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
    bool operator > (const SideCrossIterator& other) const;
    // <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
    bool operator < (const SideCrossIterator& other) const;

    // Begin and end operators.
    SideCrossIterator begin () const;
    SideCrossIterator end () const;
};

// --------------------------- Class: PrimeIterator ---------------------------
class PrimeIterator {
private:
    MagicalContainer* _container;
    size_t _index;

public:
    // Constructors.
    PrimeIterator (MagicalContainer* container, size_t index = 0);
    PrimeIterator (const PrimeIterator& other);

    // Destructor.
    ~PrimeIterator ();

    // Methods.
    static bool isPrime (int);

    // <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
    PrimeIterator& operator = (const PrimeIterator& other);

    // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
    int& operator * ();

    // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
    PrimeIterator& operator ++ ();

    // Compare operators.
    // <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
    bool operator == (const PrimeIterator& other) const;
    // <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
    bool operator != (const PrimeIterator& other) const;
    // <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
    bool operator > (const PrimeIterator& other) const;
    // <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
    bool operator < (const PrimeIterator& other) const;

    // Begin and end operators.
    PrimeIterator begin () const;
    PrimeIterator end () const;
};

#endif //SP2_EX5A_MAGICALCONTAINER_H
