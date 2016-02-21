################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/subdir.mk
-include Rtc_by_Makuna/src/subdir.mk
-include Rtc_by_Makuna/examples/DS3231_StoreIt/subdir.mk
-include Rtc_by_Makuna/examples/DS3231_Simple/subdir.mk
-include Rtc_by_Makuna/examples/DS3231_Alarms/subdir.mk
-include Rtc_by_Makuna/examples/DS1307_Simple/subdir.mk
-include Rtc_by_Makuna/examples/DS1307_Memory/subdir.mk
-include Libraries/Wire/utility/subdir.mk
-include Libraries/Wire/subdir.mk
-include Libraries/SoftwareSerial/subdir.mk
-include Libraries/SPI/subdir.mk
-include Libraries/SD/src/utility/subdir.mk
-include Libraries/SD/src/subdir.mk
-include Flash/subdir.mk
-include Fishino/src/subdir.mk
-include Fishino/examples/FishinoWiFiWebServer/subdir.mk
-include Fishino/examples/FishinoWiFiWebSecureClient/subdir.mk
-include Fishino/examples/FishinoWiFiWebClientRepeating/subdir.mk
-include Fishino/examples/FishinoTwitterSearch/subdir.mk
-include Fishino/examples/FishinoScanNetworks/subdir.mk
-include Fishino/examples/FishinoESPIo/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
arduino.ar \

ELF += \
fishino_monitoring_base.elf \

EEP += \
fishino_monitoring_base.eep \

FLASH_IMAGE += \
fishino_monitoring_base.hex \


# All Target
all: fishino_monitoring_base

# Tool invocations
fishino_monitoring_base: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/tools/avr/bin/avr-size" -A "/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release/fishino_monitoring_base.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/tools/avr/bin/avr-ar" rcs  "/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

fishino_monitoring_base.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p  -o "/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release/fishino_monitoring_base.elf"   $(LINK_OBJ) $(AR)  "/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release/arduino.ar" "-L/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

fishino_monitoring_base.eep: $(ELF)
	@echo 'Create eeprom image'
	"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release/fishino_monitoring_base.elf" "/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release/fishino_monitoring_base.eep"
	@echo 'Finished building: $@'
	@echo ' '

fishino_monitoring_base.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom  "/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release/fishino_monitoring_base.elf" "/Users/asettl010/workspaces/arduino2/fishino_monitoring_base/Release/fishino_monitoring_base.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(ELF)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(INO_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) fishino_monitoring_base
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
