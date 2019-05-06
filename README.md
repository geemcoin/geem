Geem (Geem) is an anonymous and private cryptocurrency , just like Bitcoin but more anonymous and privacy centric with opaque and more analysis resistant blockchain. It is people's electronic cash, and does not require any intermediaries.

Geem now has adaptive block size limit and difficulty. In addition to it Geem will implement adaptive emission, adaptive minimal transaction fee and adaptive monetary deposit interest rate.

**HARDFORK V4 IS SET TO BE ACTIVATED AT HEIGHT 350000** In this hardfork _Geem introduces adaptive minimal transaction fee_ as first step towards a more flexible and adaptable blockchain. Information for exchanges and other services on how to work with new fees can be found at: https://github.com/geemcoin/geem/wiki/Dynamic-transaction-minimum-fee

## Pool Configuration Changes

Pools operating **'cryptonote-nodejs-pool'** should _change config on hardfork height_. The changes in config are:
```
"daemonType": "default",
"cnAlgorithm": "cryptonight",
"cnVariant": 0,
"cnBlobType": 0,
```

## Building Geem 

### On *nix

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.55 or later.

You may download them from:

- http://gcc.gnu.org/
- http://www.cmake.org/
- http://www.boost.org/

Alternatively, it may be possible to install them using a package manager.

To build, change to a directory where this file is located, and run `make`.

or

Run these commands:
```
cd ~
sudo apt-get install build-essential git cmake libboost-all-dev
git clone https://github.com/geemcoin/geem.git
cd geem
mkdir build
cd build
cmake ..
cd ..
make
```

 The resulting executables can be found in `build/release/src`.

**Advanced options:**

* Parallel build: run `make -j<number of threads>` instead of `make`.
* Debug build: run `make build-debug`.
* Test suite: run `make test-release` to run tests in addition to building. Running `make test-debug` will do the same to the debug version.
* Building with Clang: it may be possible to use Clang instead of GCC, but this may not work everywhere. To build, run `export CC=clang CXX=clang++` before running `make`.

### On Windows
Dependencies: MSVC 2013 or later, CMake 2.8.6 or later, and Boost 1.55. You may download them from:

* http://www.microsoft.com/
* http://www.cmake.org/
* http://www.boost.org/

To build, change to a directory where this file is located, and run theas commands: 
```
mkdir build
cd build
cmake -G "Visual Studio 15 Win64" ..
```

And then do Build.
Good luck!


### Building for macOS

Dependencies: cmake boost and Xcode

Download Xcode from the App store and the Xcode command line tools with `xcode-select --install`
For the other we recommand you to use [Homebrew](https://brew.sh)

Continue with:
```
brew install git cmake boost
git clone https://github.com/geemcoin/geem.git
cd geem
cd build
cmake ..
make
```


### Building for Android on Linux

Set up the 32 bit toolchain
Download and extract the Android SDK and NDK
```
android-ndk-r15c/build/tools/make_standalone_toolchain.py --api 21 --stl=libc++ --arch arm --install-dir /opt/android/tool32
```

Download and setup the Boost 1.65.1 source
```
wget https://sourceforge.net/projects/boost/files/boost/1.65.1/boost_1_65_1.tar.bz2/download -O boost_1_65_1.tar.bz2
tar xjf boost_1_65_1.tar.bz2
cd boost_1_65_1
./bootstrap.sh
```
apply patch from external/boost1_65_1/libs/filesystem/src

Build Boost with the 32 bit toolchain
```
export PATH=/opt/android/tool32/arm-linux-androideabi/bin:/opt/android/tool32/bin:$PATH
./b2 abi=aapcs architecture=arm binary-format=elf address-model=32 link=static runtime-link=static --with-chrono --with-date_time --with-filesystem --with-program_options --with-regex --with-serialization --with-system --with-thread --with-context --with-coroutine --with-atomic --build-dir=android32 --stagedir=android32 toolset=clang threading=multi threadapi=pthread target-os=android --reconfigure stage
```

Build Geem for 32 bit Android
```
mkdir -p build/release.android32
cd build/release.android32
CC=clang CXX=clang++ cmake -D BUILD_TESTS=OFF -D ARCH="armv7-a" -ldl -D STATIC=ON -D BUILD_64=OFF -D CMAKE_BUILD_TYPE=release -D ANDROID=true -D BUILD_TAG="android" -D BOOST_ROOT=/opt/android/boost_1_65_1 -D BOOST_LIBRARYDIR=/opt/android/boost_1_65_1/android32/lib -D CMAKE_POSITION_INDEPENDENT_CODE:BOOL=true -D BOOST_IGNORE_SYSTEM_PATHS_DEFAULT=ON ../..
make SimpleWallet
```

