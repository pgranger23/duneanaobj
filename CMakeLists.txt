cmake_minimum_required (VERSION 3.20 FATAL_ERROR)

project(duneanaobj VERSION 4.0.0 LANGUAGES CXX)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/Modules)


include(CPM)

CPMFindPackage(
  NAME SRProxy
  GIT_TAG feature/Clingification_rebase3
  GITHUB_REPOSITORY luketpickering/SRProxy
  VERSION 0.46.0
)

find_package(ROOT 6.20 REQUIRED)

add_subdirectory(duneanaobj)
