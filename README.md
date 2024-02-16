<p align="center">
  <img src="assets/logo.png" alt="Quasar64 Logo" />
</p>

**_Only For Nintendo 64_**

## Overview

Quasar64 is a game engine specifically tailored for the Nintendo 64, built using modern C/C++17 standards and leveraging the power of libdragon. This engine adopts an entity-component-system (ECS) architecture to provide a flexible and efficient foundation for game development. While currently in active development, it already features a robust ECS core.

While there is no dedicated editor available at the moment, future plans include developing a user-friendly interface to streamline game creation on this platform.

## Tentative Features for Q1 2024

- [x] Basic Entity Component System (ECS)
- [ ] Input Presence System
- [ ] Input Action Mapper System
- [ ] Camera State Machine

## Building from Source

To build Quasar64, your system needs to be configured to compile libdragon projects, specifically using the unstable branch of libdragon. Ensure that `N64_INST` environment variable is set correctly as it is referenced in the `Makefile` with `include $(N64_INST)/include/n64.mk`. Run `./build.sh` after your environment is ready to show the build splash screen and then run `make` (yes, this is so slow and inefficient, but I love it).
Use UNFLoader to send the built ROM to native N64 hardware. I have not had much success testing on emulators yet, but haven't spent much time on it yet.

## Contribution and Licensing

Quasar64 is an open-source project under the Unlicense, which allows you to use, modify, and distribute the engine freely. Contributions to the project are welcome and appreciated.

Please note, while the engine itself is unlicensed, you must comply with libdragon's and any other third-party libraries' licenses when using them in your projects.
