# Define project name
PROJECT_NAME = HuffmanCoding

# Define LLVM components
CC = /opt/homebrew/opt/llvm/bin/clang
CXX = /opt/homebrew/opt/llvm/bin/clang++
SCAN_BUILD = /opt/homebrew/opt/llvm/bin/scan-build
CLANG_TIDY = /opt/homebrew/opt/llvm/bin/clang-tidy
LLVM_COV = /opt/homebrew/opt/llvm/bin/llvm-cov
LLVM_PROFDATA = /opt/homebrew/opt/llvm/bin/llvm-profdata
CLANG_FORMAT = /opt/homebrew/opt/llvm/bin/clang-format

# Define addtional components
CMAKE = /opt/homebrew/bin/cmake
CTEST = /opt/homebrew/bin/ctest
CPPCHECK = /opt/homebrew/bin/cppcheck

# Define directories
BUILD_DIR = build
SRC_DIR = src
TESTS_DIR = tests
TESTS_BIN_DIR = $(BUILD_DIR)/tests
DEPS_DIR = $(BUILD_DIR)/_deps

# Define files
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
HEADER_FILES := $(shell find $(SRC_DIR) -type f -name '*.h')
TEST_FILES := $(shell find $(TESTS_DIR) -type f -name '*.cpp')
COMPILE_COMMANDS = $(BUILD_DIR)/compile_commands.json

# Define the test executable
TEST_EXECUTABLE =$(TESTS_BIN_DIR)/test_$(PROJECT_NAME)
COV_REPORT_DIR = $(TESTS_BIN_DIR)/coverage_report
COV_IGNORE_REGEX = $(DEPS_DIR)/*

# Define the default target to build the executable
.PHONY: all
all: compile link

# Define a rule to compile with CMake
.PHONY: compile
compile:
	mkdir -p $(BUILD_DIR)
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX)

# Define a rule to link with CMake
.PHONY: link
link:
	$(CMAKE) --build $(BUILD_DIR)
	cp $(COMPILE_COMMANDS) .

# Define a rule to run unit tests
.PHONY: tests
tests: all
	@echo "Running unit tests..."
	cd $(TESTS_BIN_DIR) && \
		GTEST_COLOR=1 ${CTEST} --output-on-failure --verbose

# Define a rule to remove existing build files
.PHONY: clean
clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)

# Define a rule to compile with scan-build
.PHONY: scan-build
scan-build: clean
	mkdir -p $(BUILD_DIR)
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -DCMAKE_C_COMPILER_LAUNCHER=$(SCAN_BUILD) -DCMAKE_CXX_COMPILER_LAUNCHER=$(SCAN_BUILD)
	$(CMAKE) --build $(BUILD_DIR)

# Define a rule to perform static analysis with clang-tidy 
.PHONY: clang-tidy
clang-tidy: all
	@echo "Performing static analysis with clang-tidy..."
	$(CLANG_TIDY) -p $(BUILD_DIR) $(SRC_FILES) $(HEADER_FILES)

# Define a rule to export coverage info
.PHONY: coverage
coverage: tests
	$(LLVM_PROFDATA) merge -sparse $(TESTS_BIN_DIR)/default.profraw -o $(TESTS_BIN_DIR)/merged.profdata
	$(LLVM_COV) export -format=lcov -instr-profile=$(TESTS_BIN_DIR)/merged.profdata $(TEST_EXECUTABLE) --ignore-filename-regex=$(COV_IGNORE_REGEX) > $(TESTS_BIN_DIR)/coverage.info

# Define a rule to generate a coverage HTML report
.PHONY: coverage-html
coverage-html: tests
	$(LLVM_PROFDATA) merge -sparse $(TESTS_BIN_DIR)/default.profraw -o $(TESTS_BIN_DIR)/merged.profdata
	$(LLVM_COV) show $(TEST_EXECUTABLE) -instr-profile=$(TESTS_BIN_DIR)/merged.profdata -format=html -output-dir=$(COV_REPORT_DIR) --ignore-filename-regex=$(COV_IGNORE_REGEX)
	open $(COV_REPORT_DIR)/index.html
	
# Define a rule to format using clang-format
.PHONY: clang-format
clang-format:
	clang-format --verbose -i $(SRC_FILES) $(HEADER_FILES) $(TEST_FILES)
	
# Define a rule to check format using clang-format
.PHONY: clang-format-dry-run
clang-format-dry-run:
	clang-format --verbose --dry-run $(SRC_FILES) $(HEADER_FILES) $(TEST_FILES)
	
# Define a rule to lint using cppcheck
.PHONY: cppcheck
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive $(SRC_DIR) $(TESTS_DIR) -I src