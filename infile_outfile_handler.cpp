#include <string>
#include "infile_outfile_handler.hpp"
#include "data.hpp"

using namespace std; 

ifstream& operator>> (ifstream& lhs, Data& rhs)
{
    string uniq_id;
    string product_name;
    string brand_name;
    string asin;
    string categories; 
    string upc_ean_code;
    string list_price;
    string selling_price;
    string quantity;
    string model_number;
    string about_product;
    string product_specification;
    string technical_details;
    string shipping_weight;
    string product_dimension;
    string image;
    string variants;
    string sku;
    string product_url;
    string stock;
    string product_details;
    string dimension;
    string color;
    string ingredients;
    string direction_to_use;
    string is_amazon_seller;
    string size_quantity;
    string product_description;

    if (getline(lhs, uniq_id, ',') && getline(lhs, product_name, ',') && getline(lhs, brand_name, ',') && getline(lhs, asin, ',') && getline(lhs, categories, ',') && getline(lhs, upc_ean_code, ',') &&
         getline(lhs, list_price, ',') && getline(lhs, selling_price, ',') && getline(lhs, quantity, ',') && getline(lhs, model_number, ',') && getline(lhs, about_product, ',') && getline(lhs, product_specification, ',') &&
         getline(lhs, technical_details, ',') && getline(lhs, shipping_weight, ',') && getline(lhs, product_dimension, ',') && getline(lhs, image, ',') && getline(lhs, variants, ',') && getline(lhs, sku, ',') &&
         getline(lhs, product_url, ',') && getline(lhs, stock, ',') && getline(lhs, product_details, ',') && getline(lhs, dimension, ',') && getline(lhs, color, ',') && getline(lhs, ingredients, ',') && getline(lhs, direction_to_use, ',') &&
         getline(lhs, is_amazon_seller, ',') && getline(lhs, size_quantity, ',') && getline(lhs, product_description, '\n') )
    {
        rhs.setUniqId(uniq_id);
        rhs.setProductName(product_name);
        rhs.setBrandName(brand_name);
        rhs.setAsin(asin);
        rhs.setCategory(categories); 
        rhs.setUpcEanCode(upc_ean_code);
        rhs.setListPrice(list_price);
        rhs.setSellingPrice(selling_price);
        rhs.setQuantity(quantity);
        rhs.setModelNumber(model_number);
        rhs.setAboutProduct(about_product);
        rhs.setProductSpecification(product_specification);
        rhs.setTechnicalDetails(technical_details);
        rhs.setShippingWeight(shipping_weight);
        rhs.setProductDimension(product_dimension);
        rhs.setImage(image);
        rhs.setVariants(variants);
        rhs.setSku(sku);
        rhs.setProductUrl(product_url);
        rhs.setStock(stock);
        rhs.setProductDetails(product_details);
        rhs.setDimension(dimension);
        rhs.setColor(color);
        rhs.setIngredients(ingredients);
        rhs.setDirectionToUse(direction_to_use);
        rhs.setIsAmazonSeller(is_amazon_seller);
        rhs.setSizeQuantity(size_quantity);
        rhs.setProductDescription(product_description);

    }
    return lhs;
}

