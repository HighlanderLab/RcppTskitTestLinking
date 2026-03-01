#include <RcppTskit.hpp>
// [[Rcpp::depends(RcppTskit)]]
// [[Rcpp::plugins(RcppTskit)]]

//' @title Get number of individuals in tree sequence
//' @param ts an external pointer to a \code{tsk_treeseq_t} object.
//' @return integer number of individuals.
//' @examples
//' ts_file <- system.file("examples", "test.trees", package = "RcppTskit")
//' ts <- RcppTskit::ts_load(ts_file)
//' ts$num_individuals()
//' ts_xptr_num_individuals2(ts$pointer)
//' @export
// [[Rcpp::export]]
int ts_xptr_num_individuals2(const SEXP ts) {
  RcppTskit_treeseq_xptr ts_xptr(ts);
  return static_cast<int>(tsk_treeseq_get_num_individuals(ts_xptr));
}

//' @title Summarise `tskit` table collection
//' @param tc an external pointer to a \code{tsk_table_collection_t} object.
//' @return A list.
//' @examples
//' ts_file <- system.file("examples", "test.trees", package = "RcppTskit")
//' tc <- RcppTskit:::tc_xptr_load(ts_file)
//' RcppTskit:::tc_xptr_summary(tc)
//' tc_xptr_summary2(tc) # a bit simpler at this stage ...
//' tc <- RcppTskit::TableCollection$new(ts_file)
//' RcppTskit:::tc_xptr_summary(tc$pointer)
//' tc_xptr_summary2(tc$pointer) # a bit simpler at this stage ...
//' @export
// [[Rcpp::export]]
Rcpp::List tc_xptr_summary2(const SEXP tc) {
  RcppTskit_table_collection_xptr tc_xptr(tc);
  const tsk_table_collection_t *tables = tc_xptr;
  return Rcpp::List::create(
      Rcpp::_["num_provenances"] = tables->provenances.num_rows,
      Rcpp::_["num_populations"] = tables->populations.num_rows,
      Rcpp::_["num_migrations"] = tables->migrations.num_rows,
      Rcpp::_["num_individuals"] = tables->individuals.num_rows,
      Rcpp::_["num_nodes"] = tables->nodes.num_rows,
      Rcpp::_["num_edges"] = tables->edges.num_rows,
      Rcpp::_["num_sites"] = tables->sites.num_rows,
      Rcpp::_["num_mutations"] = tables->mutations.num_rows,
      Rcpp::_["sequence_length"] = tables->sequence_length,
      Rcpp::_["has_reference_sequence"] = tc_xptr_has_reference_sequence(tc),
      Rcpp::_["time_units"] = tc_xptr_time_units(tc),
      Rcpp::_["file_uuid"] = tc_xptr_file_uuid(tc),
      Rcpp::_["has_index"] = tc_xptr_has_index(tc));
}
