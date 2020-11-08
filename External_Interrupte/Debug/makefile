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
External_Interrupte.lss \

FLASH_IMAGE += \
External_Interrupte.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: External_Interrupte.elf secondary-outputs

# Tool invocations
External_Interrupte.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,External_Interrupte.map -mmcu=atmega32 -o "External_Interrupte.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

External_Interrupte.lss: External_Interrupte.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S External_Interrupte.elf  >"External_Interrupte.lss"
	@echo 'Finished building: $@'
	@echo ' '

External_Interrupte.hex: External_Interrupte.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex External_Interrupte.elf  "External_Interrupte.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: External_Interrupte.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 External_Interrupte.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: External_Interrupte.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:External_Interrupte.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) External_Interrupte.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
