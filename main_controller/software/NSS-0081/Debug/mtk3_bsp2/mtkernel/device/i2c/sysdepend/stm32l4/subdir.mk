################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/i2c_stm32l4.c 

OBJS += \
./mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/i2c_stm32l4.o 

C_DEPS += \
./mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/i2c_stm32l4.d 


# Each subdirectory must supply rules for building sources it contributes
mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/%.o mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/%.su mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/%.cyclo: ../mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/%.c mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -D_STM32CUBE_NUCLEO_G474_ -DARM_MATH_CM4 -c -I../Core/Inc -I"D:/work/APB-1251C/software/NSS-0079/Drivers/CMSIS/DSP/Include" -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2 -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/include -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/mtkernel/kernel/knlinc -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/config -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mtk3_bsp2-2f-mtkernel-2f-device-2f-i2c-2f-sysdepend-2f-stm32l4

clean-mtk3_bsp2-2f-mtkernel-2f-device-2f-i2c-2f-sysdepend-2f-stm32l4:
	-$(RM) ./mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/i2c_stm32l4.cyclo ./mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/i2c_stm32l4.d ./mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/i2c_stm32l4.o ./mtk3_bsp2/mtkernel/device/i2c/sysdepend/stm32l4/i2c_stm32l4.su

.PHONY: clean-mtk3_bsp2-2f-mtkernel-2f-device-2f-i2c-2f-sysdepend-2f-stm32l4

