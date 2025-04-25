# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\shudu_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\shudu_autogen.dir\\ParseCache.txt"
  "shudu_autogen"
  )
endif()
