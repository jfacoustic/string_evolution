################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Community.cpp \
../src/Organism.cpp \
../src/Population.cpp \
../src/String_Evolution.cpp 

OBJS += \
./src/Community.o \
./src/Organism.o \
./src/Population.o \
./src/String_Evolution.o 

CPP_DEPS += \
./src/Community.d \
./src/Organism.d \
./src/Population.d \
./src/String_Evolution.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


