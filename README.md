[![Build Status](https://travis-ci.org/hortonworks/orc.svg?branch=c%2B%2B)](https://travis-ci.org/hortonworks/orc)
[![Build status](https://ci.appveyor.com/api/projects/status/6aoqt6c860rf6ad4/branch/c++?svg=true)](https://ci.appveyor.com/project/thanhdowisc/orc/branch/c++)

# ORC File C++ Library

This library allows C++ programs to read and write the _Optimized Row Columnar_ (ORC) file format.

## Required Dependencies

## Building

```shell
To compile with tests, in C++11:
% mkdir build
% cd build
% cmake ..
% make
% make test

To compile in C++09i (no tests):
% mkdir build
% cd build
% cmake .. -DC09=true
% make

```

## License
