BUILD_DIR=build
include $(N64_INST)/include/n64.mk

N64_CXXFLAGS += -std=c++14

src = main.cpp

assets_png = $(wildcard assets/*.png)

assets_conv = $(addprefix filesystem/,$(notdir $(assets_png:%.png=%.sprite)))

MKSPRITE_FLAGS ?=

all: Quasar64.z64

OBJS = $(BUILD_DIR)/main.o

filesystem/%.sprite: assets/%.png
	@mkdir -p $(dir $@)
	@echo "    [SPRITE] $@"
	@$(N64_MKSPRITE) -f RGBA16 --compress -o "$(dir $@)" "$<"

$(BUILD_DIR)/Quasar64.dfs: $(assets_conv)
$(BUILD_DIR)/Quasar64.elf: $(src:%.cpp=$(BUILD_DIR)/%.o)


$(BUILD_DIR)/main.elf: $(OBJS)

Quasar64.z64: N64_ROM_TITLE="Quasar64"
Quasar64.z64: $(BUILD_DIR)/Quasar64.dfs

clean:
	rm -rf $(BUILD_DIR) filesystem/ Quasar64.z64

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean
