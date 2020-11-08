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
E2PROMwithI2C.lss \

FLASH_IMAGE += \
E2PROMwithI2C.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: E2PROMwithI2C.elf secondary-outputs

# Tool invocations
E2PROMwithI2C.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,E2PROMwithI2C.map -mmcu=atmega16 -o "E2PROMwithI2C.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

E2PROMwithI2C.lss: E2PROMwithI2C.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S E2PROMwithI2C.elf  >"E2PROMwithI2C.lss"
	@echo 'Finished building: $@'
	@echo ' '

E2PROMwithI2C.hex: E2PROMwithI2C.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex E2PROMwithI2C.elf  "E2PROMwithI2C.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: E2PROMwithI2C.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 E2PROMwithI2C.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) E2PROMwithI2C.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
