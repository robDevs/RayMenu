#include "binarySearchDeluxe.h"
#include <iostream>


int BinarySearchDeluxe::firstIndexOf(std::vector<Term> terms, std::string query) {
    int lo = 0;
    int hi = terms.size() -1;

    Term queryTerm(query, 0);

    if(queryTerm.byPrefixOrder(terms[lo], query.length()) == 0) return 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(queryTerm.byPrefixOrder(terms[mid], query.length()) < 0) hi = mid - 1;
        else if(queryTerm.byPrefixOrder(terms[mid], query.length()) > 0) lo = mid + 1;
        else if(terms[mid - 1].byPrefixOrder(terms[mid], query.length()) == 0) hi = mid - 1;
        else return mid;
    }
    return -1;
}
int BinarySearchDeluxe::lastIndexOf(std::vector<Term> terms, std::string query) {
    int lo = 0;
    int hi = terms.size() -1;

    Term queryTerm(query, 0);

    if(queryTerm.byPrefixOrder(terms[lo], query.length()) == 0) return 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(queryTerm.byPrefixOrder(terms[mid], query.length()) < 0) hi = mid - 1;
        else if(queryTerm.byPrefixOrder(terms[mid], query.length()) > 0) lo = mid + 1;
        else if(terms[mid + 1].byPrefixOrder(terms[mid], query.length()) == 0) lo = mid + 1;
        else return mid;
    }
    return -1;
}