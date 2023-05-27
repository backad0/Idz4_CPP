#include "hashTable.hpp"

hashTable::hashTable():tableSize(51) {
    pEntry = new Entry * [tableSize];
    clear();
}

hashTable::hashTable(unsigned int tableSize) : tableSize(tableSize) {
    pEntry = new Entry * [tableSize];
    clear();
}

int hashTable::hashFunction(int k) {
    return k % tableSize;
}

void hashTable::insert(int k, int v) {
    int h = hashFunction(k);
    while (pEntry[h] != nullptr && pEntry[h]->key != k) {
        h = hashFunction(h + 1);
    }
    if (pEntry[h] != nullptr) {
        delete pEntry[h];
        pEntry[h] = nullptr;
    }
    pEntry[h] = new Entry(k, v);
}

void hashTable::remove(int k) {
    int h = hashFunction(k);
    while (pEntry[h] != nullptr) {
        if (pEntry[h]->key == k)
            break;
        h = hashFunction(h + 1);
    }
    if (pEntry[h] == nullptr) {
        //No Element found at key
        return;
    }
    else {
        delete pEntry[h];
    }
}

int hashTable::searchKey(int k) {
    int h = hashFunction(k);
    while (pEntry[h] != nullptr && pEntry[h]->key != k) {
        h = hashFunction(h + 1);
    }
    if (pEntry[h] == nullptr)
        return -1;
    else
        return pEntry[h]->value;
}

void hashTable::clear() {
    for (int i = 0; i < tableSize; i++) {
        pEntry[i] = nullptr;
    }
}

bool hashTable::isEmpty() {
    for (int i = 0; i < tableSize; i++) {
        if (pEntry[i] != nullptr) {
            return false;
        }
    }
    return true;
}

hashTable::iterator_ht& hashTable::iterator_ht::operator++() {

    idx++;
    if (ptr[idx] == nullptr) {
        while (ptr[idx] == nullptr && idx < tableSize - 1) {
            idx++;
        }
    }


    return *this;
}

hashTable::iterator_ht hashTable::begin() {
    return iterator_ht(*this);
}

hashTable::iterator_ht hashTable::end() {
    return iterator_ht(*this, tableSize - 1);
}

int hashTable::iterator_ht::operator*() {
    if (ptr[idx] != nullptr) {
        return ptr[idx]->value;
    }

}

bool hashTable::iterator_ht::operator==(const hashTable::iterator_ht& other)const {
    return this->ptr == other.ptr && this->idx == other.idx;
}

hashTable::iterator_ht& hashTable::iterator_ht::operator=(const hashTable::iterator_ht& rhs) {
    if (this != &rhs) {
        this->ptr = rhs.ptr;
        this->idx = rhs.idx;
    }
    return *this;
}
