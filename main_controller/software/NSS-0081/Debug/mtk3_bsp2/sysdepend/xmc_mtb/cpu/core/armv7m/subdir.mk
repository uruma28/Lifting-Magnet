################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/cpu_cntl.c \
../mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/exc_hdr.c \
../mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/sys_start.c 

S_UPPER_SRCS += \
../mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/dispatch.S 

OBJS += \
./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/cpu_cntl.o \
./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/dispatch.o \
./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/exc_hdr.o \
./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/sys_start.o 

S_UPPER_DEPS += \
./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/dispatch.d 

C_DEPS += \
./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/cpu_cntl.d \
./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/exc_hdr.d \
./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/sys_start.d 


# Each subdirectory must supply rules for building sources it contributes
mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/%.o mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/%.su mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/%.cyclo: ../mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/%.c mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -D_STM32CUBE_NUCLEO_G474_ -DARM_MATH_CM4 -c -I../Core/Inc -I"D:/work/STM32CubeIDE/STM32G474_test/Drivers/CMSIS/DSP/Include" -ID:/work/STM32CubeIDE/STM32G474_test/mtk3_bsp2 -ID:/work/STM32CubeIDE/STM32G474_test/mtk3_bsp2/include -ID:/work/STM32CubeIDE/STM32G474_test/mtk3_bsp2/mtkernel/kernel/knlinc -ID:/work/STM32CubeIDE/STM32G474_test/mtk3_bsp2/config -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/%.o: ../mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/%.S mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -D_STM32CUBE_NUCLEO_G474_ -c -I"D:/work/STM32CubeIDE/STM32G474_test/mtk3_bsp2" -I"D:/work/STM32CubeIDE/STM32G474_test/mtk3_bsp2/config" -I"D:/work/STM32CubeIDE/STM32G474_test/mtk3_bsp2/mtkernel/kernel/knlinc" -I"D:/work/STM32CubeIDE/STM32G474_test/mtk3_bsp2/include" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-mtk3_bsp2-2f-sysdepend-2f-xmc_mtb-2f-cpu-2f-core-2f-armv7m

clean-mtk3_bsp2-2f-sysdepend-2f-xmc_mtb-2f-cpu-2f-core-2f-armv7m:
	-$(RM) ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/cpu_cntl.cyclo ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/cpu_cntl.d ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/cpu_cntl.o ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/cpu_cntl.su ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/dispatch.d ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/dispatch.o ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/exc_hdr.cyclo ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/exc_hdr.d ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/exc_hdr.o ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/exc_hdr.su ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/sys_start.cyclo ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/sys_start.d ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/sys_start.o ./mtk3_bsp2/sysdepend/xmc_mtb/cpu/core/armv7m/sys_start.su

.PHONY: clean-mtk3_bsp2-2f-sysdepend-2f-xmc_mtb-2f-cpu-2f-core-2f-armv7m

