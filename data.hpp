#pragma once
#include <string>
#include <sstream>
using namespace std; 

class Data {
    private: 
        string UniqId; 
        string ProductName; 
        string BrandName; 
        string Asin; 
        string Categories [10];  
        string UpcEanCode; 
        string ListPrice; 
        string SellingPrice; 
        string Quantity;
        string ModelNumber; 
        string AboutProduct; 
        string ProductSpecification; 
        string TechnicalDetails; 
        string ShippingWeight; 
        string ProductDimension; 
        string Image; 
        string Variants; 
        string Sku; 
        string ProductUrl; 
        string Stock; 
        string ProductDetails; 
        string Dimension; 
        string Color; 
        string Ingredients; 
        string DirectionToUse; 
        string IsAmazonSeller; 
        string SizeQuantity; 
        string ProductDescription; 

    public: 
    string getUniqId() const;
    string getProductName() const;
    string getBrandName() const;
    string getAsin() const;
    string getUpcEanCode() const;
    string getListPrice() const;
    string getSellingPrice() const;
    string getQuantity() const;
    string getModelNumber() const;
    string getAboutProduct() const;
    string getProductSpecification() const;
    string getTechnicalDetails() const;
    string getShippingWeight() const;
    string getProductDimension() const;
    string getImage() const;
    string getVariants() const;
    string getSku() const;
    string getProductUrl() const;
    string getStock() const;
    string getProductDetails() const;
    string getDimension() const;
    string getColor() const;
    string getIngredients() const;
    string getDirectionToUse() const;
    string getIsAmazonSeller() const;
    string getSizeQuantity() const;
    string getProductDescription() const;

    int getCategoryCount() const; 
    string getCategory(int index) const; 

    void setUniqId(const string newUniqId);
    void setProductName(const string newProductName);
    void setBrandName(const string newBrandName);
    void setAsin(const string newAsin);
    void setCategory(const string& newCategories);
    void setUpcEanCode(const string newUpcEanCode);
    void setListPrice(const string newListPrice);
    void setSellingPrice(const string newSellingPrice);
    void setQuantity(const string newQuantity);
    void setModelNumber(const string newModelNumber);
    void setAboutProduct(const string newAboutProduct);
    void setProductSpecification(const string newProductSpecification);
    void setTechnicalDetails(const string newTechnicalDetails);
    void setShippingWeight(const string newShippingWeight);
    void setProductDimension(const string newProductDimension);
    void setImage(const string newImage);
    void setVariants(const string newVariants);
    void setSku(const string newSku);
    void setProductUrl(const string newProductUrl);
    void setStock(const string newStock);
    void setProductDetails(const string newProductDetails);
    void setDimension(const string newDimension);
    void setColor(const string newColor);
    void setIngredients(const string newIngredients);
    void setDirectionToUse(const string newDirectionToUse);
    void setIsAmazonSeller(const string newIsAmazonSeller);
    void setSizeQuantity(const string newSizeQuantity);
    void setProductDescription(const string newProductDescription);

};