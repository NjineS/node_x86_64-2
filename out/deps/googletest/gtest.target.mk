# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := gtest
DEFS_Debug := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DGTEST_HAS_POSIX_RE=0' \
	'-DGTEST_LANG_CXX11=1' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-fno-strict-aliasing \
	-std=gnu++20

INCS_Debug := \
	-I$(srcdir)/deps/googletest \
	-I$(srcdir)/deps/googletest/include

DEFS_Release := \
	'-D_GLIBCXX_USE_CXX11_ABI=1' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNODE_OPENSSL_CONF_NAME=nodejs_conf' \
	'-DICU_NO_USER_DATA_OVERRIDE' \
	'-D__STDC_FORMAT_MACROS' \
	'-DOPENSSL_NO_PINSHARED' \
	'-DOPENSSL_THREADS' \
	'-DGTEST_HAS_POSIX_RE=0' \
	'-DGTEST_LANG_CXX11=1'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-fno-strict-aliasing \
	-std=gnu++20

INCS_Release := \
	-I$(srcdir)/deps/googletest \
	-I$(srcdir)/deps/googletest/include

OBJS := \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest-assertion-result.o \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest-death-test.o \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest-filepath.o \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest-matchers.o \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest-port.o \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest-printers.o \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest-test-part.o \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest-typed-test.o \
	$(obj).target/$(TARGET)/deps/googletest/src/gtest.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(obj).target/deps/googletest/gtest_prod.stamp

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS :=

$(obj).target/deps/googletest/libgtest.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/deps/googletest/libgtest.a: LIBS := $(LIBS)
$(obj).target/deps/googletest/libgtest.a: TOOLSET := $(TOOLSET)
$(obj).target/deps/googletest/libgtest.a: $(OBJS)
	$(call create_thin_archive,$@,$^)

# Add target alias
.PHONY: gtest
gtest: $(obj).target/deps/googletest/libgtest.a

# Add target alias to "all" target.
.PHONY: all
all: gtest

