################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../boot.s

CPP_SRCS += \
../kernel.cpp \
../processes.cpp \
../runbatch.cpp 

CPP_DEPS += \
./kernel.d \
./processes.d \
./runbatch.d 

OBJS += \
./kernel.o \
./processes.o \
./runbatch.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -g3 -Wall -c -fmessage-length=0 -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./kernel.d ./kernel.o ./processes.d ./processes.o ./runbatch.d ./runbatch.o

.PHONY: clean--2e-

