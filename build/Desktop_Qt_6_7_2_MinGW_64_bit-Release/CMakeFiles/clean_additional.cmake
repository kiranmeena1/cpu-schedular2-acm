# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\cpu_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cpu_autogen.dir\\ParseCache.txt"
  "cpu_autogen"
  )
endif()
