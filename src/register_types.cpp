#include "register_types.h"

// Inclua o cabeçalho da sua classe
#include "Managers/DualSenseManager.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "API/GamepadDefs.h"

using namespace godot;

// Load module
void initialize_godot_dualsense_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    // initialize class
    ClassDB::register_class<DualSenseManager>();
    ClassDB::register_class<GamepadDefs>();
}

// Load Godot module
void uninitialize_godot_dualsense_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
    // Search dll
    GDExtensionBool GDE_EXPORT gdextension_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_godot_dualsense_module);
        init_obj.register_terminator(uninitialize_godot_dualsense_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
