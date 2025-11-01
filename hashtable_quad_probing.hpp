#pragma once
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "data.hpp"
#include "hashtable_container.hpp"

using namespace std; 

template <typename KeyTemplate, typename ValuesTemplate>
class HashTable_Quad_Probing { //using hash table, will have a O(1) for search. This hashtable is only for uniq id. 
    private: 
        double load_factor = 0; 
        int max_size = 51; 
        int used_index = 0; 
        HashTable_Container<KeyTemplate, ValuesTemplate> *table; 
        void rehash(); //change size of table; 
    
    public: 
        HashTable_Quad_Probing(); //constructor 
        ~HashTable_Quad_Probing(); //deconstructor 
        void insert_uniq_id(const KeyTemplate key, const ValuesTemplate& data); 
        void insert_category(const KeyTemplate key, const ValuesTemplate& data); 
        void update_used_index();  //update the number of used index
        void update_loadfactor();   //update load factor of hash table. 
        void rehash_check(); //check if rehash is needed if load factor passes 0.5
        void find(KeyTemplate target); 
};

template <typename KeyTemplate, typename ValuesTemplate>
inline HashTable_Quad_Probing<KeyTemplate, ValuesTemplate>::HashTable_Quad_Probing()
{
    table = new HashTable_Container<KeyTemplate, ValuesTemplate> [max_size]; 
}

template <typename KeyTemplate, typename ValuesTemplate>
inline HashTable_Quad_Probing<KeyTemplate, ValuesTemplate>::~HashTable_Quad_Probing()
{
    delete[] table; 
}

template <typename KeyTemplate, typename ValuesTemplate>
inline void HashTable_Quad_Probing<KeyTemplate, ValuesTemplate>::update_used_index()
{
    used_index += 1; 
}

template <typename KeyTemplate, typename ValuesTemplate>
void HashTable_Quad_Probing<KeyTemplate, ValuesTemplate>::update_loadfactor()
{
    load_factor = double(used_index) / max_size; 
}

template <typename KeyTemplate, typename ValuesTemplate>
inline void HashTable_Quad_Probing<KeyTemplate, ValuesTemplate>::rehash_check()
{
    if (load_factor > 0.5)
    {
        rehash(); 
    }
}

template <typename KeyTemplate, typename ValuesTemplate>
inline void HashTable_Quad_Probing<KeyTemplate, ValuesTemplate>::find(KeyTemplate target)
{
    hash<KeyTemplate> function; 
    int function_value = function(target) % max_size; //hash function
    bool found; 
    for (int i = 0; i < max_size; i++)
    {
        int index = (function_value + i*i) % max_size;// quadratic probing


        if (table[index].getKey() == target) //available spot
        {
            Data data = table[index].getData();
            cout << "Product ID: " << data.getUniqId() << "\n" << "Product Name: " << data.getProductName() << "\n" << "Brand: " << data.getBrandName() << "\n" << "ASIN: " << data.getAsin() << "\n"
            << "UPC/Barcode: " << data.getUpcEanCode() << "\n"<< "List Price: " << data.getListPrice() << "\n" << "Selling Price: " << data.getSellingPrice() << "\n" << "Quantity: " << data.getQuantity() << "\n"
            << "Model Number: " << data.getModelNumber() << "\n" << "About Product: " << data.getAboutProduct() << "\n" << "Product Specifications: " << data.getProductSpecification() << "\n" << "Technical Details: " << data.getTechnicalDetails() << "\n"
            << "Shipping Weight: " << data.getShippingWeight() << "\n" << "Product Dimensions: " << data.getProductDimension() << "\n" << "Image URL: " << data.getImage() << "\n" << "Variants: " << data.getVariants() << "\n"
            << "SKU: " << data.getSku() << "\n" << "Product URL: " << data.getProductUrl() << "\n" << "Stock: " << data.getStock() << "\n" << "Product Details: " << data.getProductDetails() << "\n" << "Dimension: " << data.getDimension() << "\n"
            << "Color: " << data.getColor() << "\n" << "Ingredients: " << data.getIngredients() << "\n" << "Directions to Use: " << data.getDirectionToUse() << "\n" << "Amazon Seller: " << data.getIsAmazonSeller() << "\n"
            << "Size Quantity: " << data.getSizeQuantity() << "\n" << "Product Description: " << data.getProductDescription() << "\n";
            found = true; 
        }
    }
    if (!found){
        cout << "Not Found"; 
    }
}

template <typename KeyTemplate, typename ValuesTemplate>
inline void HashTable_Quad_Probing<KeyTemplate, ValuesTemplate>::rehash()
{
    //Change max_size
    int new_max_size = max_size * 2; 
    int old_max_size = max_size; 
    HashTable_Container<KeyTemplate, ValuesTemplate>* old_table = table;
    table = new HashTable_Container<KeyTemplate, ValuesTemplate>[new_max_size];  //allocate a new space in the heap for a new array
    max_size = new_max_size; //update max_size 

    //reset hash tables attributes for were making a new array
    load_factor = 0; 
    used_index = 0; 

     hash<KeyTemplate> function; 
    for(int i = 0; i < old_max_size; i++) //copy keys and value from old array to new array. //perform the same operation as insert_uniq_id for it must follow its hash function.
    {
        KeyTemplate key = old_table[i].getKey(); 
        ValuesTemplate data = old_table[i].getData(); 
        int function_value = static_cast<int>(function(old_table[i].getKey()) & 0x7fffffff); //have to mask here because  index would just give a negative value. 

        for(int x = 0; x < new_max_size; x++){ //insert_uniq_id data to new array
            int index = (function_value + x*x) % new_max_size; 

            if(table[index].getKey() == "") //if array index is availlable
            {
                table[index].setKey(key); 
                table[index].setData(data); 
                update_used_index(); 
                break; 
            }
    }
    }
    load_factor = double(used_index) / max_size; 
    delete[] old_table; 
}

//insert function for uniq id. Will do quadratic probing. 
template <typename KeyTemplate, typename ValuesTemplate>
void HashTable_Quad_Probing<KeyTemplate, ValuesTemplate>::insert_uniq_id(const KeyTemplate key, const ValuesTemplate& data)
{
    hash<KeyTemplate> function; 
    int function_value = function(key) % max_size; //hash function
    for (int i = 0; i < max_size; i++)
    {
        int index = (function_value + i*i) % max_size;// quadratic probing

        if (table[index].getKey() == "") //available spot
        {
            table[index].setKey(key); 
            table[index].setData(data); 
            update_used_index(); 
            update_loadfactor(); 
            rehash_check(); 
            return; 
        }
    }
}


