################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/componentes/cmu.c" \
"../Sources/componentes/sharp.c" \

C_SRCS += \
../Sources/componentes/cmu.c \
../Sources/componentes/sharp.c \

OBJS += \
./Sources/componentes/cmu_c.obj \
./Sources/componentes/sharp_c.obj \

OBJS_QUOTED += \
"./Sources/componentes/cmu_c.obj" \
"./Sources/componentes/sharp_c.obj" \

C_DEPS += \
./Sources/componentes/cmu_c.d \
./Sources/componentes/sharp_c.d \

OBJS_OS_FORMAT += \
./Sources/componentes/cmu_c.obj \
./Sources/componentes/sharp_c.obj \

C_DEPS_QUOTED += \
"./Sources/componentes/cmu_c.d" \
"./Sources/componentes/sharp_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/componentes/cmu_c.obj: ../Sources/componentes/cmu.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/componentes/cmu.args" -o "Sources/componentes/cmu_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/componentes/%.d: ../Sources/componentes/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/componentes/sharp_c.obj: ../Sources/componentes/sharp.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/componentes/sharp.args" -o "Sources/componentes/sharp_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


