#include <Rcpp.h>
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace Rcpp;

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

int  count_substring (std::string pattern,
                      std::string x
                     )
{

    // string counter
    int i = 0;

    if(x.length() != 0){

        // to lower case
        boost::algorithm::to_lower(x);

        // loop over pattern in string, if found augment counter
        size_t pos = 0;
        size_t from = 0;

        while ((pos = x.find(pattern, from)) != std::string::npos) {

            from = pos + pattern.length();
            ++i;
        }

    }

    return i;

}

