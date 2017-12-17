TARGET_EXEC ?= lisp

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) -I/usr/local/include

LDFLAGS := 

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++11

.PHONY: all
all: $(BUILD_DIR)/$(TARGET_EXEC) ./build/library.lisp

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

./build/library.lisp: ./src/library.lisp
	cp ./src/library.lisp ./build/library.lisp

./src/library.lisp:
	touch ./src/library.lisp

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
