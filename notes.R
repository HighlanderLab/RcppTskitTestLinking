library(usethis)
path <- "."
create_package(path)
proj_activate(path)
use_mit_license("Gregor Gorjanc")

# Add to DESCRIPTION next two lines:
# Imports: RcppTskit
# LinkingTo: RcppTskit
# And until RcppTskit is on CRAN, add to DESCRIPTION also this line:
# Remotes: git::git@bitbucket.org:HighlanderLab/RcppTskit.git

use_tidy_description()

use_readme_md()

use_test("my-test")

use_git()


Imports: Rcpp, RcppTskit
LinkingTo: Rcpp, RcppTskit