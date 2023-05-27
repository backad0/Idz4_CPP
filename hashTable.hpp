class hashTable {
    class Entry {
    public:
        int key;
        int value;

        Entry(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };
    class iterator_ht {
    public:
        explicit iterator_ht(hashTable& _ptr) : tableSize(_ptr.tableSize), ptr((_ptr.pEntry)), idx(0) {};
        iterator_ht(hashTable& _ptr, int _idx) : tableSize(_ptr.tableSize), ptr((_ptr.pEntry)), idx(_idx) {};
        iterator_ht& operator++();
        int operator*();
        bool operator==(const iterator_ht& other)const;
        bool operator!=(const iterator_ht& other)const {
            return !(other == *this);
        };
        iterator_ht& operator=(const iterator_ht& rhs);
    private:
        const unsigned int tableSize;
        unsigned idx;
        Entry** ptr;
    };
    Entry** pEntry;
    const unsigned int tableSize;

public:
    hashTable();

    hashTable(unsigned int tableSize );



    int hashFunction(int k);

    void insert(int k, int v);

    void remove(int k);

    int searchKey(int k);

    void clear();

    bool isEmpty();

    iterator_ht begin();
    iterator_ht end();
};
