
# output binary
BIN := waifu_gatcha

DATABASE := sqlite3

# source files
SRCS := $(wildcard src/*.cpp)                             \
		$(wildcard src/database/$(DATABASE).cpp)                             \
		$(wildcard src/domain/*.cpp)                               \
		$(wildcard src/interface/*.cpp)                             \
		$(wildcard src/interface/cli/*.cpp)                             \

# files included in the tarball generated by 'make dist' (e.g. add LICENSE file)
DISTFILES := $(BIN)

# filename of the tar archive generated by 'make dist'
DISTOUTPUT := $(BIN).tar.gz

# intermediate directory for generated object files
OBJDIR := .o
# intermediate directory for generated dependency files
DEPDIR := .d

# object files, auto generated from source files
OBJS := $(patsubst %,$(OBJDIR)/%.o,$(basename $(SRCS)))
# dependency files, auto generated from source files
DEPS := $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS)))

# compilers (at least gcc and clang) don't create the subdirectories automatically
$(shell mkdir -p $(dir $(OBJS)) >/dev/null)
$(shell mkdir -p $(dir $(DEPS)) >/dev/null)

# C++ compiler
CXX := g++
# linker
LD := g++
# tar
TAR := tar

# C/C++ flags
export INCDIR := $(CURDIR)/include/

CPPFLAGS := -D __database__sqlite3__      # Database
CPPFLAGS += -D __interface__cli__         # Interface
CPPFLAGS += -D __check_interface__        # Check Interface
CPPFLAGS += -std=c++11 -Wall -Wextra -Werror -Wa,--warn
CPPFLAGS += -I $(INCDIR)

# DATABASE INCLUDE
CPPFLAGS += -l sqlite3

# linker flags
LDFLAGS := 
# linker flags: libraries to link (e.g. -lfoo)
LDLIBS := -lsqlite3
# flags required for dependency generation; passed to compilers
DEPFLAGS = -MT $@ -MD -MP -MF $(DEPDIR)/$*.Td

# compile C++ source files
COMPILE.cc = $(CXX) $(DEPFLAGS) $(CPPFLAGS) -c -o $@
# precompile step
PRECOMPILE =
# postcompile step
POSTCOMPILE = mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d

all: $(BIN) clean

dist: $(DISTFILES)
	$(TAR) -cvzf $(DISTOUTPUT) $^

.PHONY: clean
clean:
	$(RM) -r $(OBJDIR) $(DEPDIR)

.PHONY: distclean
distclean: clean
	$(RM) $(BIN) $(DISTOUTPUT)

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) $^ $(LDLIBS) -o $@
	

.PHONY: run
run: clean
	./$(BIN)

$(OBJDIR)/%.o: %.cpp
$(OBJDIR)/%.o: %.cpp $(DEPDIR)/%.d
	$(PRECOMPILE)
	$(COMPILE.cc) $<
	$(POSTCOMPILE)

.PRECIOUS: $(DEPDIR)/%.d
$(DEPDIR)/%.d: ;

-include $(DEPS)