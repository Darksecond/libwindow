# - Find the core library
# This module defines the following variables:
# CORE_INCLUDE_DIRS
# CORE_LIBRARIES
# CORE_FOUND

# Copyright 2014 Tim Peters

find_path(CORE_INCLUDE_DIR core/core.h)
find_library(CORE_LIBRARY NAMES core PATH_SUFFIXES lib64)

set(CORE_INCLUDE_DIRS ${CORE_INCLUDE_DIR})
set(CORE_LIBRARIES ${CORE_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CORE REQUIRED_VARS CORE_INCLUDE_DIR CORE_LIBRARY)

mark_as_advanced(CORE_INCLUDE_DIR CORE_LIBRARY)
