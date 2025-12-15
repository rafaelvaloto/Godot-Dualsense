cmake_minimum_required(VERSION 3.20)
project(godot_dualsense)

# --- Configuração do Padrão C++ (Igual ao SCons) ---
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Definições de Pré-processador (Crucial para Windows e Godot) ---
if(WIN32)
    add_compile_definitions(
            WIN32
            _WIN32
            _WINDOWS
            UNICODE        # Corrige o erro do CreateFileW
            _UNICODE       # Corrige o erro do CreateFileW
            NOMINMAX       # Evita conflito com std::min/max
            TYPED_METHOD_BIND # Necessário para o Godot
            HOT_RELOAD_ENABLED
    )
endif()

# --- Pastas de Include (Onde o CLion vai procurar os .h) ---
include_directories(
        .
        src
        src/Public
        src/Private
        # Submódulo GamepadCore
        src/GamepadCore/Source/Public
        src/GamepadCore/Source/Private
        # Godot CPP (Bindings)
        godot-cpp/include
        godot-cpp/gen/include
        godot-cpp/gdextension
)

# --- Busca de Arquivos Fonte (Recursiva) ---
# Isso imita o script Python do SCons que fizemos
file(GLOB_RECURSE SOURCES
        "src/*.cpp"
        "src/*.h"
        "src/*.hpp"
        "src/*.c"
)

# --- Filtros de Plataforma (Para o CLion não indexar arquivos de Linux no Windows) ---
if(WIN32)
    list(FILTER SOURCES EXCLUDE REGEX ".*(Linux|Mac|Android|IOS).*")
elseif(UNIX AND NOT APPLE)
    list(FILTER SOURCES EXCLUDE REGEX ".*(Windows|Mac|Android|IOS).*")
endif()

# --- Definição do Alvo (Target) ---
# Cria uma biblioteca compartilhada (DLL) para o CLion entender que é um projeto válido
add_library(${PROJECT_NAME} SHARED ${SOURCES}
        src/Public/API/GamepadDefs.h
        src/Private/API/GamepadDefs.cpp
)

# --- Aviso sobre Godot-CPP ---
# Como não estamos compilando o godot-cpp via CMake aqui (usamos SCons),
# o CLion vai apenas ler os headers. Isso é suficiente para o autocomplete.