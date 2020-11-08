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
T_2N2222.lss \

FLASH_IMAGE += \
T_2N2222.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: T_2N2222.elf secondary-outputs

# Tool invocations
T_2N2222.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,T_2N2222.map -mmcu=atmega16 -o "T_2N2222.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

T_2N2222.lss: T_2N2222.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S T_2N2222.elf  >"T_2N2222.lss"
	@echo 'Finished building: $@'
	@echo ' '

T_2N2222.hex: T_2N2222.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex T_2N2222.elf  "T_2N2222.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: T_2N2222.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 T_2N2222.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) T_2N2222.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
