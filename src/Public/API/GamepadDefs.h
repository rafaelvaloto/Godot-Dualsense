

#include "GCore/Types/DSCoreTypes.h"
#include "godot_cpp/classes/object.hpp"
#include "godot_cpp/core/binder_common.hpp"

namespace godot {
class GamepadDefs : public Object {
    GDCLASS(GamepadDefs, Object)
    public:
    enum LedMic {
        MIC_ON = 0,
        MIC_OFF = 1,
        MIC_PULSE = 2
    };

    enum LedPlayer {
        PLAYER_OFF = 0,
        PLAYER_ONE = DSCoreTypes::LedMasks::Middle,
        PLAYER_TWO = DSCoreTypes::LedMasks::MiddleRight | DSCoreTypes::LedMasks::MiddleLeft,
        PLAYER_THREE = DSCoreTypes::LedMasks::Right | DSCoreTypes::LedMasks::Middle | DSCoreTypes::LedMasks::Left,
        PLAYER_ALL = DSCoreTypes::LedMasks::Right | DSCoreTypes::LedMasks::MiddleRight | DSCoreTypes::LedMasks::MiddleLeft | DSCoreTypes::LedMasks::Left
    };

    enum LedBrightness {
        BRIGHTNESS_LOW = 0x03,
        BRIGHTNESS_MEDIUM = 0x02,
        BRIGHTNESS_HIGH = 0x00
    };

    enum AudioFeature {
        AUDIO_ON,
        AUDIO_OFF
    };

    enum DeviceFeature {
        FEATURE_OFF = 0,
        DEFAULT_RUMBLE = 0xFF,
        HAPTICS_RUMBLE = 0xFC
    };

    enum TriggerSoftness {
        SOFTNESS_OFF = 0,
        VERY_RIGID = 1,
        RIGID = 2,
        MEDIUM_SOFTNESS = 4, // Renomeado para evitar conflito
        SOFT = 6,
        VERY_SOFT = 8
    };

    enum TriggerFeedbackIntensity {
        FEEDBACK_DISABLED = 0x00,
        FEEDBACK_LOW = 0x01,
        FEEDBACK_MEDIUM = 0x02,
        FEEDBACK_HIGH = 0x03
    };

    enum TriggerForceIntensity {
        FORCE_DISABLED = 0x00,
        FORCE_LOW = 0x01,
        FORCE_MEDIUM = 0x02,
        FORCE_HIGH = 0x03
    };

    enum TriggerPosition {
        POS_OFF = 0x00,
        POS_START = 0x82,
        POS_MIDDLE = 0x84,
        POS_BEFORE_END = 0x88,
        POS_END = 0x80
    };

    enum TriggerPositionMask {
        MASK_POS_OFF = 0x00,
        MASK_POS_START = 0x00,
        MASK_POS_EARLY = 0x40,
        MASK_POS_MIDDLE = 0x80,
        MASK_POS_LATE = 0xC0,
        MASK_POS_END = 0xFF
    };

    enum TriggerForceMask {
        MASK_FORCE_OFF = 0x00,
        MASK_FORCE_VERY_LOW = 0x20,
        MASK_FORCE_LOW = 0x40,
        MASK_FORCE_MEDIUM_LOW = 0x60,
        MASK_FORCE_MEDIUM = 0x80,
        MASK_FORCE_MEDIUM_HIGH = 0xA0,
        MASK_FORCE_HIGH = 0xC0,
        MASK_FORCE_VERY_HIGH = 0xE0,
        MASK_FORCE_MAX = 0xFF
    };

    enum TriggerAmplitude {
        AMP_NONE = 0x00,
        AMP_LOW = 0x0A,
        AMP_MEDIUM = 0x0C,
        AMP_HIGH = 0x0F
    };

    enum SnapBack {
        SNAP_NONE = 0x00,
        SNAP_LOW = 0x3A,
        SNAP_MEDIUM = 0x3E,
        SNAP_HIGH = 0x3F
    };

    enum WeaponTrigger {
        WEAPON_NONE = 0x00,
        WEAPON_LOW = 0x02,
        WEAPON_MEDIUM = 0x04,
        WEAPON_HIGH = 0x0A,
        WEAPON_MAX = 0x0F
    };

    enum TriggerEffectBehavior {
        LOCALIZED = 0,
        SUSTAINED = 1
    };

    enum AutoGunStrength {
        GUN_LIGHT = 0,
        GUN_MEDIUM = 1,
        GUN_HEAVY = 2
    };

    enum GamepadHand {
        LEFT_HAND,
        RIGHT_HAND,
        ANY_HAND
    };

protected:
    static void _bind_methods();
};
}

VARIANT_ENUM_CAST(godot::GamepadDefs::LedMic);
VARIANT_ENUM_CAST(godot::GamepadDefs::LedPlayer);
VARIANT_ENUM_CAST(godot::GamepadDefs::LedBrightness);
VARIANT_ENUM_CAST(godot::GamepadDefs::AudioFeature);
VARIANT_ENUM_CAST(godot::GamepadDefs::DeviceFeature);
VARIANT_ENUM_CAST(godot::GamepadDefs::TriggerSoftness);
VARIANT_ENUM_CAST(godot::GamepadDefs::TriggerFeedbackIntensity);
VARIANT_ENUM_CAST(godot::GamepadDefs::TriggerForceIntensity);
VARIANT_ENUM_CAST(godot::GamepadDefs::TriggerPosition);
VARIANT_ENUM_CAST(godot::GamepadDefs::TriggerPositionMask);
VARIANT_ENUM_CAST(godot::GamepadDefs::TriggerForceMask);
VARIANT_ENUM_CAST(godot::GamepadDefs::TriggerAmplitude);
VARIANT_ENUM_CAST(godot::GamepadDefs::SnapBack);
VARIANT_ENUM_CAST(godot::GamepadDefs::WeaponTrigger);
VARIANT_ENUM_CAST(godot::GamepadDefs::TriggerEffectBehavior);
VARIANT_ENUM_CAST(godot::GamepadDefs::AutoGunStrength);
VARIANT_ENUM_CAST(godot::GamepadDefs::GamepadHand);
