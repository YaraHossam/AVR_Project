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
Gate_security.lss \

FLASH_IMAGE += \
Gate_security.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Gate_security.elf secondary-outputs

# Tool invocations
Gate_security.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Gate_security.map -mmcu=atmega32 -o "Gate_security.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Gate_security.lss: Gate_security.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Gate_security.elf  >"Gate_security.lss"
	@echo 'Finished building: $@'
	@echo ' '

Gate_security.hex: Gate_security.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Gate_security.elf  "Gate_security.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Gate_security.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Gate_security.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Gate_security.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
