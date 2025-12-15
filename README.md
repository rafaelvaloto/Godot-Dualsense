# GodotDualsense (GDExtension) 🎮

A **GDExtension** for **Godot 4.x** that provides native support for the Sony DualSense controller via HID. This extension bypasses standard SDL limitations to unlock advanced features like Adaptive Triggers, Haptic Feedback, and direct Lightbar control.

> ⚠️ **Status: Work in Progress / Proof of Concept**
> This project is currently a functional foundation. Basic communication (Rumble, Lightbar, Simple Triggers) is implemented and stable, but full feature coverage (Touchpad, Gyro) needs community contribution.

## ✨ Features Implemented
- [x] **Lightbar Control:** Set RGB colors programmatically per controller.
- [x] **Rumble/Vibration:** Standard rumble support.
- [x] **Adaptive Triggers (Partial):** Support for basic effects (Resistance, Weapon/Vibration modes).
- [x] **Hot-plugging:** Detects connection/disconnection at runtime via Signals.
- [ ] **Touchpad:** (Help wanted)
- [ ] **Gyroscope/Motion:** (Help wanted)
- [ ] **Battery Status:** (Help wanted)
- [ ] **Audio Haptics:** (Future goal)

## 🛠️ Building & Installation

### 1. Clone with Submodules
This project depends on `godot-cpp` and `GamepadCore`. You must clone recursively:
```bash

git clone --recursive [https://github.com/SEU_USUARIO/GodotDualSense.git](https://github.com/SEU_USUARIO/GodotDualSense.git)

```
2. Compile
   You can use SCons or CMake (if using CLion/Rider).

Using SCons:
```bash
scons platform=windows target=template_debug
# or for release
scons platform=windows target=template_release
```

Using CMake: Open the project in CLion/Rider and build the godot_dualsense target.

## 💻 Usage (GDScript)

Since `DualSenseManager` handles the discovery loop, you just need to listen to signals.

```gdscript
extends Node

# Reference to the manager node in your scene
@onready var dualsense_manager = $DualSenseManager

func _ready():
    # Listen for hot-plug events
    dualsense_manager.device_connected.connect(_on_device_connected)
    dualsense_manager.device_disconnected.connect(_on_device_disconnected)

func _on_device_connected(device_id: int):
    print("DualSense Connected! ID: %d" % device_id)
    
    # 1. Change Lightbar to Cyan
    dualsense_manager.set_lightbar_color(device_id, Color.CYAN)
    
    # 2. Set Adaptive Trigger (Example: Weapon Recoil on Right Trigger)
    # Parameters: device_id, "Right"/"Left", start_pos, end_pos, force
    dualsense_manager.set_trigger_weapon(device_id, "Right", 0, 8, 5)

func _on_device_disconnected(device_id: int):
    print("DualSense Disconnected! ID: %d" % device_id)
```

🤝 Contributing
I need your help! I have built the "hard part": the GDExtension architecture, the C++ build system, and the raw HID communication layer (GamepadCore).

If you want native DualSense support in Godot, please consider contributing to map the missing features instead of starting from scratch.

Fork the repository.

Check the src/GamepadCore submodule for HID implementation details.

Expose new methods in DualSenseManager.cpp.

Submit a Pull Request.

🔗 Architecture
GodotDualSense: Handles the Godot GDExtension wrapping, Node management, and Signals.

GamepadCore: The backend C++ library that handles raw HID reports and OS-level device discovery.

📄 License
MIT License

## ⚖️ Disclaimer and Trademarks

This software is an independent and unofficial project. It is **not** affiliated, associated, authorized, endorsed by, or in any way officially connected with Sony Interactive Entertainment Inc., Microsoft Corporation, Apple Inc., Epic Games, Unity Technologies, the Godot Engine project, or the Open 3D Foundation.

**Trademarks belong to their respective owners:**

* **Sony:** "PlayStation", "PlayStation Family Mark", "PS5 logo", "PS5", "DualSense", and "DualShock" are registered trademarks or trademarks of Sony Interactive Entertainment Inc. "SONY" is a registered trademark of Sony Corporation.
* **Microsoft:** "Windows" and "Xbox" are registered trademarks of Microsoft Corporation.
* **Apple:** "Mac" and "macOS" are registered trademarks of Apple Inc.
* **Linux:** "Linux" is the registered trademark of Linus Torvalds in the U.S. and other countries.
* **Epic Games:** "Unreal" and "Unreal Engine" are trademarks or registered trademarks of Epic Games, Inc. in the United States of America and elsewhere.
* **Unity:** "Unity", Unity logos, and other Unity trademarks are trademarks or registered trademarks of Unity Technologies or its affiliates in the U.S. and elsewhere.
* **Godot:** "Godot" and the Godot logo are trademarks of the Godot Engine project.
* **O3DE:** "O3DE" and the O3DE logo are trademarks of the Open 3D Foundation.

