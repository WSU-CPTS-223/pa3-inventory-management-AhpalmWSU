#pragma once

template <typename Keytype, typename Data> 
class HashTable_Container {
    private: 
        Keytype key; 
        Data data; 

    public: 
        HashTable_Container() : key(), data() {}; //default constructor
        HashTable_Container(const Keytype& newKey, const Data& newData); 
        Keytype getKey() const; 
        Data getData() const; 

        void setKey(Keytype newKey); 
        void setData(const Data& newData);
};

template <typename Keytype, typename Data>
inline HashTable_Container<Keytype, Data>::HashTable_Container(const Keytype& newKey, const Data& newData)
{
    setKey(newKey); 
    setData(newData); 
}

template <typename Keytype, typename Data>
inline Keytype HashTable_Container<Keytype, Data>::getKey() const
{
    return key; 
}

template <typename Keytype, typename Data>
inline Data HashTable_Container<Keytype, Data>::getData() const
{
    return data; 
}

template <typename Keytype, typename Data>
inline void HashTable_Container<Keytype, Data>::setKey(Keytype newKey)
{
    key = newKey;
}

template <typename Keytype, typename Data>
inline void HashTable_Container<Keytype, Data>::setData(const Data &newData)
{
    data = newData; 
}
