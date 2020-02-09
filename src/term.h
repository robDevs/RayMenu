#ifndef _TERM_
#define _TERM_

#include <string>
#include <vector>

class Term {
    private:
    std::string query;
    float weight;

    public:
    //Init a term with given query string and weight
    //-1 if this < that. 1 if this > that. 0 if == to that
    Term(std::string query, float weight);

    //compare the two terms in desc order by weight
    int byReverseWeightOrder(Term that);
    
    //compare the two terms in lexicographic order but using only the first r chars of each. 
    int byPrefixOrder(Term that, int r);

    //compares the two terms in lexicographic order by query
    int compareTo(Term that);

    //returns string representaiton of term. 
    std::string toString();

    //for testing the functions. 
    void unit_test(std::string query_one, std::string query_two);

};

extern void sortTerms(std::vector<Term> *terms);
extern void quickSort(std::vector<Term> *terms, int lo, int hi);
extern int partition(std::vector<Term> *terms, int lo, int hi);

#endif