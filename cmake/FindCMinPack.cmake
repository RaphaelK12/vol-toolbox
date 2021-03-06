find_path(CMINPACK_DIRS
          NAMES "minpack.h"
          HINTS "lib/cminpack")
option (BUILD_EXAMPLES "Build the examples and tests." OFF)
add_subdirectory ("${CMINPACK_DIRS}")
target_compile_definitions(cminpack PUBLIC CMINPACK_NO_DLL)
set_target_properties (cminpack PROPERTIES FOLDER external)
set_target_properties (uninstall PROPERTIES FOLDER external)