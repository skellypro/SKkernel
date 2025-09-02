################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arch/i686/cr0.cpp \
../arch/i686/eflags.cpp 

CPP_DEPS += \
./arch/i686/cr0.d \
./arch/i686/eflags.d 

OBJS += \
./arch/i686/cr0.o \
./arch/i686/eflags.o 


# Each subdirectory must supply rules for building sources it contributes
arch/i686/%.o: ../arch/i686/%.cpp arch/i686/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -nostdinc -I"/home/sean/Dropbox/eclipse-workspace/SKkernel/include" -I"/home/sean/Dropbox/eclipse-workspace/sklib/include" -O2 -c -fmessage-length=0 -Wnoexcept -ffreestanding -Wattributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-arch-2f-i686

clean-arch-2f-i686:
	-$(RM) ./arch/i686/cr0.d ./arch/i686/cr0.o ./arch/i686/eflags.d ./arch/i686/eflags.o

.PHONY: clean-arch-2f-i686

