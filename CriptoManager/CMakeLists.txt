cmake_minimum_required(VERSION 3.16)
project(CriptoManager LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(CriptoManager main.cpp
    cifrador.h cifrador.cpp
    cifradorcesar.h cifradorcesar.cpp
    cifradorxor.h cifradorxor.cpp
    cifradorvigenere.h cifradorvigenere.cpp
    utilidades.h utilidades.cpp
    gestorarchivos.h gestorarchivos.cpp
    usuario.h usuario.cpp
    gestorusuarios.h gestorusuarios.cpp
    operacion.h operacion.cpp
    historialoperaciones.h historialoperaciones.cpp
)
target_link_options(CriptoManager PRIVATE -static -static-libgcc -static-libstdc++)
target_link_libraries(CriptoManager comdlg32)
include(GNUInstallDirs)
install(TARGETS CriptoManager
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)