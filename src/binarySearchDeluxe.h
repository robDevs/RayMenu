#ifndef _Bdeluxe_
#define _Bdeluxe_

#include "term.h"
#include <vector>

class BinarySearchDeluxe {
    private:

    public:
    int firstIndexOf(std::vector<Term> terms, std::string query);
    int lastIndexOf(std::vector<Term> terms, std::string query);

    void unit_test();

};

#endif