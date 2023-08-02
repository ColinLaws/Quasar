BUILD_DIR=build
include $(N64_INST)/include/n64.mk

N64_CXXFLAGS += -std=c++17

src = Core/App.cpp \
	  Core/Entity.cpp \
	  Core/EntityManager.cpp \
	  Core/Scene.cpp \
	  Components/IComponent.cpp \
	  Components/TransformComponent.cpp \
	  Components/ModelComponent.cpp \
	  Components/CameraComponent.cpp \
	  Systems/SystemsPipeline.cpp \
	  Systems/System.cpp \
	  Systems/RenderInitializationSystem.cpp \
	  Systems/RenderUninitializationSystem.cpp \
	  Systems/ModelRendererSystem.cpp \
	  Systems/TransformSystem.cpp \
	  Systems/InitializationSystem.cpp \
	  main.cpp 

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

OBJS = $(BUILD_DIR)/main.o \
	   $(BUILD_DIR)/Core/App.o \
	   $(BUILD_DIR)/Core/Entity.o \
       $(BUILD_DIR)/Core/EntityManager.o \
	   $(BUILD_DIR)/Core/Scene.o \
	   $(BUILD_DIR)/Components/IComponent.o \
	   $(BUILD_DIR)/Components/TransformComponent.o \
	   $(BUILD_DIR)/Systems/RenderInitializationSystem.o \
	   $(BUILD_DIR)/Systems/RenderUninitializationSystem.o \
	   $(BUILD_DIR)/Systems/ModelRendererSystem.o \
	   $(BUILD_DIR)/Systems/InitializationSystem.o \
	   $(BUILD_DIR)/Systems/TransformSystem.o \
	   $(BUILD_DIR)/Systems/System.o \
	   $(BUILD_DIR)/Systems/SystemsPipeline.o

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
