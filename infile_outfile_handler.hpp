#pragma once
#include "data.hpp"
#include <fstream>

using namespace std; 

ifstream& operator>> (ifstream& lhs, Data& rhs); //Overload >> operator. To move data to uscity
