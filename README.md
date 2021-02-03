# C++ Build System and Testing Framework for Google Code Jam

This is a tiny setup I prepared to make my sporadic participation in Google Code Jam contests a bit more comfortable.

It is only tested on Linux but should in principle run on all platforms with support for [Meson](http://mesonbuild.com/), [Google Test](https://github.com/google/googletest) and of course [GCC](https://gcc.gnu.org/).

## Prerequisites

Since Code Jam 2020, for C++ solutions _gcc 8.3.0_ is used with the following compilation line:
```
g++ solution.cpp -std=c++17 -pthread -O2 -o solution
```

- [Meson build system](http://mesonbuild.com/) with the [Ninja](https://ninja-build.org/) backend
- Google's C++ test framework [Google Test](https://github.com/google/googletest)

On Debian-based systems use apt to install the following packages:
```
sudo apt install meson ninja libgtest-dev 
```
If meson is not provided by your package manager, you can use the python 3 installer:
```
pip3 install meson
```

## Getting Started

For each round of a Code Jam contest, make a copy of the folder [template](template) (e.g. `2025/Round2b`) and add an include instruction to the end of [meson.build](meson.build). Add any helper files provided by Google for a particular round.

For each round a pair of source file and corresponding tests is provided (e.g. [A.cpp](template/A.cpp) and [A-test.cpp](template/A-test.cpp)). Integrate your solution in the former while adding test to the latter.

The macros provided in [include/testing.h](include/testing.h) allow you to perform unit testing on the solution's `main()` function, providing input and capturing the output as a whole, without having to account for it in the solution file at all.
It means that after successful debugging and unit testing of your solution, you can simply copy&paste the complete contents of the file to the competition dashboard.

## Compiling and Testing
- Setup meson in an out-of-source build directory (e.g. a subdirectory in the project root):
```
mkdir build
cd build
meson .. [--prefix=/install/dir] [--buildtype=(plain|debug|debugoptimized|release)]
```
- Use mesonconf to revise or modify your configuration:
```
mesonconf .
```
- Both meson(.py) and mesonconf(.py) offer decent command-line help if executed with the option --help.
- To compile the code, execute ninja in the build directory:
```
ninja [-v]
```
- Execute all unit tests using the following command:
```
ninja test
```

Of course you can execute the compiled solution executables or test individually from the build directory (there is no need to perform 'ninja install').
