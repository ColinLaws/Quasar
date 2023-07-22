BUILD_DIR=build
include $(N64_INST)/include/n64.mk

src = main.c
assets_png = $(wildcard assets/*.png)

assets_conv = $(addprefix filesystem/,$(notdir $(assets_png:%.png=%.sprite)))

MKSPRITE_FLAGS ?=

all: Quasar64.z64

filesystem/%.sprite: assets/%.png
	@mkdir -p $(dir $@)
	@echo "    [SPRITE] $@"
	@$(N64_MKSPRITE) -f RGBA16 --compress -o "$(dir $@)" "$<"

$(BUILD_DIR)/Quasar64.dfs: $(assets_conv)
$(BUILD_DIR)/Quasar64.elf: $(src:%.c=$(BUILD_DIR)/%.o)

Quasar64.z64: N64_ROM_TITLE="GL Demo"
Quasar64.z64: $(BUILD_DIR)/Quasar64.dfs

clean:
	rm -rf $(BUILD_DIR) filesystem/ Quasar64.z64

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean
