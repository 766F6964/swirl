COMPILER = clang
COMPILER_FLAGS = -g -Wall #-Werror
LINKER_FLAGS = -lncursesw -lm

PROG_NAME = swirl
SOURCE_FILES = $(wildcard ../src/*.c) \
       		   $(wildcard ../deps/dotdotdot/src/*.c)

prog:
	$(COMPILER) -o $(PROG_NAME) $(SOURCE_FILES) $(COMPILER_FLAGS) $(LINKER_FLAGS)
clean:
	rm swirl