################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arch/AMD64/cr0.cpp \
../arch/AMD64/efer.cpp \
../arch/AMD64/gdt.cpp \
../arch/AMD64/idt.cpp 

CPP_DEPS += \
./arch/AMD64/cr0.d \
./arch/AMD64/efer.d \
./arch/AMD64/gdt.d \
./arch/AMD64/idt.d 

OBJS += \
./arch/AMD64/cr0.o \
./arch/AMD64/efer.o \
./arch/AMD64/gdt.o \
./arch/AMD64/idt.o 


# Each subdirectory must supply rules for building sources it contributes
arch/AMD64/%.o: ../arch/AMD64/%.cpp arch/AMD64/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -nostdinc -I"/home/sean/Dropbox/eclipse-workspace/SKkernel/include" -I"/home/sean/Dropbox/eclipse-workspace/sklib/include" -O2 -c -fmessage-length=0 -Wnoexcept -ffreestanding -Wattributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-arch-2f-AMD64

clean-arch-2f-AMD64:
	-$(RM) ./arch/AMD64/cr0.d ./arch/AMD64/cr0.o ./arch/AMD64/efer.d ./arch/AMD64/efer.o ./arch/AMD64/gdt.d ./arch/AMD64/gdt.o ./arch/AMD64/idt.d ./arch/AMD64/idt.o

.PHONY: clean-arch-2f-AMD64

