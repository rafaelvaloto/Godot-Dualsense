#!/usr/bin/env python
import os
import sys

if "build_profile" not in ARGUMENTS:
    ARGUMENTS["build_profile"] = "build_profile.json"

env = SConscript("godot-cpp/SConstruct")

# --- Configuração do Projeto ---
libname = "godot_dualsense"
plugin_path = "demo/bin"

# --- Includes ---
env.Append(CPPPATH=[
    ".",
    "src/",
    "src/Public",
    "src/Private",
    "src/GamepadCore/Source/Public",
    "src/GamepadCore/Source/Private"
])

# --- Flags de Compilação (C++20 Obrigatório) ---
if env["platform"] == "windows":
    # Força C++20 no MSVC
    env.Append(CXXFLAGS=["/std:c++20"])
    env.Append(CPPDEFINES=["UNICODE", "_UNICODE"])
    env.Append(LIBS=["setupapi", "hid"])

elif env["platform"] == "linuxbsd":
    env.Append(CXXFLAGS=["-std=c++20"])

# --- Busca Recursiva de Fontes ---
sources = []
for root, dirs, files in os.walk("src"):
    for file in files:
        if file.endswith(".cpp"):
            file_path = os.path.join(root, file)
            # Filtro de plataforma simples
            if env["platform"] == "windows" and ("Linux" in file_path or "Mac" in file_path or "Android" in file_path):
                continue
            sources.append(file_path)

# --- Compilação ---
library = env.SharedLibrary(
    target=os.path.join(plugin_path, env["platform"], libname),
    source=sources
)

Default(library)