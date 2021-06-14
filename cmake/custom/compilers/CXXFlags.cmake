set(XCFun_CXX_FLAGS)
set(XCFun_CXX_FLAGS_DEBUG)
set(XCFun_CXX_FLAGS_RELEASE)
set(XCFun_CXX_FLAGS_COVERAGE)

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
  list(APPEND XCFun_CXX_FLAGS
    "-O2"
    "-flto=auto"
    "-ffat-lto-objects"
    "-fexceptions"
    "-g"
    "-grecord-gcc-switches"
    "-pipe"
    "-Wall"
    "-Werror=format-security"
    "-Wp,-D_FORTIFY_SOURCE=2"
    "-Wp,-D_GLIBCXX_ASSERTIONS"
#   "-specs=/usr/lib/rpm/redhat/redhat-hardened-cc1"
    "-fstack-protector-strong"
#   "-specs=/usr/lib/rpm/redhat/redhat-annobin-cc1"
    "-m64"
    "-mtune=generic"
    "-fasynchronous-unwind-tables"
    "-fstack-clash-protection"
    "-fcf-protection"
    )
  list(APPEND XCFun_CXX_FLAGS_DEBUG)
  list(APPEND XCFun_CXX_FLAGS_RELEASE)
  list(APPEND XCFun_CXX_FLAGS_COVERAGE
    "${CODE_COVERAGE_FLAGS}"
    )
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
  list(APPEND XCFun_CXX_FLAGS
    "-fno-rtti"
    "-fno-exceptions"
    )
  list(APPEND XCFun_CXX_FLAGS_DEBUG
    "-Wall"
    "-O0"
    "-g3"
    "-Wextra"
    "-Winit-self"
    "-Woverloaded-virtual"
    "-Wuninitialized"
    "-Wmissing-declarations"
    "-Wwrite-strings"
    "-Wno-sign-compare"
    "-Wno-implicit-fallthrough"
    "-Wno-missing-field-initializers"
    "-Wno-undefined-var-template"
    )
  list(APPEND XCFun_CXX_FLAGS_RELEASE
    "-O3"
    "-ffast-math"
    "-funroll-loops"
    "-ftree-vectorize"
    "-Wno-unused"
    "-Wno-implicit-fallthrough"
    "-Wno-missing-field-initializers"
    "-Wno-undefined-var-template"
    )
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES Intel)
  list(APPEND XCFun_CXX_FLAGS
    "-g"
    "-wd981"
    "-wd279"
    "-wd383"
    "-wd1572"
    "-wd177"
    "-fno-rtti"
    "-fno-exceptions"
    )
  list(APPEND XCFun_CXX_FLAGS_DEBUG
    "-Wall"
    "-O0"
    )
  list(APPEND XCFun_CXX_FLAGS_RELEASE
    "-O3"
    "-ip"
    )
endif ()

if(CMAKE_CXX_COMPILER_ID MATCHES PGI)
  #236 suppress assert warnings and 175 suppress subscript out of range warning /SR
  list(APPEND XCFun_CXX_FLAGS
    "-Mpreprocess"
    "--diag_suppress 236"
    "--diag_suppress 175"
    )
  list(APPEND XCFun_CXX_FLAGS_DEBUG
    "-g"
    "-O0"
    )
  list(APPEND XCFun_CXX_FLAGS_RELEASE
    "-O3"
    "-fast"
    "-Munroll"
    "-Mvect=idiom"
    )
endif()

message(STATUS "C++ compiler flags     : ${CMAKE_CXX_FLAGS} ${XCFun_CXX_FLAGS} ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}} ${XCFun_CXX_FLAGS_${CMAKE_BUILD_TYPE}}")
