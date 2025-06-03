################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/tm_com.c 

OBJS += \
./mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/tm_com.o 

C_DEPS += \
./mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/tm_com.d 


# Each subdirectory must supply rules for building sources it contributes
mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/%.o mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/%.su mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/%.cyclo: ../mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/%.c mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -D_STM32CUBE_NUCLEO_G474_ -DARM_MATH_CM4 -c -I../Core/Inc -I"D:/work/APB-1251C/software/NSS-0079/Drivers/CMSIS/DSP/Include" -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2 -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/include -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/mtkernel/kernel/knlinc -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/config -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mtk3_bsp2-2f-sysdepend-2f-ra_fsp-2f-lib-2f-libtm-2f-ek_ra8m1

clean-mtk3_bsp2-2f-sysdepend-2f-ra_fsp-2f-lib-2f-libtm-2f-ek_ra8m1:
	-$(RM) ./mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/tm_com.cyclo ./mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/tm_com.d ./mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/tm_com.o ./mtk3_bsp2/sysdepend/ra_fsp/lib/libtm/ek_ra8m1/tm_com.su

.PHONY: clean-mtk3_bsp2-2f-sysdepend-2f-ra_fsp-2f-lib-2f-libtm-2f-ek_ra8m1

