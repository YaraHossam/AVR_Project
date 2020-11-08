################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Pro.c \
../Keypad_Pro.c \
../LCD_Pro.c \
../fun_pro.c \
../main_storehouse.c \
../seven_segment_Pro.c 

OBJS += \
./DIO_Pro.o \
./Keypad_Pro.o \
./LCD_Pro.o \
./fun_pro.o \
./main_storehouse.o \
./seven_segment_Pro.o 

C_DEPS += \
./DIO_Pro.d \
./Keypad_Pro.d \
./LCD_Pro.d \
./fun_pro.d \
./main_storehouse.d \
./seven_segment_Pro.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


