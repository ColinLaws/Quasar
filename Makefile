BUILD_DIR=build
include $(N64_INST)/include/n64.mk

N64_CXXFLAGS += -std=c++14

src = Core/GameObject.cpp main.cpp 

assets_png = $(wildcard assets/*.png)
assets_glb = $(wildcard assets/*.glb)
assets_ttf = $(wildcard assets/*.ttf)

assets_conv = $(addprefix filesystem/,$(notdir $(assets_png:%.png=%.sprite))) \
			  $(addprefix filesystem/,$(notdir $(assets_glb:%.glb=%.model64))) \
			  $(addprefix filesystem/,$(notdir $(assets_ttf:%.ttf=%.font64)))

MKSPRITE_FLAGS ?=
MKFONT_FLAGS ?=
MKMODEL_FLAGS ?=

TITLE = Quasar64

TARGET = $(TITLE).z64

N64_ROM_TITLE = "Quasar 64"

all: $(TARGET)

OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/Core/GameObject.o

filesystem/%.sprite: assets/%.png
	@mkdir -p $(dir $@)
	@echo "    [SPRITE] $@"
	@$(N64_MKSPRITE) -f RGBA16 --compress -o "$(dir $@)" "$<"

filesystem/%.model64: assets/%.glb
	@mkdir -p $(dir $@)
	@echo "    [COPY] $@"
	@$(N64_MKMODEL) $(MKMODEL_FLAGS) -o "$(dir $@)" "$<"

filesystem/%.font64: assets/%.ttf
	@mkdir -p $(dir $@)
	@echo "    [FONT] $@"
	@$(N64_MKFONT) $(MKFONT_FLAGS) --compress -o "$(dir $@)" "$<"

filesystem/Pacifico.font64: MKFONT_FLAGS+=--size 18

$(BUILD_DIR)/$(TITLE).dfs: $(assets_conv)
$(BUILD_DIR)/$(TITLE).elf: $(src:%.cpp=$(BUILD_DIR)/%.o)

$(TITLE).z64: N64_ROM_TITLE="$(TITLE)"
$(TITLE).z64: $(BUILD_DIR)/$(TITLE).dfs

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.elf filesystem/ $(TITLE).z64

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean
