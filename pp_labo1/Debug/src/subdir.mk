################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP_[2].c \
../src/arrays.c \
../src/passenger.c \
../src/tp.c \
../src/utn.c \
../src/validaciones.c 

OBJS += \
./src/TP_[2].o \
./src/arrays.o \
./src/passenger.o \
./src/tp.o \
./src/utn.o \
./src/validaciones.o 

C_DEPS += \
./src/TP_[2].d \
./src/arrays.d \
./src/passenger.d \
./src/tp.d \
./src/utn.d \
./src/validaciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


