################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Pro.c \
../Keypad_Pro.c \
../LCD_Pro.c \
../main_of_app.c 

OBJS += \
./DIO_Pro.o \
./Keypad_Pro.o \
./LCD_Pro.o \
./main_of_app.o 

C_DEPS += \
./DIO_Pro.d \
./Keypad_Pro.d \
./LCD_Pro.d \
./main_of_app.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


