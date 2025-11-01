#include "data.hpp"

//Every get function below obtains class private variables
string Data::getUniqId() const
{
    return this->UniqId;
}

string Data::getProductName() const
{
    return this->ProductName;
}

string Data::getBrandName() const
{
    return this->BrandName;
}

string Data::getAsin() const
{
    return this->Asin;
}

string Data::getUpcEanCode() const
{
    return this->UpcEanCode;
}

string Data::getListPrice() const
{
    return this->ListPrice;
}

string Data::getSellingPrice() const
{
    return this->SellingPrice;
}

string Data::getQuantity() const
{
    return this->Quantity;
}

string Data::getModelNumber() const
{
    return this->ModelNumber;
}

string Data::getAboutProduct() const
{
    return this->AboutProduct;
}

string Data::getProductSpecification() const
{
    return this->ProductSpecification;
}

string Data::getTechnicalDetails() const
{
    return this->TechnicalDetails;
}

string Data::getShippingWeight() const
{
    return this->ShippingWeight;
}

string Data::getProductDimension() const
{
    return this->ProductDimension;
}

string Data::getImage() const
{
    return this->Image;
}

string Data::getVariants() const
{
    return this->Variants;
}

string Data::getSku() const
{
    return this->Sku;
}

string Data::getProductUrl() const
{
    return this->ProductUrl;
}

string Data::getStock() const
{
    return this->Stock;
}

string Data::getProductDetails() const
{
    return this->ProductDetails;
}

string Data::getDimension() const
{
    return this->Dimension;
}

string Data::getColor() const
{
    return this->Color;
}

string Data::getIngredients() const
{
    return this->Ingredients;
}

string Data::getDirectionToUse() const
{
    return this->DirectionToUse;
}

string Data::getIsAmazonSeller() const
{
    return this->IsAmazonSeller;
}

string Data::getSizeQuantity() const
{
    return this->SizeQuantity;
}

string Data::getProductDescription() const
{
    return this->ProductDescription;
}

int Data::getCategoryCount() const //will be use to determine if data has more than one count
{
    int count = 0; 
    for (int i = 0; i < 10; i++)
    {
        if (Categories[i] != "" && Categories[i] != "N/A"){
            count++; 
        }
    }
    return count; 
}

string Data::getCategory(int index) const 
{
    if (index < 10) {
        return Categories[index]; 
    }
    else {
        return "N/A"; 
    }
}

// Every set function below sets a private value based on the argument

void Data::setUniqId( const string newUniqId )
{
    if (newUniqId == ""){
        UniqId = "N/A";
    }
    else { 
        UniqId = newUniqId;
    }
}

void Data::setProductName( const string newProductName )
{
    if (newProductName == ""){
        ProductName = "N/A";
    }
    else {
    ProductName = newProductName;
    }
}

void Data::setBrandName( const string newBrandName )
{
    if (newBrandName == ""){
        BrandName = "N/A";
    }
    else {
    BrandName = newBrandName;
    }
}

void Data::setAsin( const string newAsin )
{
    if (newAsin == ""){
        Asin = "N/A";
    }
    else {
    Asin = newAsin;
    }
}

void Data::setCategory(const string &newCategories)
{
    int i = 0; 
    stringstream line (newCategories);

    while(getline(line, Categories[i], '|')  && i < 10)
    {
        i++; 
    }
    if(Categories[0] == "")
    {
        Categories[0] = "N/A"; 
    }
}

void Data::setUpcEanCode( const string newUpcEanCode )
{
    if (newUpcEanCode == ""){
        UpcEanCode = "N/A"; 
    }
    else {
    UpcEanCode = newUpcEanCode;
    }
}

void Data::setListPrice( const string newListPrice )
{
    if (newListPrice == ""){
        ListPrice = "N/A"; 
    }
    else {
    ListPrice = newListPrice;
    }
}

void Data::setSellingPrice( const string newSellingPrice )
{
    if (newSellingPrice == ""){
        SellingPrice = "N/A"; 
    }
    else {
    SellingPrice = newSellingPrice;
    }
}

