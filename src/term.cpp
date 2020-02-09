#include "term.h"

//Init a term with given query string and weight
Term::Term(std::string query, float weight) {
    this->query = query;
    this->weight = weight;
}

//compare the two terms in desc order by weight
//-1 if this < that. 1 if this > that. 0 if == to that
int Term::byReverseWeightOrder(Term that) {
    if(weight < that.weight) return -1;
    else if(weight > that.weight) return 1;
    else return 0;
}

//compare the two terms in lexicographic order but using only the first r chars of each. 
int Term::byPrefixOrder(Term that, int r) {


    return query.substr(0, r).compare(that.query.substr(0, r));
}

//compares the two terms in lexicographic order by query
int Term::compareTo(Term that) {
    return query.compare(that.query);
}

//returns string representaiton of term. 
std::string Term::toString() {
    return query;
}

//for testing the functions. 
void Term::unit_test(std::string query_one, std::string query_two) {

}

void swap(Term *term1, Term *term2) {
    Term temp = *term1;
    *term1 = *term2;
    *term2 = temp;
}
void sortTerms(std::vector<Term> *terms) {
    int lo = 0; 
    int hi = terms->size() - 1;

    quickSort(terms, lo, hi);
}

void quickSort(std::vector<Term> *terms, int lo, int hi) {
    if (lo < hi) {
        int pi = partition(terms, lo, hi);

        quickSort(terms, lo, pi -1);
        quickSort(terms, pi + 1, hi);
    }
}
int partition(std::vector<Term> *terms, int lo, int hi) {
    Term pivot = terms->at(hi);
    int i = (lo - 1);
    for(int j = lo; j <= hi - 1; j++) {
        if(terms->at(j).compareTo(pivot) < 0) {
            i++;
            swap(terms[i], terms[j]);
        }
    }
    swap(terms[i+1], terms[hi]);
    return(i+1);
}