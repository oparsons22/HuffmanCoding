# Huffman Coding

[![CI](https://github.com/oparsons22/HuffmanCoding/actions/workflows/CI.yml/badge.svg)](https://github.com/oparsons22/HuffmanCoding/actions/workflows/CI.yml)
[![codecov](https://codecov.io/github/oparsons22/HuffmanCoding/graph/badge.svg?token=4R1VN6AHIE)](https://codecov.io/github/oparsons22/HuffmanCoding)

This project focuses on building a lossless data compression algorithm using Huffman Codes. In 1952, David Huffman developed a way to find optimal prefix codes for a given set of input symbols. Essentially, Huffman Codes are variable-length bit strings that uniquely represent a set of input symbols. The main benefit of this scheme is that the more common the input symbol, the fewer the number of bits required to represent it. This is advantageous when compressing data.

## Compressing ASCII Text using Huffman Codes

The algorithm always begins with the source set of symbols to be compressed. For this assignment, we will focus only on using ASCII text but the algorithm applies to any set of symbols. Below is an example source string to be compressed:

> to be or not to be

The first step is to find the frequency of each letter in the source text. These symbol frequencies are a fundamental aspect of the algorithm. Table 1 gives a summary of these frequencies for this example. One approach to compressing this data is to use a block encoding representation that uses the minimum number of bits that permit all the letters to be encoded, i.e. 3 bits per letter for this example. Since there are 18 characters in this string, 54 bits (3 x 18) would be required to represent this sentence using block encoding. Using the Huffman Codes shown in Table 2, the same sentence can be represented with just 47 bits – a 13% reduction in size.

| Letter  | Freq |
|:-------:|:----:|
| `space` |  5   |
|   `o`   |  4   |
|   `t`   |  3   |
|   `b`   |  2   |
|   `e`   |  2   |
|   `n`   |  1   |
|   `r`   |  1   |

*Table 1 - Letter Frequencies*

The second step of the algorithm is to construct a binary tree using the data in Table 1. The pseudo-code below describes a way to build a binary tree. It makes use of a priority queue to construct the tree, i.e. in this kind of data structure items with higher priority are placed at the front of the queue. In this case, the letter frequency is used as the priority indicator with lower letter frequencies having higher priority.

```text
CREATE leaf node for each letter
    ADD all leaf nodes to priority queue
    LOOP WHILE more than one node in priority queue
        REMOVE two nodes from priority queue*
        CREATE new node with two removed nodes as children
        SET new node’s priority to sum of two child node priorities
        ADD new node to priority queue
    END LOOP
REMOVE remaining node from priority queue SET node as root
```

> [!note]
> Any node pair is permitted When more than two items have the same priority.

The third step of the algorithm is to traverse the constructed binary tree to build Huffman Codes for each letter. To do this all links within the tree must be labelled 0 or 1. By convention, each left child link is a 0 and each right child link is a 1. Figure 1 gives an example binary tree for the example string.

<img width="511" alt="ExampleBinaryTree" src="https://github.com/user-attachments/assets/c08793cc-1a27-44fe-b2cb-311c0f354540">

*Figure 1 - Example Binary Tree*

Each Huffman Code is found by traversing the tree from the root node to the letter in question. Table 2 shows the result of traversing the tree for each letter in the example string.

| Letter  | Huffman Code |
|:-------:|:------------:|
| `space` |     `00`     |
|   `o`   |     `11`     |
|   `t`   |    `011`     |
|   `b`   |    `010`     |
|   `e`   |    `100`     |
|   `n`   |    `1010`    |
|   `r`   |    `1011`    |

*Table 2 - Huffman Codes*

The project structure is described below, remove as necessary:

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

This project uses CMake and Clang/Clang++ to build the executables. It contains a wrapper Makefile to run different configurations.

Run the following command to install the project dependencies via Homebrew:

```shell
brew install llvm cmake cppcheck
```

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
