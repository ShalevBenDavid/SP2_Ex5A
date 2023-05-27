// Created by Shalev Ben David.

#ifndef SP2_EX5A_MAGICALCONTAINER_H
#define SP2_EX5A_MAGICALCONTAINER_H

#include <vector>

class MagicalContainer {
    // Private attributes.
    std :: vector <int> _container;

public:
    // Constructors.
    MagicalContainer () {}; // Default.

    // Methods.
    void addElement (int);
    void removeElement (int);
    size_t size (int) const;

    // --------------------------- Class: AscendingIterator ---------------------------
    class AscendingIterator {
    private:
        // Private attributes.
        std :: vector <int>& _iterator;
        size_t _index;

    public:
        // Constructors.
        AscendingIterator (std :: vector <int>& iterator = _container, size_t index = 0) : _iterator(iterator), _index(index) {} // Default.
        AscendingIterator (const AscendingIterator& other) : _iterator(other._iterator), _index(other.index) {} // Copy.

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
        AscendingIterator begin ();
        AscendingIterator end ();
    };

    // --------------------------- Class: SideCrossIterator ---------------------------
    class SideCrossIterator {
    private:
        std :: vector <int>& _iterator;
        size_t _index;

    public:
        // Constructors.
        SideCrossIterator (std :: vector <int>& iterator = _container, size_t index = 0) : _iterator(iterator), _index(index) {} // Default.
        SideCrossIterator (const SideCrossIterator& other) : _iterator(other._iterator), _index(other._index) {} // Copy.

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
        SideCrossIterator begin ();
        SideCrossIterator end ();
    };

    // --------------------------- Class: PrimeIterator ---------------------------
    class PrimeIterator {
    private:
        std :: vector <int>& _iterator;
        size_t _index;

    public:
        // Constructors.
        PrimeIterator (std :: vector <int>& iterator = _container, size_t index = 0) : _iterator(iterator), _index(index) {} // Default.
        PrimeIterator (const PrimeIterator& other) : _iterator(other._iterator), _index(other._index) {} // Copy.

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
        PrimeIterator begin ();
        PrimeIterator end ();
    };
};
#endif //SP2_EX5A_MAGICALCONTAINER_H
