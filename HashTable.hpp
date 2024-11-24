// HashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>

enum probingType { LINEAR, QUADRATIC };

class HashTable {
private:
    std::vector<int> table;
    int size;
    int numElements;
    float loadFactor;

    // Función de hash que utiliza el operador módulo
    int hashFunction(int key) const;
    void getNumElements();
    void rehashing(probingType type);

public:
    // Constructor
    HashTable(int size);

    // Métodos de la tabla hash
    void insert(int key, probingType type);
    bool search(int key) const;
    void remove(int key);
    void display() const;
};

#endif // HASHTABLE_H