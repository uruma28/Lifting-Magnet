################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/cpu_clock.c \
../mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/devinit.c \
../mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/hw_setting.c \
../mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/power_save.c 

OBJS += \
./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/cpu_clock.o \
./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/devinit.o \
./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/hw_setting.o \
./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/power_save.o 

C_DEPS += \
./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/cpu_clock.d \
./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/devinit.d \
./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/hw_setting.d \
./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/power_save.d 


# Each subdirectory must supply rules for building sources it contributes
mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/%.o mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/%.su mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/%.cyclo: ../mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/%.c mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -D_STM32CUBE_NUCLEO_G474_ -DARM_MATH_CM4 -c -I../Core/Inc -I"D:/work/APB-1251C/software/NSS-0079/Drivers/CMSIS/DSP/Include" -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2 -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/include -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/mtkernel/kernel/knlinc -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/config -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mtk3_bsp2-2f-mtkernel-2f-kernel-2f-sysdepend-2f-iote_rx231

clean-mtk3_bsp2-2f-mtkernel-2f-kernel-2f-sysdepend-2f-iote_rx231:
	-$(RM) ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/cpu_clock.cyclo ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/cpu_clock.d ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/cpu_clock.o ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/cpu_clock.su ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/devinit.cyclo ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/devinit.d ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/devinit.o ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/devinit.su ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/hw_setting.cyclo ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/hw_setting.d ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/hw_setting.o ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/hw_setting.su ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/power_save.cyclo ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/power_save.d ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/power_save.o ./mtk3_bsp2/mtkernel/kernel/sysdepend/iote_rx231/power_save.su

.PHONY: clean-mtk3_bsp2-2f-mtkernel-2f-kernel-2f-sysdepend-2f-iote_rx231

