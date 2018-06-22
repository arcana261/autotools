[![Build Status](https://travis-ci.org/arcana261/autotools.svg?branch=master)](https://travis-ci.org/arcana261/autotools)
[![Coverage Status](https://coveralls.io/repos/github/arcana261/autotools/badge.svg?branch=master)](https://coveralls.io/github/arcana261/autotools?branch=master)

# autotools
A backbone for autotools and C/C++

See more doc [here](https://autotools.io)

# requirements

1. glib-2.0
2. autotools

# what to do?

```bash
./autogen.sh
./configure
make check
make
make install
```

# linter

requires cpplint, install via `pip install --user cpplint`

```bash
make lint
```

# unit test

```bash
make unittest
```

# gcc/clang sanity checks

```bash
make sanity
```

# code coverage

requires gcov and lcov, install via `apt-get install gcov lcov`

```bash
make coverage
```

# vscode coding

contents of `.vscode/c_cpp_properties.json`
```json
{
    "configurations": [
        {
            "name": "mehdi",
            "includePath": [
                "/usr/include",
                "/usr/include/glib-2.0/glib",
                "/home/arcana/Documents/Projects/autotools",
                "/home/arcana/Documents/Projects/autotools/src",
                "/home/arcana/Documents/Projects/autotools/src/whine"
            ],
            "browse": {
                "path": [
                    "/usr/include/glib-2.0/glib"
                ]
            },
            "intelliSenseMode": "clang-x64",
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c11",
            "cppStandard": "c++17"
        }
    ],
    "version": 4
}
```
