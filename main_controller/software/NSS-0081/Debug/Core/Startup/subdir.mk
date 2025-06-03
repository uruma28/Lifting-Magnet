################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32g474vetx.s 

OBJS += \
./Core/Startup/startup_stm32g474vetx.o 

S_DEPS += \
./Core/Startup/startup_stm32g474vetx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -D_STM32CUBE_NUCLEO_G474_ -c -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/config" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/mtkernel/kernel/knlinc" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/include" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g474vetx.d ./Core/Startup/startup_stm32g474vetx.o

.PHONY: clean-Core-2f-Startup