void Data::setQuantity( const string newQuantity )
{
    if (newQuantity == ""){
        Quantity = "N/A"; 
    }
    else {
    Quantity = newQuantity;
    }
}

void Data::setModelNumber( const string newModelNumber )
{
    if (newModelNumber == ""){
        ModelNumber = "N/A"; 
    }
    else {
    ModelNumber = newModelNumber;
    }
}

void Data::setAboutProduct( const string newAboutProduct )
{
    if (newAboutProduct == ""){
        AboutProduct = "N/A"; 
    }
    else {
    AboutProduct = newAboutProduct;
    }
}

void Data::setProductSpecification( const string newProductSpecification )
{
    if (newProductSpecification == ""){
        ProductSpecification = "N/A"; 
    }
    else {
    ProductSpecification = newProductSpecification;
    }
}

void Data::setTechnicalDetails( const string newTechnicalDetails )
{
    if (newTechnicalDetails == ""){
        TechnicalDetails = "N/A"; 
    }
    else {
    TechnicalDetails = newTechnicalDetails;
    }
}

void Data::setShippingWeight( const string newShippingWeight )
{
    if (newShippingWeight == ""){
        ShippingWeight = "N/A"; 
    }
    else {
    ShippingWeight = newShippingWeight;
    }
}

void Data::setProductDimension( const string newProductDimension )
{
    if (newProductDimension == ""){
        ProductDimension = "N/A"; 
    }
    else {
    ProductDimension = newProductDimension;
    }
}

void Data::setImage( const string newImage )
{
    if (newImage == ""){
        Image = "N/A"; 
    }
    else {
    Image = newImage;
    }
}

void Data::setVariants( const string newVariants )
{
    if (newVariants == ""){
        Variants = "N/A"; 
    }
    else {
    Variants = newVariants;
    }
}

void Data::setSku( const string newSku )
{
    if (newSku == ""){
        Sku = "N/A"; 
    }
    else {
    Sku = newSku;
    }
}

void Data::setProductUrl( const string newProductUrl )
{
    if (newProductUrl == ""){
        ProductUrl = "N/A"; 
    }
    else {
    ProductUrl = newProductUrl;
    }
}

void Data::setStock( const string newStock )
{
    if (newStock == ""){
        Stock = "N/A"; 
    }
    else {
    Stock = newStock;
    }
}

void Data::setProductDetails( const string newProductDetails )
{
    if (newProductDetails == ""){
        ProductDetails = "N/A"; 
    }
    else {
    ProductDetails = newProductDetails;
    }
}

void Data::setDimension( const string newDimension )
{
    if (newDimension == ""){
        Dimension = "N/A"; 
    }
    else {
    Dimension = newDimension;
    }
}

void Data::setColor( const string newColor )
{
    if (newColor == ""){
        Color = "N/A"; 
    }
    else {
    Color = newColor;
    }
}

void Data::setIngredients( const string newIngredients )
{
    if (newIngredients == ""){
        Ingredients = "N/A"; 
    }
    else {
    Ingredients = newIngredients;
    }
}

void Data::setDirectionToUse( const string newDirectionToUse )
{
    if (newDirectionToUse == ""){
        DirectionToUse = "N/A"; 
    }
    else {
    DirectionToUse = newDirectionToUse;
    }
}

void Data::setIsAmazonSeller( const string newIsAmazonSeller )
{
    if (newIsAmazonSeller == ""){
        IsAmazonSeller = "N/A"; 
    }
    else {
    IsAmazonSeller = newIsAmazonSeller;
    }
}

void Data::setSizeQuantity( const string newSizeQuantity )
{
    if (newSizeQuantity == ""){
        SizeQuantity = "N/A"; 
    }
    else {
    SizeQuantity = newSizeQuantity;
    }
}

void Data::setProductDescription( const string newProductDescription )
{
    if (newProductDescription == ""){
        ProductDescription = "N/A"; 
    }
    else {
    ProductDescription = newProductDescription;
    }
}

