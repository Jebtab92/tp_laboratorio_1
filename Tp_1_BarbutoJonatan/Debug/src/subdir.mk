################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BibliotecaTp1.c \
../src/Tp_1_BarbutoJonatan.c 

OBJS += \
./src/BibliotecaTp1.o \
./src/Tp_1_BarbutoJonatan.o 

C_DEPS += \
./src/BibliotecaTp1.d \
./src/Tp_1_BarbutoJonatan.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


