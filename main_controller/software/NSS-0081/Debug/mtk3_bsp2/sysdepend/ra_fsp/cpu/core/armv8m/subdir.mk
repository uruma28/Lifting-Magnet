################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/cpu_cntl.c \
../mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/exc_hdr.c \
../mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/interrupt.c \
../mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/sys_start.c 

S_UPPER_SRCS += \
../mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/dispatch.S 

OBJS += \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/cpu_cntl.o \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/dispatch.o \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/exc_hdr.o \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/interrupt.o \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/sys_start.o 

S_UPPER_DEPS += \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/dispatch.d 

C_DEPS += \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/cpu_cntl.d \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/exc_hdr.d \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/interrupt.d \
./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/sys_start.d 


# Each subdirectory must supply rules for building sources it contributes
mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/%.o mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/%.su mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/%.cyclo: ../mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/%.c mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -D_STM32CUBE_NUCLEO_G474_ -DARM_MATH_CM4 -c -I../Core/Inc -I"D:/work/APB-1251C/software/NSS-0079/Drivers/CMSIS/DSP/Include" -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2 -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/include -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/mtkernel/kernel/knlinc -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/config -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/%.o: ../mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/%.S mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -D_STM32CUBE_NUCLEO_G474_ -c -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/config" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/mtkernel/kernel/knlinc" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/include" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-mtk3_bsp2-2f-sysdepend-2f-ra_fsp-2f-cpu-2f-core-2f-armv8m

clean-mtk3_bsp2-2f-sysdepend-2f-ra_fsp-2f-cpu-2f-core-2f-armv8m:
	-$(RM) ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/cpu_cntl.cyclo ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/cpu_cntl.d ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/cpu_cntl.o ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/cpu_cntl.su ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/dispatch.d ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/dispatch.o ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/exc_hdr.cyclo ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/exc_hdr.d ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/exc_hdr.o ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/exc_hdr.su ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/interrupt.cyclo ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/interrupt.d ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/interrupt.o ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/interrupt.su ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/sys_start.cyclo ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/sys_start.d ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/sys_start.o ./mtk3_bsp2/sysdepend/ra_fsp/cpu/core/armv8m/sys_start.su

.PHONY: clean-mtk3_bsp2-2f-sysdepend-2f-ra_fsp-2f-cpu-2f-core-2f-armv8m

