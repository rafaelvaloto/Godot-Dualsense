#pragma once

#include <godot_cpp/variant/utility_functions.hpp>
#include <functional>
#include <concepts>

struct FGodotRegistryPolicy
{
    using EngineIdType = int32_t;

    // Hasher necessário para o TBasicDeviceRegistry usar IDs como chave em Mapas
    struct Hasher
    {
        std::size_t operator()(const EngineIdType& Id) const
        {
            return std::hash<EngineIdType>{}(Id);
        }
    };

    // Contador simples para gerar novos IDs únicos
    static inline EngineIdType NextDeviceId = 0;

    // Função chamada pela biblioteca quando um novo controle físico é encontrado
    EngineIdType AllocEngineDevice()
    {
        return ++NextDeviceId;
    }

    // Chamado quando a conexão é confirmada
    void DispatchNewGamepad(EngineIdType GamepadId)
    {
        godot::UtilityFunctions::print("[GamepadCore] DualSense Conectado! ID: ", GamepadId);
        DualSenseManager::get_singleton()->test_lightbar();
        DualSenseManager::get_singleton()->test_rumble();
        DualSenseManager::get_singleton()->test_weapon();
        DualSenseManager::get_singleton()->test_custom_trigger();
        // DualSenseManager::get_singleton()->emit_signal("device_connected", GamepadId);
    }

    // Chamado quando o controle é desconectado
    void DisconnectDevice(EngineIdType GamepadId)
    {
        godot::UtilityFunctions::print("[GamepadCore] DualSense Desconectado! ID: ", GamepadId);
        // DualSenseManager::get_singleton()->emit_signal("device_disconnected", GamepadId);
    }
};
