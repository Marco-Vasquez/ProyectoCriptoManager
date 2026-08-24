cmake_minimum_required(VERSION 3.16)

project(CriptoManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CriptoManager main.cpp)

include(GNUInstallDirs)
install(TARGETS CriptoManager
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
