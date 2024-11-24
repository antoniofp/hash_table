// main.cpp
#include "HashTable.hpp"

int main() {
    // Tamaño de la tabla hash
    int tableSize = 10;
    HashTable hashTable(tableSize);

    // Insertar elementos
    hashTable.insert(5, LINEAR);
    hashTable.display();
    std::cin.get();
    hashTable.insert(15, LINEAR);
    hashTable.display();
    std::cin.get();
    hashTable.insert(25, LINEAR);
    hashTable.display();
    std::cin.get();
    hashTable.insert(2, LINEAR);
    hashTable.display();
    std::cin.get();
    hashTable.insert(10, LINEAR);
    hashTable.display();
    std::cin.get();
    hashTable.insert(7, QUADRATIC);
    hashTable.display();
    std::cin.get();
    hashTable.insert(12, QUADRATIC);
    hashTable.display();
    std::cin.get();
    hashTable.insert(9, QUADRATIC);
    hashTable.display();
    std::cin.get();
    hashTable.insert(19, QUADRATIC);
    hashTable.display();
    std::cin.get();



    // Buscar elementos
    std::cout << "\nBuscar 15: " << (hashTable.search(15) ? "Encontrado" : "No encontrado") << "\n";
    std::cout << "Buscar 9: " << (hashTable.search(9) ? "Encontrado" : "No encontrado") << "\n";

    // Eliminar un elemento
    hashTable.remove(15);
    std::cout << "\nDespués de eliminar 15:\n";
    hashTable.display();

    return 0;
}