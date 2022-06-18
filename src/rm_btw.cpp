#include <Rcpp.h>
#include <string>

using namespace Rcpp;

// [[Rcpp::export]]

std::string rm_btw( 
	std::string x, 
	char a,
	char b
	)
{

    bool inside = false;
    std::string output;

    for (size_t i = 0; i < x.size(); ++i){ 

	char ch = x[i];

	if (ch == a){ 

	    inside = true;

	} else { 

	    if ( ch == b ){

		inside = false;

	    } else {

		if ( !inside ){

		    output += ch;
		}
	    }
	}
    }
    

    return output;

}

