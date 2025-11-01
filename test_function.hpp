#pragma once
#include <cassert>
#include "data.hpp"
#include "hashtable_chaining.hpp"
#include "hashtable_quad_probing.hpp"
#include "infile_outfile_handler.hpp"
#include "node.hpp"

class Test{

public: 
    Test(){
        test_data_container(); 
        test_hashtable_container(); 
        test_hashtable1(); 
        test_hashtable2(); 
        test_link_list(); 
    }
    //test if data container work as intended
    void test_data_container() {
        Data test; 
        Data test_empty; 

        test.setProductDescription("TestProduct"); 
        test.setUniqId("TestID"); 
        test.setCategory("Category1|Category2"); //test category. Want to have two category in the end

        assert(test.getProductDescription() == "TestProduct");
        assert(test.getUniqId() == "TestID");
        assert(test.getCategory(0) == "Category1");
        assert(test.getCategory(1) == "Category2");

        //Empty data
        test_empty.setCategory(""); 
        assert(test_empty.getCategory(0) == "N/A"); 
        cout << "DATA CONTAINER PASS\n\n"; 
    }

    //test if hashtable container work as intended
    void test_hashtable_container()
    {
        HashTable_Container<string,string> container; 

        container.setKey("TestKey"); 
        container.setData("TestData"); 

        assert(container.getData() == "TestData"); 
        assert(container.getKey() == "TestKey"); 
        cout << "HASHTABLE CONTAINER PASS\n\n"; 
    }

   //test hashtable (quadratic probing) 
   void test_hashtable1(){
        HashTable_Quad_Probing <string, Data> test; 
        Data data_test; 
        data_test.setUniqId("TestUniqID"); 
        test.insert_uniq_id(data_test.getUniqId(), data_test); 

        test.find("TestUniqID"); //Should display information if it works
        test.find("nothing");  //should display nothing for it doesnt exist
        cout << "HASHTABLE QUAD PROB PASS\n\n"; 
   }

   //test hashtable (chaining) 
   void test_hashtable2(){
        HashTable_Chaining <string, Data> test; 
        Data data_test; 
        data_test.setCategory("TestCategory1|TestCategory2"); 
        test.insert_category(data_test.getCategory(1), data_test); //should insert TestCategory2

        test.find("TestCategory2"); //Should display information if it works
        test.find("nothing");  //should display nothing for it doesnt exist
        cout << "HASHTABLE CHAINING PASS\n\n"; 
   }

   // tset link list
   void test_link_list()
   {
        Link_List<string> test; 
        string data_test_one = "Test"; 
        string data_test_two = "Test 2"; 

        assert(test.isEmpty()); //test if empty
        test.insertAtFront(data_test_one);
        assert(test.gethead()->getData() == "Test"); 
        test.insertAtFront(data_test_two); 
        assert(test.gethead()->getData() == "Test 2"); 
        cout << "LINKLIST PASS\n\n"; 
   }


};