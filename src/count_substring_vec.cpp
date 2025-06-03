#include <Rcpp.h>
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace Rcpp;

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

std::vector<int>  count_substring_vec (
	std::string pattern,
	std::vector<std::string> vec 
	)
{

    // output vector
    std::vector<int> output( vec.size() );

    for( int vec_index = 0; vec_index < vec.size(); vec_index++ ){

	std::string x = vec[ vec_index ];

	// string counter
	int i = 0;

	if( x.length() != 0 ){

	    // to lower case
	    boost::algorithm::to_lower(x);

	    // loop over pattern in string, if found augment counter
	    size_t pos = 0;
	    size_t from = 0;

	    while ((pos = x.find(pattern, from)) != std::string::npos) {

		from = pos + pattern.length();
		++i;
	    }

	    output[ vec_index ] = i;

	}
    }

    return output;

}

