#pragma once
#include <string>
#include "linked_list.hpp"
#include "hashtable_container.hpp"
#include "data.hpp"
#include "node.hpp"

using namespace std; 

template <typename KeyTemplate, typename ValueTemplate>
class HashTable_Chaining{
    private: 
        int max_size = 51;  
        double load_factor = 0; 
        int used_index = 0; 
        Link_List<HashTable_Container<KeyTemplate, ValueTemplate>> *table; 
        void rehash(); 

    public: 
        HashTable_Chaining(); 
        ~HashTable_Chaining(); 

        void update_used_index(); 
        void update_loadfactor(); 
        void rehash_check(); 
        void insert_category(const KeyTemplate key, const ValueTemplate& data); 
        void find(KeyTemplate target);
};

template <typename KeyTemplate, typename ValueTemplate>
inline HashTable_Chaining<KeyTemplate, ValueTemplate>::HashTable_Chaining()
{
    table = new Link_List<HashTable_Container<KeyTemplate, ValueTemplate>> [max_size]; 
}

template <typename KeyTemplate, typename ValueTemplate>
inline HashTable_Chaining<KeyTemplate, ValueTemplate>::~HashTable_Chaining()
{
    delete[] table; 
}

template <typename KeyTemplate, typename ValueTemplate>
inline void HashTable_Chaining<KeyTemplate, ValueTemplate>::update_used_index()
{
    used_index += 1;
}

template <typename KeyTemplate, typename ValueTemplate>
inline void HashTable_Chaining<KeyTemplate, ValueTemplate>::update_loadfactor()
{
    load_factor = double(used_index) / max_size; 
}

template <typename KeyTemplate, typename ValueTemplate>
inline void HashTable_Chaining<KeyTemplate, ValueTemplate>::rehash_check()
{
    if (load_factor > 0.5){
        rehash(); 
    }
}

//insert function, perform a normal hash function.
template <typename KeyTemplate, typename ValueTemplate>
inline void HashTable_Chaining<KeyTemplate, ValueTemplate>::insert_category(const KeyTemplate key, const ValueTemplate &data)
{
    hash<KeyTemplate> function; 
    int index = function(key) % max_size; 
    HashTable_Container<KeyTemplate, ValueTemplate> container; 
    container.setKey(key); 
    container.setData(data); 

    table[index].insertAtFront(container); 

    if (table[index].gethead()->getNextPtr() == nullptr){
        update_used_index(); 
    }

    update_loadfactor(); 
    rehash_check(); 
}

template <typename KeyTemplate, typename ValueTemplate>
inline void HashTable_Chaining<KeyTemplate, ValueTemplate>::find(KeyTemplate target)
{
    hash<KeyTemplate> function; 
    int index = function(target) % max_size; 

    Node<HashTable_Container<KeyTemplate, ValueTemplate>> * pCur = table[index].gethead(); 
    while (pCur != nullptr){
        HashTable_Container<KeyTemplate, ValueTemplate> container = pCur->getData(); 
        pCur = pCur->getNextPtr(); 
        if(container.getKey() == target){
            ValueTemplate data = container.getData(); 

            cout << "Category: " << container.getKey() << "\n" << "Product ID: " << data.getUniqId() << "\n" << "Product Name: " << data.getProductName() << "\n" << "Brand: " << data.getBrandName() << "\n"
            << "ASIN: " << data.getAsin() << "\n" << "UPC/Barcode: " << data.getUpcEanCode() << "\n" << "List Price: " << data.getListPrice() << "\n" << "Selling Price: " << data.getSellingPrice() << "\n"
            << "Quantity: " << data.getQuantity() << "\n" << "Model Number: " << data.getModelNumber() << "\n" << "About Product: " << data.getAboutProduct() << "\n" << "Product Specifications: " << data.getProductSpecification() << "\n"
            << "Technical Details: " << data.getTechnicalDetails() << "\n" << "Shipping Weight: " << data.getShippingWeight() << "\n" << "Product Dimensions: " << data.getProductDimension() << "\n"
            << "Image URL: " << data.getImage() << "\n" << "Variants: " << data.getVariants() << "\n" << "SKU: " << data.getSku() << "\n" << "Product URL: " << data.getProductUrl() << "\n"
            << "Stock: " << data.getStock() << "\n" << "Product Details: " << data.getProductDetails() << "\n" << "Dimension: " << data.getDimension() << "\n" << "Color: " << data.getColor() << "\n"
            << "Ingredients: " << data.getIngredients() << "\n" << "Directions to Use: " << data.getDirectionToUse() << "\n" << "Amazon Seller: " << data.getIsAmazonSeller() << "\n"<< "Size Quantity: " << data.getSizeQuantity() << "\n" << "Product Description: " << data.getProductDescription() << "\n";
        }
    }
}

template <typename KeyTemplate, typename ValueTemplate>
inline void HashTable_Chaining<KeyTemplate, ValueTemplate>::rehash()
{
    int new_max_size = max_size *2; 
    Link_List<HashTable_Container<KeyTemplate, ValueTemplate>>* old_table = table; 

    int old_max_size = max_size; 
    max_size = new_max_size; 
    load_factor = 0; 
    used_index = 0; 

    table = new Link_List<HashTable_Container<KeyTemplate, ValueTemplate>> [new_max_size]; 
    hash<KeyTemplate>function; 

    for (int i = 0; i < old_max_size; i++){
        Node<HashTable_Container<KeyTemplate, ValueTemplate>>* pCur = old_table[i].gethead(); 

        while (pCur != nullptr) {
            HashTable_Container<KeyTemplate, ValueTemplate> old_container = pCur->getData(); 
            ValueTemplate data = old_container.getData(); 
            KeyTemplate key = old_container.getKey(); 

            int index = static_cast<int>(function(key) & 0x7fffffff) % new_max_size;  //have to mask here because  index would just give a negative value. 
            if (table[index].isEmpty()){
                update_used_index(); 
            }
            table[index].insertAtFront(old_container); 

            pCur = pCur->getNextPtr(); 
        }
    }
    load_factor = double(used_index) / max_size; 
    delete[] old_table; 
}

