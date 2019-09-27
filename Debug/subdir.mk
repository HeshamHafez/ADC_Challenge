################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../ADC_cfg.c \
../DIO.c \
../TImer.c \
../lcd.c \
../main.c \
../pwm.c 

OBJS += \
./ADC.o \
./ADC_cfg.o \
./DIO.o \
./TImer.o \
./lcd.o \
./main.o \
./pwm.o 

C_DEPS += \
./ADC.d \
./ADC_cfg.d \
./DIO.d \
./TImer.d \
./lcd.d \
./main.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


