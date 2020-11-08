################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Pro.c \
../RTOS_Pro.c \
../Timer0_Pro.c \
../main_RTOS.c 

OBJS += \
./DIO_Pro.o \
./RTOS_Pro.o \
./Timer0_Pro.o \
./main_RTOS.o 

C_DEPS += \
./DIO_Pro.d \
./RTOS_Pro.d \
./Timer0_Pro.d \
./main_RTOS.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


