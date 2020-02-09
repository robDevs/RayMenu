#ifndef _AUTOCOMPLETE_
#define _AUTOCOMPLETE_

#include "term.h"
#include "binarySearchDeluxe.h"
#include <string>
#include <vector>

class AutoComplete {
    private:

    public:
    //init the data struct from given vector of terms
    AutoComplete(Term[] terms);

    //return an array of terms that start with the given prefix in descending order of weight
    Term[] allMatches(std::string prefix); //return null if no matches. 

    //return number of matches. 
    int numberOfMatches(std::string prefix);
}

#endif