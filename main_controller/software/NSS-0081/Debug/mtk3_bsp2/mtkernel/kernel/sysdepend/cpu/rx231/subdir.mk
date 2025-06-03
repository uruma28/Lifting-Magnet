################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_tbl.c \
../mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/intvect_tbl.c 

S_UPPER_SRCS += \
../mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_ent.S 

OBJS += \
./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_ent.o \
./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_tbl.o \
./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/intvect_tbl.o 

S_UPPER_DEPS += \
./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_ent.d 

C_DEPS += \
./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_tbl.d \
./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/intvect_tbl.d 


# Each subdirectory must supply rules for building sources it contributes
mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/%.o: ../mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/%.S mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -D_STM32CUBE_NUCLEO_G474_ -c -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/config" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/mtkernel/kernel/knlinc" -I"D:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/include" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/%.o mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/%.su mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/%.cyclo: ../mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/%.c mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -D_STM32CUBE_NUCLEO_G474_ -DARM_MATH_CM4 -c -I../Core/Inc -I"D:/work/APB-1251C/software/NSS-0079/Drivers/CMSIS/DSP/Include" -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2 -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/include -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/mtkernel/kernel/knlinc -ID:/work/APB-1251C/software/NSS-0079/mtk3_bsp2/config -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mtk3_bsp2-2f-mtkernel-2f-kernel-2f-sysdepend-2f-cpu-2f-rx231

clean-mtk3_bsp2-2f-mtkernel-2f-kernel-2f-sysdepend-2f-cpu-2f-rx231:
	-$(RM) ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_ent.d ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_ent.o ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_tbl.cyclo ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_tbl.d ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_tbl.o ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/hllint_tbl.su ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/intvect_tbl.cyclo ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/intvect_tbl.d ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/intvect_tbl.o ./mtk3_bsp2/mtkernel/kernel/sysdepend/cpu/rx231/intvect_tbl.su

.PHONY: clean-mtk3_bsp2-2f-mtkernel-2f-kernel-2f-sysdepend-2f-cpu-2f-rx231

