# FE7 EU (AE7X) matching build.
#
# Rebuilds fe7eu.gba from:
#   - the split asm modules in asm/eu (functions not yet converted to C),
#   - validated C functions compiled with agbcc from refs/fe7j/src,
#   - baserom fill chunks for the not-yet-decompiled regions,
# and verifies the result against fe7eu.sha1.

BUILD   := build
AS      := arm-none-eabi-as
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy
STRIP   := arm-none-eabi-strip
CPP     := arm-none-eabi-cpp
CC1     := tools/agbcc/agbcc

ASM_OBJS  := $(patsubst asm/eu/%.s,$(BUILD)/asm/eu/%.o,$(wildcard asm/eu/*.s))
FILL_OBJS := $(patsubst %.s,%.o,$(wildcard $(BUILD)/gen/*.s))
C_SRCS    := $(shell cat config/c-integrated-files.txt 2>/dev/null)
C_OBJS    := $(patsubst refs/fe7j/src/%.c,$(BUILD)/c/%.o,$(C_SRCS))
OBJS      := $(ASM_OBJS) $(FILL_OBJS) $(C_OBJS)

# per-file optimisation overrides (mirrors the FE7J makefile)
OFLAGS_irq := -O0
OFLAGS_random := -O0
OFLAGS_agb-sram := -O1
OFLAGS_hardware := -O0
OFLAGS_move-data := -O0
OFLAGS_oam := -O0

.PHONY: all compare clean

all: fe7eu.gba

$(BUILD)/asm/eu/%.o: asm/eu/%.s
	@mkdir -p $(@D)
	$(AS) -mcpu=arm7tdmi -I . $< -o $@

$(BUILD)/gen/%.o: $(BUILD)/gen/%.s
	$(AS) -mcpu=arm7tdmi -I . $< -o $@

$(BUILD)/c/%.o: refs/fe7j/src/%.c config/c-integrated.json scripts/filter_c_sections.py scripts/patch_relocs_from_rom.py
	@mkdir -p $(@D)
	$(CPP) -Irefs/fe7j/tools/agbcc/include -iquote refs/fe7j/include \
		-iquote refs/fe7j -nostdinc -undef $< | \
		iconv -f UTF-8 -t CP932 | \
		$(CC1) -g -mthumb-interwork -Wimplicit -Wparentheses -fhex-asm \
		-ffix-debug-line -ffunction-sections -O2 $(OFLAGS_$*) -o $(BUILD)/c/$*.s
	python3 scripts/filter_c_sections.py --manifest config/c-integrated.json \
		--file $* < $(BUILD)/c/$*.s > $(BUILD)/c/$*.keep.s
	printf '.text\n\t.align\t2, 0\n' >> $(BUILD)/c/$*.keep.s
	$(AS) -mcpu=arm7tdmi -I refs/fe7j/include $(BUILD)/c/$*.keep.s -o $@
	python3 scripts/patch_relocs_from_rom.py --manifest config/c-integrated.json \
		--rom rom/fe7eu.gba $@
	$(STRIP) -N .gcc2_compiled. $@

fe7eu.elf: $(OBJS) fe7eu.lds
	$(LD) -T fe7eu.lds -o $@ $(OBJS)

fe7eu.gba: fe7eu.elf
	$(OBJCOPY) -O binary $< $@

compare: fe7eu.gba
	sha1sum -c fe7eu.sha1

clean:
	rm -rf $(BUILD) fe7eu.elf fe7eu.gba
