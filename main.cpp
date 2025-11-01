#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "hashtable_chaining.hpp"
#include "hashtable_quad_probing.hpp"
#include "infile_outfile_handler.hpp"
#include "data.hpp"
#include "test_function.hpp"

using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line, HashTable_Chaining<string,Data>& hashtable_category, HashTable_Quad_Probing<string,Data>& hashtable_id)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        string id; 
        string trash; 
        stringstream target(line); 
        target >> trash >> id;  

        // Look up the appropriate datastructure to find if the inventory exist
        hashtable_id.find(id);
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        string category; 
        string trash; 
        stringstream target(line); 
        target >> trash;
        getline(target, category); 

        if (category[0] == ' '){  //gets rid of the space at the front of category
            category.erase(0,1); 
        }
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        hashtable_category.find(category);
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}

int main(int argc, char const *argv[])
{
   // Test test; 
    string line;
    bootStrap();
    ifstream infile; 
    infile.open("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");

    getline(infile, line, '\n'); //collect headers of infile.

    Data data; 
    HashTable_Chaining <string, Data> hashtable_category; 
    HashTable_Quad_Probing<string, Data> hashtable_id; 

    while (infile >> data){
    hashtable_id.insert_uniq_id(data.getUniqId(), data); 

        for (int i = 0; i < data.getCategoryCount(); i++){ //insert the same data to a new container with its alternative categories
            string category = data.getCategory(i); 

            if (category[category.back() == ' ']) //get rid of the space at the end if there is space.
            {
                category.pop_back(); 
            }
            hashtable_category.insert_category(category, data); 
        }
    }       

    infile.close(); 

    while (getline(cin, line) && line != ":quit")
    {
         if (validCommand(line))
        {
            evalCommand(line, hashtable_category, hashtable_id);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
