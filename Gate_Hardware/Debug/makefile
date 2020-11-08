################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
StoreHouse_New.lss \

FLASH_IMAGE += \
StoreHouse_New.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: StoreHouse_New.elf secondary-outputs

# Tool invocations
StoreHouse_New.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,StoreHouse_New.map -mmcu=atmega16 -o "StoreHouse_New.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

StoreHouse_New.lss: StoreHouse_New.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S StoreHouse_New.elf  >"StoreHouse_New.lss"
	@echo 'Finished building: $@'
	@echo ' '

StoreHouse_New.hex: StoreHouse_New.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex StoreHouse_New.elf  "StoreHouse_New.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: StoreHouse_New.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 StoreHouse_New.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) StoreHouse_New.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
