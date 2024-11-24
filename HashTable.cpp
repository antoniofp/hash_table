// HashTable.cpp
#include "HashTable.hpp"

// Constructor que inicializa la tabla con un tamaño dado
HashTable::HashTable(int size) : size(size), numElements(0), loadFactor(0.0f) {
    table.resize(size, -1);
}

// Función de hash que utiliza el operador módulo
int HashTable::hashFunction(int key) const {
    return key % size;
}

void HashTable::getNumElements(){
    numElements = 0;
    for (int element : table){
        if (element != -1){
            numElements++;
        }
    }
}

void HashTable::rehashing(probingType type){
    //el tamaño de la tabla se duplica
    size = size * 2;
    //se copia la tabla original en una nueva tabla
    std::vector<int> oldTable = table;
    //se limpia la tabla original
    table.clear();
    //se redimensiona la tabla original
    table.resize(size, -1);
    //se insertan los elementos de la tabla original en la nueva tabla
    for (int element : oldTable){
        if (element != -1){
            insert(element, type);
        }
    }
}

// Inserta un elemento en la tabla
void HashTable::insert(int key, probingType type) {
    if (key == -1){
        return;
    }
    
    int i = 0;
    int initialIndex = hashFunction(key);
    int index = initialIndex;
    if (type == LINEAR){
        // Si la posición está ocupada, buscar la siguiente posición disponible de forma lineal
        while (table[index] != -1){
            index = (initialIndex + i) % size;
            i++;
        }
    } else if (type == QUADRATIC){
        // Si la posición está ocupada, buscar la siguiente posición disponible de forma cuadrática
        while (table[index] != -1){
            index = (initialIndex + i * i) % size;
            i++;
        }
    }
    // Insertar el elemento en la tabla
    // Actualizar el factor de carga
    getNumElements();
    loadFactor = static_cast<float>(numElements) / static_cast<float>(size); 
    // si el loadFactor es mayor o igual a 0.7, la tabla necesita rehashing
    if (loadFactor >= 0.69){
        std::cout << "Tabla alcanzo un el LoadFactor de: " << loadFactor << ", necesita rehashing\n";
        rehashing(type);
    }
    table[index] = key;
    getNumElements();
    loadFactor = static_cast<float>(numElements) / static_cast<float>(size); 
    std::cout << "El loadFactor actual es: " << loadFactor << "\n";
    


    
}

// Busca un elemento en la tabla
bool HashTable::search(int key) const {
    //se itera por la tabla y si se encuentra el elemento, se retorna verdadero
    //no se usa la función de hashing porque si hubo colisiones, el elemento no estará en la posición que le corresponde
    for (int element : table){
        if (element == key){
            return true;
        }
    }
    return false;
}

// Elimina un elemento de la tabla
void HashTable::remove(int key) {
    //se itera por la tabla y si se encuentra el elemento, se cambia por -1
    for (int& element : table){
        if (element == key){
            element = -1;
            break;
        }
    }
}

// Muestra la tabla hash
void HashTable::display() const {
    for (int i = 0; i < size; i++){
        if (table[i] != -1){
            std::cout << "Indice: " << i << " Elemento: " << table[i] << "\n";
        }
    }
    std::cout << "Tamaño de la tabla: " << size << "\n";
    std::cout << "\n";
}