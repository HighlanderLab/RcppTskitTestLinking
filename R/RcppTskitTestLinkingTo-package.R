#' @description
#' This is a demo package that shows how to link to and import from RcppTskit
#' package, which provides R access to tskit C API.
#' @keywords internal
#'
#' @useDynLib RcppTskitTestLinking, .registration = TRUE
#' @importFrom methods is
#' @import RcppTskit
"_PACKAGE"
