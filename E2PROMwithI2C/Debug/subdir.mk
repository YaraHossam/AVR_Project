################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Pro.c \
../I2C_Pro.c \
../LCD_Pro.c \
../main_APP.c 

OBJS += \
./DIO_Pro.o \
./I2C_Pro.o \
./LCD_Pro.o \
./main_APP.o 

C_DEPS += \
./DIO_Pro.d \
./I2C_Pro.d \
./LCD_Pro.d \
./main_APP.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


