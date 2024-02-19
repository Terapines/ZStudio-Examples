################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include nuclei_sdk/SoC/demosoc/Common/Source/Stubs/newlib/subdir.mk
-include nuclei_sdk/SoC/demosoc/Common/Source/GCC/subdir.mk
-include nuclei_sdk/SoC/demosoc/Common/Source/Drivers/subdir.mk
-include nuclei_sdk/SoC/demosoc/Common/Source/subdir.mk
-include application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
hello_with_dsp_and_nn_sdk_0.4.0.hex \

SECONDARY_LIST += \
hello_with_dsp_and_nn_sdk_0.4.0.lst \

SECONDARY_SIZE += \
hello_with_dsp_and_nn_sdk_0.4.0.siz \


# All Target
all: hello_with_dsp_and_nn_sdk_0.4.0.elf secondary-outputs

# Tool invocations
hello_with_dsp_and_nn_sdk_0.4.0.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU RISC-V Cross C++ Linker'
	riscv-nuclei-elf-g++ -march=rv32imac -mabi=ilp32 -mtune=nuclei-300-series -mcmodel=medlow -mno-save-restore -O2 -ffunction-sections -fdata-sections -fno-common --specs=nano.specs --specs=nosys.specs  -g -T "/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/SoC/demosoc/Board/nuclei_fpga_eval/Source/GCC/gcc_demosoc_ilm.ld" -nostartfiles -Xlinker --gc-sections -L"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/NMSIS/Library/DSP/GCC" -L"/home/tptuser/NucleiStudio_workspace/hello_with_dsp_and_nn_sdk_0.4.0/nuclei_sdk/NMSIS/Library/NN/GCC" -Wl,-Map,"hello_with_dsp_and_nn_sdk_0.4.0.map" -Wl,--check-sections -u _isatty -u _write -u _sbrk -u _read -u _close -u _fstat -u _lseek -o "hello_with_dsp_and_nn_sdk_0.4.0.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

hello_with_dsp_and_nn_sdk_0.4.0.hex: hello_with_dsp_and_nn_sdk_0.4.0.elf
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv-nuclei-elf-objcopy -O ihex "hello_with_dsp_and_nn_sdk_0.4.0.elf"  "hello_with_dsp_and_nn_sdk_0.4.0.hex"
	@echo 'Finished building: $@'
	@echo ' '

hello_with_dsp_and_nn_sdk_0.4.0.lst: hello_with_dsp_and_nn_sdk_0.4.0.elf
	@echo 'Invoking: GNU RISC-V Cross Create Listing'
	riscv-nuclei-elf-objdump --source --all-headers --demangle --line-numbers --wide "hello_with_dsp_and_nn_sdk_0.4.0.elf" > "hello_with_dsp_and_nn_sdk_0.4.0.lst"
	@echo 'Finished building: $@'
	@echo ' '

hello_with_dsp_and_nn_sdk_0.4.0.siz: hello_with_dsp_and_nn_sdk_0.4.0.elf
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv-nuclei-elf-size --format=berkeley "hello_with_dsp_and_nn_sdk_0.4.0.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) hello_with_dsp_and_nn_sdk_0.4.0.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
