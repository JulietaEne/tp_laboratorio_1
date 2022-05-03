################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/album.c \
../src/arrays.c \
../src/artista.c \
../src/fecha.c \
../src/genero.c \
../src/pp-labo1_nakasone.c \
../src/tipo-artista.c \
../src/tp.c \
../src/utn.c \
../src/validaciones.c 

C_DEPS += \
./src/album.d \
./src/arrays.d \
./src/artista.d \
./src/fecha.d \
./src/genero.d \
./src/pp-labo1_nakasone.d \
./src/tipo-artista.d \
./src/tp.d \
./src/utn.d \
./src/validaciones.d 

OBJS += \
./src/album.o \
./src/arrays.o \
./src/artista.o \
./src/fecha.o \
./src/genero.o \
./src/pp-labo1_nakasone.o \
./src/tipo-artista.o \
./src/tp.o \
./src/utn.o \
./src/validaciones.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/album.d ./src/album.o ./src/arrays.d ./src/arrays.o ./src/artista.d ./src/artista.o ./src/fecha.d ./src/fecha.o ./src/genero.d ./src/genero.o ./src/pp-labo1_nakasone.d ./src/pp-labo1_nakasone.o ./src/tipo-artista.d ./src/tipo-artista.o ./src/tp.d ./src/tp.o ./src/utn.d ./src/utn.o ./src/validaciones.d ./src/validaciones.o

.PHONY: clean-src

