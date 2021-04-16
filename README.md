Requisites:
    * Conan C/C++ package manager: on Ubuntu 18.04 run `pip3 install conan`.

Building:

```
mkdir build && cd build
conan install ..
cmake ..
make
```

Binaries are stored in folder `build/bin`.
