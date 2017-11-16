################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Assignment3/Assign3.cpp \
../Assignment3/Assign3Fib.cpp \
../Assignment3/Assign3e.cpp \
../Assignment3/Assign3pi.cpp 

OBJS += \
./Assignment3/Assign3.o \
./Assignment3/Assign3Fib.o \
./Assignment3/Assign3e.o \
./Assignment3/Assign3pi.o 

CPP_DEPS += \
./Assignment3/Assign3.d \
./Assignment3/Assign3Fib.d \
./Assignment3/Assign3e.d \
./Assignment3/Assign3pi.d 


# Each subdirectory must supply rules for building sources it contributes
Assignment3/%.o: ../Assignment3/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


