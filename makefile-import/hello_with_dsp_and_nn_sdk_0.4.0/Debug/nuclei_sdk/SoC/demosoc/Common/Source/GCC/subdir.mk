################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../nuclei_sdk/SoC/demosoc/Common/Source/GCC/intexc_demosoc.S \
../nuclei_sdk/SoC/demosoc/Common/Source/GCC/intexc_demosoc_s.S \
../nuclei_sdk/SoC/demosoc/Common/Source/GCC/startup_demosoc.S 

OBJS += \
./nuclei_sdk/SoC/demosoc/Common/Source/GCC/intexc_demosoc.o \
./nuclei_sdk/SoC/demosoc/Common/Source/GCC/intexc_demosoc_s.o \
./nuclei_sdk/SoC/demosoc/Common/Source/GCC/startup_demosoc.o 

S_UPPER_DEPS += \
./nuclei_sdk/SoC/demosoc/Common/Source/GCC/intexc_demosoc.d \
./nuclei_sdk/SoC/demosoc/Common/Source/GCC/intexc_demosoc_s.d \
./nuclei_sdk/SoC/demosoc/Common/Source/GCC/startup_demosoc.d 


# Each subdirectory must supply rules for building sources it contributes
nuclei_sdk/SoC/demosoc/Common/Source/GCC/%.o: ../nuclei_sdk/SoC/demosoc/Common/Source/GCC/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv-nuclei-elf-gcc -march=rv32imac -mabi=ilp32 -mtune=nuclei-300-series -mcmodel=medlow -mno-save-restore -O2 -ffunction-sections -fdata-sections -fno-common --specs=nano.specs --specs=nosys.specs  -g -x assembler-with-cpp -D__IDE_RV_CORE=n300 -DBOOT_HARTID=0 -DRUNMODE_IC_EN=0 -DRUNMODE_DC_EN=0 -DRUNMODE_CCM_EN=0 -DDOWNLOAD_MODE=DOWNLOAD_MODE_ILM -DDOWNLOAD_MODE_STRING=\"ILM\" -I"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/NMSIS/Core/Include" -I"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/NMSIS/DSP/Include" -I"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/NMSIS/DSP/PrivateInclude" -I"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/NMSIS/NN/Include" -I"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/SoC/demosoc/Common/Include" -I"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/SoC/demosoc/Board/nuclei_fpga_eval/Include" -I"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/application" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


