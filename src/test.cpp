#include <tskit.h>
// [[Rcpp::depends(RcppTskit)]]
// [[Rcpp::plugins(RcppTskit)]]

//' @title Get number of individuals in tree sequence
//' @param ts an external pointer to a \code{tsk_treeseq_t} object.
//' @return integer number of individuals.
//' @examples
//' ts_file <- system.file("examples", "test.trees", package = "RcppTskit")
//' ts <- RcppTskit::ts_load(ts_file)
//' RcppTskit::ts$num_individuals()
//' ts_num_individuals_ptr2(ts$pointer)
//' @export
// [[Rcpp::export]]
int ts_num_individuals_ptr2(const SEXP ts) {
  RcppTskit_treeseq_xptr ts_xptr(ts);
  return static_cast<int>(tsk_treeseq_get_num_individuals(ts_xptr));
}