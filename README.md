# GodotDualsense (GDExtension) 🎮

A **GDExtension** for **Godot 4.x** that provides native support for the Sony DualSense controller via HID. This extension is built on top of **[GamepadCore](https://github.com/rafaelvaloto/GamepadCore_)**, a cross-platform C++ library that handles raw HID communication and device discovery for DualSense controllers.

> ⚠️ **Status: Work in Progress / Proof of Concept**
> This project is currently a functional foundation. Basic communication (Rumble, Lightbar, Simple Triggers) is implemented and stable, but full feature coverage (Touchpad, Gyro) needs community contribution.

> 💡 **Looking for a complete implementation?**
> Check out **[Unreal-Dualsense](https://github.com/rafaelvaloto/Unreal-Dualsense)** for a full-featured implementation using the same GamepadCore library.

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

git clone --recursive https://github.com/rafaelvaloto/Godot-Dualsense.git

```

Using SCons:
```bash
scons platform=windows target=template_debug
# or for release
scons platform=windows target=template_release
```

Using CMake: Open the project in CLion/Rider and build the godot_dualsense target.

## 💻 Usage (GDScript)

The `DualSenseManager` handles device discovery automatically. You can extend it or use static test methods:

```gdscript
extends DualSenseManager

func device_connected(device_id: int):
    print("DualSense Connected! ID: ", device_id)
    
    # Test methods available in DualSenseManager
    test_lightbar()   # Sets lightbar to red
    test_weapon()     # Tests weapon effect on triggers
    test_rumble()     # Tests vibration

func device_disconnected(device_id: int):
    print("DualSense Disconnected: ", device_id)
```

**Note:** The current implementation provides basic test methods. For production use, you'll need to extend the C++ API to expose more granular control over GamepadCore features (see Contributing section).

## 🤝 Contributing
This project needs your help! The foundation is complete: the GDExtension architecture, C++ build system, and **GamepadCore** integration are all working.

**GamepadCore** does the heavy lifting—it handles raw HID reports and OS-level device discovery. What's needed now is exposing more of GamepadCore's features through the GDExtension API.

**How to contribute:**

1. Fork the repository.
2. Study the **[GamepadCore](https://github.com/rafaelvaloto/GamepadCore_)** submodule to understand the available HID features.
3. Expose new methods in `DualSenseManager.cpp` that wrap GamepadCore functionality.
4. Submit a Pull Request.

If you want native DualSense support in Godot, please contribute to mapping the missing features instead of starting from scratch. For reference, see **[Unreal-Dualsense](https://github.com/rafaelvaloto/Unreal-Dualsense)** which uses the same GamepadCore library with more complete feature exposure.

## 🔗 Architecture

This project consists of two main components:

### **GamepadCore** (The Foundation) 🎯
**[GamepadCore](https://github.com/rafaelvaloto/GamepadCore_)** is the backend C++ library that powers this extension. It handles:
- Raw HID report parsing and generation
- OS-level device discovery (Windows, with Linux/macOS support planned)
- Direct communication with DualSense hardware
- Low-level trigger effects, haptics, and lightbar control

GamepadCore is designed to be engine-agnostic and can be integrated into any game engine or application. It's already used in **[Unreal-Dualsense](https://github.com/rafaelvaloto/Unreal-Dualsense)**.

### **GodotDualsense** (The Wrapper)
This GDExtension wraps GamepadCore for use in Godot 4.x. It provides:
- Node-based architecture for easy integration
- Signal-based device connection/disconnection events
- Godot-specific bindings and memory management

**In short:** GamepadCore does the hard work of talking to the controller, while GodotDualsense makes it accessible from GDScript.

## 📄 License
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

