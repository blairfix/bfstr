#include <Rcpp.h>
#include <vector>
#include <string>


// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

Rcpp::NumericVector string_index ( Rcpp::StringVector x )

{

int n = x.size();
Rcpp::NumericVector index_vec(n);

int index = 1;

for( int i = 0; i < n; i++ ){

    index_vec[i] = index;

    if( i <(n-1) && x[i] != x[i + 1] ){
	index++;
    }
}

return index_vec;

}

