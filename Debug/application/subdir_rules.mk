################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
application/ADC_Control.obj: ../application/ADC_Control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/achi/workspace_v7/Alarm_CC3220S_tirtos_ccs" --include_path="C:/ti/simplelink_cc32xx_sdk_1_60_00_04/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/include" --define=cc3220s -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="application/ADC_Control.d_raw" --obj_directory="application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

application/GPIO_control.obj: ../application/GPIO_control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/achi/workspace_v7/Alarm_CC3220S_tirtos_ccs" --include_path="C:/ti/simplelink_cc32xx_sdk_1_60_00_04/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/include" --define=cc3220s -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="application/GPIO_control.d_raw" --obj_directory="application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

application/I2C_Utils.obj: ../application/I2C_Utils.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/achi/workspace_v7/Alarm_CC3220S_tirtos_ccs" --include_path="C:/ti/simplelink_cc32xx_sdk_1_60_00_04/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/include" --define=cc3220s -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="application/I2C_Utils.d_raw" --obj_directory="application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

application/PWM_Control.obj: ../application/PWM_Control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/achi/workspace_v7/Alarm_CC3220S_tirtos_ccs" --include_path="C:/ti/simplelink_cc32xx_sdk_1_60_00_04/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/include" --define=cc3220s -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="application/PWM_Control.d_raw" --obj_directory="application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

application/UART_control.obj: ../application/UART_control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/achi/workspace_v7/Alarm_CC3220S_tirtos_ccs" --include_path="C:/ti/simplelink_cc32xx_sdk_1_60_00_04/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/include" --define=cc3220s -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="application/UART_control.d_raw" --obj_directory="application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

application/i2c_control.obj: ../application/i2c_control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/achi/workspace_v7/Alarm_CC3220S_tirtos_ccs" --include_path="C:/ti/simplelink_cc32xx_sdk_1_60_00_04/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/include" --define=cc3220s -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="application/i2c_control.d_raw" --obj_directory="application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

application/main.obj: ../application/main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/achi/workspace_v7/Alarm_CC3220S_tirtos_ccs" --include_path="C:/ti/simplelink_cc32xx_sdk_1_60_00_04/kernel/tirtos/packages/ti/sysbios/posix" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.6.LTS/include" --define=cc3220s -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="application/main.d_raw" --obj_directory="application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


