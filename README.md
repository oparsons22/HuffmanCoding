# C Template

[![CI](https://github.com/oparsons22/CTemplate/actions/workflows/CI.yml/badge.svg)](https://github.com/oparsons22/CTemplate/actions/workflows/CI.yml)
[![codecov](https://codecov.io/github/oparsons22/CTemplate/graph/badge.svg?token=8FJXAAC5PM)](https://codecov.io/github/oparsons22/CTemplate)

This is a template for C projects.

## Usage

> [!important]
> Replace all instances of `CTemplate` with the repository name.

Run the following command to install the project dependencies:

```shell
brew install llvm cmake cppcheck
```

This project uses CMake and Clang/Clang++ to build the executables. It contains
a wrapper Makefile to run different configurations.

The structure is described below, remove as necessary:

```text
|-- Makefile
|-- CMakeLists.txt
|-- README.md
|-- build/      <- Object files
|  |-- bin/     <- Executable files
|  `-- tests/   <- Unit test executable file
|-- data/       <- Project data
|-- src/        <- Source and header files
`-- tests/      <- Unit tests
```

### Build

Run the following commands to build the executable:

```shell
make
```

Alternatively, run the following command to build using [scan-build](https://clang.llvm.org/docs/analyzer/user-docs/CommandLineUsage.html#scan-build):

```shell
make scan-build
```

Run the following command to clean the build files:

```shell
make clean
```

### Unit Tests

Unit test executables are generated in the [build](#build) process and can be run via the following command:

```shell
make tests
```

#### Coverage

Run the following command to generate and open a coverage HTML report:

```shell
make coverage-html
```

You can then view the coverage report by opening `build/tests/coverage_report/index.html`.

### Code Formatting

The source code is formatted using [clang-format](https://clang.llvm.org/docs/ClangFormat.html#clangformat). This can be performed by running the following command:

```shell
make clang-format
```

### Static Analysis

[scan-build](https://clang.llvm.org/docs/analyzer/user-docs/CommandLineUsage.html#scan-build) is used by the compiler to perform statically analyse the source code to identify bugs, security vulnerabilities, and potential performance issues at build time by running the following command:

```shell
make scan-build
```

Additional static analysis can be performed on the build, using [clang-tidy](https://clang.llvm.org/extra/clang-tidy/), by running the following command:

```shell
make clang-tidy
```

Manual static analysis can also be performed using [cppcheck](https://sourceforge.net/projects/cppcheck/):

```shell
make cppcheck
```
