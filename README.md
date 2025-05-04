# Simple Sandbox with C++

A small project which implements a sandbox using [SFML](https://www.sfml-dev.org/) in C++.

> [!NOTE]  
> On Linux VMs (WSL2 etc.) the program may hang, closing then relaunching the program may fix it

<img src="https://github.com/user-attachments/assets/c0b68d73-b175-4f84-9bd5-c5e8cf2243e3" alt="drawing" width="600"/>

## Building and running on your own machine
### Prerequisites
You will need:
- [CMake](https://cmake.org/download/) (≥ 3.28)
- [Git](https://git-scm.com/downloads)
- C++ compiler (GCC ≥ 9, Clang ≥ 10, or MSVC ≥ 2019)

And SFML dependencies:
Linux (Ubuntu/Debian)
```
sudo apt install libopenal-dev libx11-dev libxrandr-dev libfreetype6-dev libgl1-mesa-dev libudev-dev
```
macOS (Homebrew)
```
brew install openal-soft freetype
```
Windows (vcpkg)
```
vcpkg install openal-soft freetype
```

### Build
```sh
# Clone the repository
git clone https://github.com/EllMoorby/SimpleSandbox.git
cd SimpleSandbox

# Build using cmake
cmake -B build && cmake --build build
```
### Run
Linux/macOS
```
./build/bin/SimpleSandbox
```
Windows
```
.\build\bin\SimpleSandbox.exe
```

### Controls
Left mouse places sand
