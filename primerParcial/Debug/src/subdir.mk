################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/primelParcialv1.c \
../src/utn_inputs.c \
../src/utn_structBibCliente.c \
../src/utn_structBibPedido.c 

OBJS += \
./src/primelParcialv1.o \
./src/utn_inputs.o \
./src/utn_structBibCliente.o \
./src/utn_structBibPedido.o 

C_DEPS += \
./src/primelParcialv1.d \
./src/utn_inputs.d \
./src/utn_structBibCliente.d \
./src/utn_structBibPedido.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


