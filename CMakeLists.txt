cmake_minimum_required (VERSION 3.23)

project (BlueWarrior)
set (MY_AUTHORS "Michael_Zargari")

include (cmake/CompilerSettings.cmake)

add_executable (${CMAKE_PROJECT_NAME})

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)
include_directories(${PROJECT_SOURCE_DIR}/include/assets)
include (cmake/Zip.cmake)

set (SFML_LOCATION "C:/SFML/SFML-2.6.0")
set (SFML_DIR "${SFML_LOCATION}/lib/cmake/SFML")

find_package (SFML 2.6 COMPONENTS graphics audio REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (${CMAKE_PROJECT_NAME} sfml-graphics sfml-audio sfml-main)

include (cmake/SFML.cmake)

