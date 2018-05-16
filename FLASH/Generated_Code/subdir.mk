################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/BLUETOOTHserial.c" \
"../Generated_Code/Bit1.c" \
"../Generated_Code/CMUserial.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/IO_Map.c" \
"../Generated_Code/M1bit.c" \
"../Generated_Code/M1pwm.c" \
"../Generated_Code/M2bit.c" \
"../Generated_Code/M2pwm.c" \
"../Generated_Code/PE_Timer.c" \
"../Generated_Code/SHARPadc.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/BLUETOOTHserial.c \
../Generated_Code/Bit1.c \
../Generated_Code/CMUserial.c \
../Generated_Code/Cpu.c \
../Generated_Code/IO_Map.c \
../Generated_Code/M1bit.c \
../Generated_Code/M1pwm.c \
../Generated_Code/M2bit.c \
../Generated_Code/M2pwm.c \
../Generated_Code/PE_Timer.c \
../Generated_Code/SHARPadc.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/BLUETOOTHserial_c.obj \
./Generated_Code/Bit1_c.obj \
./Generated_Code/CMUserial_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/M1bit_c.obj \
./Generated_Code/M1pwm_c.obj \
./Generated_Code/M2bit_c.obj \
./Generated_Code/M2pwm_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/SHARPadc_c.obj \
./Generated_Code/Vectors_c.obj \

OBJS_QUOTED += \
"./Generated_Code/BLUETOOTHserial_c.obj" \
"./Generated_Code/Bit1_c.obj" \
"./Generated_Code/CMUserial_c.obj" \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/IO_Map_c.obj" \
"./Generated_Code/M1bit_c.obj" \
"./Generated_Code/M1pwm_c.obj" \
"./Generated_Code/M2bit_c.obj" \
"./Generated_Code/M2pwm_c.obj" \
"./Generated_Code/PE_Timer_c.obj" \
"./Generated_Code/SHARPadc_c.obj" \
"./Generated_Code/Vectors_c.obj" \

C_DEPS += \
./Generated_Code/BLUETOOTHserial_c.d \
./Generated_Code/Bit1_c.d \
./Generated_Code/CMUserial_c.d \
./Generated_Code/Cpu_c.d \
./Generated_Code/IO_Map_c.d \
./Generated_Code/M1bit_c.d \
./Generated_Code/M1pwm_c.d \
./Generated_Code/M2bit_c.d \
./Generated_Code/M2pwm_c.d \
./Generated_Code/PE_Timer_c.d \
./Generated_Code/SHARPadc_c.d \
./Generated_Code/Vectors_c.d \

OBJS_OS_FORMAT += \
./Generated_Code/BLUETOOTHserial_c.obj \
./Generated_Code/Bit1_c.obj \
./Generated_Code/CMUserial_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/M1bit_c.obj \
./Generated_Code/M1pwm_c.obj \
./Generated_Code/M2bit_c.obj \
./Generated_Code/M2pwm_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/SHARPadc_c.obj \
./Generated_Code/Vectors_c.obj \

C_DEPS_QUOTED += \
"./Generated_Code/BLUETOOTHserial_c.d" \
"./Generated_Code/Bit1_c.d" \
"./Generated_Code/CMUserial_c.d" \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/IO_Map_c.d" \
"./Generated_Code/M1bit_c.d" \
"./Generated_Code/M1pwm_c.d" \
"./Generated_Code/M2bit_c.d" \
"./Generated_Code/M2pwm_c.d" \
"./Generated_Code/PE_Timer_c.d" \
"./Generated_Code/SHARPadc_c.d" \
"./Generated_Code/Vectors_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/BLUETOOTHserial_c.obj: ../Generated_Code/BLUETOOTHserial.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/BLUETOOTHserial.args" -o "Generated_Code/BLUETOOTHserial_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/Bit1_c.obj: ../Generated_Code/Bit1.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/Bit1.args" -o "Generated_Code/Bit1_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/CMUserial_c.obj: ../Generated_Code/CMUserial.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/CMUserial.args" -o "Generated_Code/CMUserial_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/Cpu.args" -o "Generated_Code/Cpu_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IO_Map_c.obj: ../Generated_Code/IO_Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/IO_Map.args" -o "Generated_Code/IO_Map_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M1bit_c.obj: ../Generated_Code/M1bit.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M1bit.args" -o "Generated_Code/M1bit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M1pwm_c.obj: ../Generated_Code/M1pwm.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M1pwm.args" -o "Generated_Code/M1pwm_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M2bit_c.obj: ../Generated_Code/M2bit.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M2bit.args" -o "Generated_Code/M2bit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M2pwm_c.obj: ../Generated_Code/M2pwm.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M2pwm.args" -o "Generated_Code/M2pwm_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_Timer_c.obj: ../Generated_Code/PE_Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/PE_Timer.args" -o "Generated_Code/PE_Timer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SHARPadc_c.obj: ../Generated_Code/SHARPadc.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/SHARPadc.args" -o "Generated_Code/SHARPadc_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/Vectors.args" -o "Generated_Code/Vectors_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


