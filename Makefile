BUILD_DIR=build
include $(N64_INST)/include/n64.mk

N64_CXXFLAGS += -std=c++14

src = main.cpp GameObject.o

assets_png = $(wildcard assets/*.png)
assets_glb = $(wildcard assets/*.glb)
assets_ttf = $(wildcard assets/*.ttf)

assets_conv = $(addprefix filesystem/,$(notdir $(assets_png:%.png=%.sprite))) \
			  $(addprefix filesystem/,$(notdir $(assets_glb:%.glb=%.model64))) \
			  $(addprefix filesystem/,$(notdir $(assets_ttf:%.ttf=%.font64)))

MKSPRITE_FLAGS ?=
MKFONT_FLAGS ?=
MKMODEL_FLAGS ?=

all: Quasar64.z64

OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/GameObject.o

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

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

$(BUILD_DIR)/Quasar64.dfs: $(assets_conv)
$(BUILD_DIR)/Quasar64.elf: $(src:%.cpp=$(BUILD_DIR)/%.o)


$(BUILD_DIR)/main.elf: $(OBJS)

Quasar64.z64: N64_ROM_TITLE="Quasar64"
Quasar64.z64: $(BUILD_DIR)/Quasar64.dfs

clean:
	rm -rf $(BUILD_DIR) filesystem/ Quasar64.z64

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean
