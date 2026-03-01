
# RcppTskitTestLinking

This is a demo package that shows how to link to and import from `RcppTskit`
package, which provides `R` access to `tskit C` API.

R CMD checks: [![R universe](https://highlanderlab.r-universe.dev/RcppTskitTestLinking/badges/checks?label=R-universe)](https://highlanderlab.r-universe.dev/RcppTskitTestLinking) <!-- Col-1-End -->
[![GitHub](https://img.shields.io/github/actions/workflow/status/HighlanderLab/RcppTskitTestLinking/R-CMD-check.yaml?label=GitHub)](https://github.com/HighlanderLab/RcppTskitTestLinking/actions/workflows/R-CMD-check.yaml)

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
# Install from GitHub
remotes::install_github("HighlanderLab/RcppTskitTestLinking")

# Load the package
library(RcppTskitTestLinking)

# Check the help page for one implemented function
?ts_xptr_num_individuals2
```

Now run the example from the help page.
Below we mark it up to explain what is what.

```
# Find an example tree sequence file in RcppTskit package
> ts_file <- system.file("examples", "test.trees", package = "RcppTskit")
> ts_file
[1] "/Users/ggorjanc/Library/R/arm64/4.5/library/RcppTskit/examples/test.trees"

# Load tree sequence into R workspace
> ts <- RcppTskit::ts_load(ts_file)

# Check summary of the tree sequence
> ts
Object of class 'TreeSequence'
$ts
         property            value
1     num_samples               16
2 sequence_length              100
3       num_trees                9
4      time_units      generations
5        min_time                0
6        max_time 6.96199333719081
7    has_metadata            FALSE

$tables
        table number has_metadata
1 provenances      2           NA
2 populations      1         TRUE
3  migrations      0        FALSE
4 individuals      8        FALSE
5       nodes     39        FALSE
6       edges     59        FALSE
7       sites     25        FALSE
8   mutations     30        FALSE

# Note that we have 8 individuals in ts

# We can obtain the same number by running
> ts$num_individuals()
[1] 8

# This demo package implemented the same function
# that is available in RcppTskit, but since we here
# focus just on C++ code, we have to work with the
# pointer object (externalptr) `ts$pointer` and
# not with the tree sequence object (TreeSequence) `ts`
> ts_xptr_num_individuals2(ts$pointer)
[1] 8
```

## Wrap up

Hopefully this demo package shows you sufficiently well on how
to leverage `RcppTskit` for your package.

If we develop any methods that should work on
the tree sequence object (`TreeSequence`) or the table collection object (`TableCollection`),
then the methods could go into `RcppTskit::TreeSequence` or `RcppTskit::TableCollection`
or new packages could inherit from this class and add their methods.
