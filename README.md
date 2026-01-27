
# RcppTskitTestLinking

This is a demo package that shows how to link to and import from RcppTskit
package, which provides R access to tskit C API.

## Key files

The key files you should study are:

- `DESCRIPTION`

- `R/RcppTskitTestLinking-package.R`

- `src/test.cpp`

- `src/Makevars.in` and `src/Makevars.win.in`

- `tools/configure.R`

- `configure` and `configure.win`

- `cleanup` and `cleanup.win`

## Install and test

You can install and test this package by running:

```
remotes::install_github("HighlanderLab/RcppTskitTestLinking")
library(RcppTskitTestLinking)
?ts_num_individuals2
```
