################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Bluetooth/Blutooth_program.c \
../MCAL/Bluetooth/USART_program.c 

OBJS += \
./MCAL/Bluetooth/Blutooth_program.o \
./MCAL/Bluetooth/USART_program.o 

C_DEPS += \
./MCAL/Bluetooth/Blutooth_program.d \
./MCAL/Bluetooth/USART_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Bluetooth/%.o: ../MCAL/Bluetooth/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


