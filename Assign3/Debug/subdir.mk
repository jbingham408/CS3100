################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Assign3.o \
../Assign3Fib.o \
../Assign3e.o \
../Assign3pi.o 

CPP_SRCS += \
../Assign3.cpp \
../Assign3Fib.cpp \
../Assign3e.cpp \
../Assign3pi.cpp 

OBJS += \
./Assign3.o \
./Assign3Fib.o \
./Assign3e.o \
./Assign3pi.o 

CPP_DEPS += \
./Assign3.d \
./Assign3Fib.d \
./Assign3e.d \
./Assign3pi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


