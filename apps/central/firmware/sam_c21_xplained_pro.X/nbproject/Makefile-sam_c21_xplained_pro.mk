#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-sam_c21_xplained_pro.mk)" "nbproject/Makefile-local-sam_c21_xplained_pro.mk"
include nbproject/Makefile-local-sam_c21_xplained_pro.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=sam_c21_xplained_pro
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/sam_c21_xplained_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/sam_c21_xplained_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/application/command/command.c ../src/application/console/console.c ../src/application/rf/rf.c ../src/application/states/states.c ../src/application/states/states_error.c ../src/application/states/states_alarm.c ../src/application/states/states_learn.c ../src/application/states/states_keep_alive.c ../src/application/states/states_idle.c ../src/application/states/states_init.c ../src/application/states/states_connection_verification.c ../src/application/states/states_update.c ../src/application/test/test.c ../src/application/application.c ../src/config/sam_c21_xplained_pro/bsp/bsp.c ../src/config/sam_c21_xplained_pro/library/emulated_eeprom/emulated_eeprom.c ../src/config/sam_c21_xplained_pro/osal/osal_freertos.c ../src/config/sam_c21_xplained_pro/peripheral/clock/plib_clock.c ../src/config/sam_c21_xplained_pro/peripheral/eic/plib_eic.c ../src/config/sam_c21_xplained_pro/peripheral/evsys/plib_evsys.c ../src/config/sam_c21_xplained_pro/peripheral/nvic/plib_nvic.c ../src/config/sam_c21_xplained_pro/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/sam_c21_xplained_pro/peripheral/port/plib_port.c ../src/config/sam_c21_xplained_pro/peripheral/rtc/plib_rtc_timer.c ../src/config/sam_c21_xplained_pro/peripheral/sercom/spi_master/plib_sercom1_spi_master.c ../src/config/sam_c21_xplained_pro/peripheral/sercom/usart/plib_sercom4_usart.c ../src/config/sam_c21_xplained_pro/stdio/xc32_monitor.c ../src/config/sam_c21_xplained_pro/system/command/src/sys_command.c ../src/config/sam_c21_xplained_pro/system/console/src/sys_console.c ../src/config/sam_c21_xplained_pro/system/console/src/sys_console_uart.c ../src/config/sam_c21_xplained_pro/system/debug/src/sys_debug.c ../src/config/sam_c21_xplained_pro/system/int/src/sys_int.c ../src/config/sam_c21_xplained_pro/system/reset/sys_reset.c ../src/config/sam_c21_xplained_pro/system/time/src/sys_time.c ../src/config/sam_c21_xplained_pro/exceptions.c ../src/config/sam_c21_xplained_pro/initialization.c ../src/config/sam_c21_xplained_pro/interrupts.c ../src/config/sam_c21_xplained_pro/libc_syscalls.c ../src/config/sam_c21_xplained_pro/startup_xc32.c ../src/config/sam_c21_xplained_pro/freertos_hooks.c ../src/config/sam_c21_xplained_pro/tasks.c ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.c ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c ../src/third_party/rtos/FreeRTOS/Source/croutine.c ../src/third_party/rtos/FreeRTOS/Source/list.c ../src/third_party/rtos/FreeRTOS/Source/queue.c ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c ../src/third_party/rtos/FreeRTOS/Source/timers.c ../src/third_party/rtos/FreeRTOS/Source/event_groups.c ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c ../src/main.c ../src/app.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1793397138/command.o ${OBJECTDIR}/_ext/1794512798/console.o ${OBJECTDIR}/_ext/1274956685/rf.o ${OBJECTDIR}/_ext/1212921563/states.o ${OBJECTDIR}/_ext/1212921563/states_error.o ${OBJECTDIR}/_ext/1212921563/states_alarm.o ${OBJECTDIR}/_ext/1212921563/states_learn.o ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o ${OBJECTDIR}/_ext/1212921563/states_idle.o ${OBJECTDIR}/_ext/1212921563/states_init.o ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o ${OBJECTDIR}/_ext/1212921563/states_update.o ${OBJECTDIR}/_ext/1167757227/test.o ${OBJECTDIR}/_ext/801483606/application.o ${OBJECTDIR}/_ext/1038944351/bsp.o ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o ${OBJECTDIR}/_ext/2142890735/osal_freertos.o ${OBJECTDIR}/_ext/1818098789/plib_clock.o ${OBJECTDIR}/_ext/435409140/plib_eic.o ${OBJECTDIR}/_ext/1815949303/plib_evsys.o ${OBJECTDIR}/_ext/612500555/plib_nvic.o ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o ${OBJECTDIR}/_ext/612447404/plib_port.o ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o ${OBJECTDIR}/_ext/653373664/sys_command.o ${OBJECTDIR}/_ext/1110085844/sys_console.o ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o ${OBJECTDIR}/_ext/1437254184/sys_debug.o ${OBJECTDIR}/_ext/1386091972/sys_int.o ${OBJECTDIR}/_ext/200569009/sys_reset.o ${OBJECTDIR}/_ext/1715113378/sys_time.o ${OBJECTDIR}/_ext/1383211985/exceptions.o ${OBJECTDIR}/_ext/1383211985/initialization.o ${OBJECTDIR}/_ext/1383211985/interrupts.o ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o ${OBJECTDIR}/_ext/1383211985/startup_xc32.o ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o ${OBJECTDIR}/_ext/1383211985/tasks.o ${OBJECTDIR}/_ext/1624415188/port.o ${OBJECTDIR}/_ext/1624415188/portasm.o ${OBJECTDIR}/_ext/1665200909/heap_1.o ${OBJECTDIR}/_ext/404212886/croutine.o ${OBJECTDIR}/_ext/404212886/list.o ${OBJECTDIR}/_ext/404212886/queue.o ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o ${OBJECTDIR}/_ext/404212886/timers.o ${OBJECTDIR}/_ext/404212886/event_groups.o ${OBJECTDIR}/_ext/404212886/stream_buffer.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/app.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1793397138/command.o.d ${OBJECTDIR}/_ext/1794512798/console.o.d ${OBJECTDIR}/_ext/1274956685/rf.o.d ${OBJECTDIR}/_ext/1212921563/states.o.d ${OBJECTDIR}/_ext/1212921563/states_error.o.d ${OBJECTDIR}/_ext/1212921563/states_alarm.o.d ${OBJECTDIR}/_ext/1212921563/states_learn.o.d ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o.d ${OBJECTDIR}/_ext/1212921563/states_idle.o.d ${OBJECTDIR}/_ext/1212921563/states_init.o.d ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o.d ${OBJECTDIR}/_ext/1212921563/states_update.o.d ${OBJECTDIR}/_ext/1167757227/test.o.d ${OBJECTDIR}/_ext/801483606/application.o.d ${OBJECTDIR}/_ext/1038944351/bsp.o.d ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o.d ${OBJECTDIR}/_ext/2142890735/osal_freertos.o.d ${OBJECTDIR}/_ext/1818098789/plib_clock.o.d ${OBJECTDIR}/_ext/435409140/plib_eic.o.d ${OBJECTDIR}/_ext/1815949303/plib_evsys.o.d ${OBJECTDIR}/_ext/612500555/plib_nvic.o.d ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o.d ${OBJECTDIR}/_ext/612447404/plib_port.o.d ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o.d ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o.d ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o.d ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o.d ${OBJECTDIR}/_ext/653373664/sys_command.o.d ${OBJECTDIR}/_ext/1110085844/sys_console.o.d ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o.d ${OBJECTDIR}/_ext/1437254184/sys_debug.o.d ${OBJECTDIR}/_ext/1386091972/sys_int.o.d ${OBJECTDIR}/_ext/200569009/sys_reset.o.d ${OBJECTDIR}/_ext/1715113378/sys_time.o.d ${OBJECTDIR}/_ext/1383211985/exceptions.o.d ${OBJECTDIR}/_ext/1383211985/initialization.o.d ${OBJECTDIR}/_ext/1383211985/interrupts.o.d ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o.d ${OBJECTDIR}/_ext/1383211985/startup_xc32.o.d ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o.d ${OBJECTDIR}/_ext/1383211985/tasks.o.d ${OBJECTDIR}/_ext/1624415188/port.o.d ${OBJECTDIR}/_ext/1624415188/portasm.o.d ${OBJECTDIR}/_ext/1665200909/heap_1.o.d ${OBJECTDIR}/_ext/404212886/croutine.o.d ${OBJECTDIR}/_ext/404212886/list.o.d ${OBJECTDIR}/_ext/404212886/queue.o.d ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d ${OBJECTDIR}/_ext/404212886/timers.o.d ${OBJECTDIR}/_ext/404212886/event_groups.o.d ${OBJECTDIR}/_ext/404212886/stream_buffer.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1793397138/command.o ${OBJECTDIR}/_ext/1794512798/console.o ${OBJECTDIR}/_ext/1274956685/rf.o ${OBJECTDIR}/_ext/1212921563/states.o ${OBJECTDIR}/_ext/1212921563/states_error.o ${OBJECTDIR}/_ext/1212921563/states_alarm.o ${OBJECTDIR}/_ext/1212921563/states_learn.o ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o ${OBJECTDIR}/_ext/1212921563/states_idle.o ${OBJECTDIR}/_ext/1212921563/states_init.o ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o ${OBJECTDIR}/_ext/1212921563/states_update.o ${OBJECTDIR}/_ext/1167757227/test.o ${OBJECTDIR}/_ext/801483606/application.o ${OBJECTDIR}/_ext/1038944351/bsp.o ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o ${OBJECTDIR}/_ext/2142890735/osal_freertos.o ${OBJECTDIR}/_ext/1818098789/plib_clock.o ${OBJECTDIR}/_ext/435409140/plib_eic.o ${OBJECTDIR}/_ext/1815949303/plib_evsys.o ${OBJECTDIR}/_ext/612500555/plib_nvic.o ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o ${OBJECTDIR}/_ext/612447404/plib_port.o ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o ${OBJECTDIR}/_ext/653373664/sys_command.o ${OBJECTDIR}/_ext/1110085844/sys_console.o ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o ${OBJECTDIR}/_ext/1437254184/sys_debug.o ${OBJECTDIR}/_ext/1386091972/sys_int.o ${OBJECTDIR}/_ext/200569009/sys_reset.o ${OBJECTDIR}/_ext/1715113378/sys_time.o ${OBJECTDIR}/_ext/1383211985/exceptions.o ${OBJECTDIR}/_ext/1383211985/initialization.o ${OBJECTDIR}/_ext/1383211985/interrupts.o ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o ${OBJECTDIR}/_ext/1383211985/startup_xc32.o ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o ${OBJECTDIR}/_ext/1383211985/tasks.o ${OBJECTDIR}/_ext/1624415188/port.o ${OBJECTDIR}/_ext/1624415188/portasm.o ${OBJECTDIR}/_ext/1665200909/heap_1.o ${OBJECTDIR}/_ext/404212886/croutine.o ${OBJECTDIR}/_ext/404212886/list.o ${OBJECTDIR}/_ext/404212886/queue.o ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o ${OBJECTDIR}/_ext/404212886/timers.o ${OBJECTDIR}/_ext/404212886/event_groups.o ${OBJECTDIR}/_ext/404212886/stream_buffer.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/app.o

# Source Files
SOURCEFILES=../src/application/command/command.c ../src/application/console/console.c ../src/application/rf/rf.c ../src/application/states/states.c ../src/application/states/states_error.c ../src/application/states/states_alarm.c ../src/application/states/states_learn.c ../src/application/states/states_keep_alive.c ../src/application/states/states_idle.c ../src/application/states/states_init.c ../src/application/states/states_connection_verification.c ../src/application/states/states_update.c ../src/application/test/test.c ../src/application/application.c ../src/config/sam_c21_xplained_pro/bsp/bsp.c ../src/config/sam_c21_xplained_pro/library/emulated_eeprom/emulated_eeprom.c ../src/config/sam_c21_xplained_pro/osal/osal_freertos.c ../src/config/sam_c21_xplained_pro/peripheral/clock/plib_clock.c ../src/config/sam_c21_xplained_pro/peripheral/eic/plib_eic.c ../src/config/sam_c21_xplained_pro/peripheral/evsys/plib_evsys.c ../src/config/sam_c21_xplained_pro/peripheral/nvic/plib_nvic.c ../src/config/sam_c21_xplained_pro/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/sam_c21_xplained_pro/peripheral/port/plib_port.c ../src/config/sam_c21_xplained_pro/peripheral/rtc/plib_rtc_timer.c ../src/config/sam_c21_xplained_pro/peripheral/sercom/spi_master/plib_sercom1_spi_master.c ../src/config/sam_c21_xplained_pro/peripheral/sercom/usart/plib_sercom4_usart.c ../src/config/sam_c21_xplained_pro/stdio/xc32_monitor.c ../src/config/sam_c21_xplained_pro/system/command/src/sys_command.c ../src/config/sam_c21_xplained_pro/system/console/src/sys_console.c ../src/config/sam_c21_xplained_pro/system/console/src/sys_console_uart.c ../src/config/sam_c21_xplained_pro/system/debug/src/sys_debug.c ../src/config/sam_c21_xplained_pro/system/int/src/sys_int.c ../src/config/sam_c21_xplained_pro/system/reset/sys_reset.c ../src/config/sam_c21_xplained_pro/system/time/src/sys_time.c ../src/config/sam_c21_xplained_pro/exceptions.c ../src/config/sam_c21_xplained_pro/initialization.c ../src/config/sam_c21_xplained_pro/interrupts.c ../src/config/sam_c21_xplained_pro/libc_syscalls.c ../src/config/sam_c21_xplained_pro/startup_xc32.c ../src/config/sam_c21_xplained_pro/freertos_hooks.c ../src/config/sam_c21_xplained_pro/tasks.c ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.c ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c ../src/third_party/rtos/FreeRTOS/Source/croutine.c ../src/third_party/rtos/FreeRTOS/Source/list.c ../src/third_party/rtos/FreeRTOS/Source/queue.c ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c ../src/third_party/rtos/FreeRTOS/Source/timers.c ../src/third_party/rtos/FreeRTOS/Source/event_groups.c ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c ../src/main.c ../src/app.c

# Pack Options 
PACK_COMMON_OPTIONS=-I "${CMSIS_DIR}/CMSIS/Core/Include"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-sam_c21_xplained_pro.mk ${DISTDIR}/sam_c21_xplained_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAMC21J18A
MP_LINKER_FILE_OPTION=,--script="..\src\config\sam_c21_xplained_pro\ATSAMC21J18A.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1793397138/command.o: ../src/application/command/command.c  .generated_files/flags/sam_c21_xplained_pro/94297c1fbe856156674963ff54b835ec2532ffe5 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1793397138" 
	@${RM} ${OBJECTDIR}/_ext/1793397138/command.o.d 
	@${RM} ${OBJECTDIR}/_ext/1793397138/command.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1793397138/command.o.d" -o ${OBJECTDIR}/_ext/1793397138/command.o ../src/application/command/command.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1794512798/console.o: ../src/application/console/console.c  .generated_files/flags/sam_c21_xplained_pro/414c97b0a8f01709c8e9027497a29f6c8c056769 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1794512798" 
	@${RM} ${OBJECTDIR}/_ext/1794512798/console.o.d 
	@${RM} ${OBJECTDIR}/_ext/1794512798/console.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1794512798/console.o.d" -o ${OBJECTDIR}/_ext/1794512798/console.o ../src/application/console/console.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1274956685/rf.o: ../src/application/rf/rf.c  .generated_files/flags/sam_c21_xplained_pro/82bf04f0132d2268af468b7d620944996120eeca .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1274956685" 
	@${RM} ${OBJECTDIR}/_ext/1274956685/rf.o.d 
	@${RM} ${OBJECTDIR}/_ext/1274956685/rf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1274956685/rf.o.d" -o ${OBJECTDIR}/_ext/1274956685/rf.o ../src/application/rf/rf.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states.o: ../src/application/states/states.c  .generated_files/flags/sam_c21_xplained_pro/b24edc255c5ad013fdb6bfd24663d6e6c415a884 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states.o.d" -o ${OBJECTDIR}/_ext/1212921563/states.o ../src/application/states/states.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_error.o: ../src/application/states/states_error.c  .generated_files/flags/sam_c21_xplained_pro/91159e4e45b48e60d8250eca242a3a0e2923e607 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_error.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_error.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_error.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_error.o ../src/application/states/states_error.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_alarm.o: ../src/application/states/states_alarm.c  .generated_files/flags/sam_c21_xplained_pro/aa7182158da7b3126d68172875c4d82bc7df541a .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_alarm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_alarm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_alarm.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_alarm.o ../src/application/states/states_alarm.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_learn.o: ../src/application/states/states_learn.c  .generated_files/flags/sam_c21_xplained_pro/5caacdcccb8692f9e0f2b3de8c868b85770fd70d .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_learn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_learn.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_learn.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_learn.o ../src/application/states/states_learn.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_keep_alive.o: ../src/application/states/states_keep_alive.c  .generated_files/flags/sam_c21_xplained_pro/e454418aaa7bafc70a7fbf2fdb3e311f302dce86 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_keep_alive.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o ../src/application/states/states_keep_alive.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_idle.o: ../src/application/states/states_idle.c  .generated_files/flags/sam_c21_xplained_pro/840fb862d1f3736ff7c06ef4e3a2c010bdd5fd8e .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_idle.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_idle.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_idle.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_idle.o ../src/application/states/states_idle.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_init.o: ../src/application/states/states_init.c  .generated_files/flags/sam_c21_xplained_pro/b0f9fc91bd283f1b39285343a5824363f4b17246 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_init.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_init.o ../src/application/states/states_init.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_connection_verification.o: ../src/application/states/states_connection_verification.c  .generated_files/flags/sam_c21_xplained_pro/2855495c79df7ffa30b4649ea282b2f33c80aa8b .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_connection_verification.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o ../src/application/states/states_connection_verification.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_update.o: ../src/application/states/states_update.c  .generated_files/flags/sam_c21_xplained_pro/624d77958f55a5677987770d6ddb0d9c56655170 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_update.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_update.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_update.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_update.o ../src/application/states/states_update.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1167757227/test.o: ../src/application/test/test.c  .generated_files/flags/sam_c21_xplained_pro/3db600c6fe6a41c9f464241ccb3207d271efa7e7 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1167757227" 
	@${RM} ${OBJECTDIR}/_ext/1167757227/test.o.d 
	@${RM} ${OBJECTDIR}/_ext/1167757227/test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1167757227/test.o.d" -o ${OBJECTDIR}/_ext/1167757227/test.o ../src/application/test/test.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/801483606/application.o: ../src/application/application.c  .generated_files/flags/sam_c21_xplained_pro/86b9a0a05e33a98af9775f0bead068c3ad70f93f .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/application.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/application.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/application.o.d" -o ${OBJECTDIR}/_ext/801483606/application.o ../src/application/application.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1038944351/bsp.o: ../src/config/sam_c21_xplained_pro/bsp/bsp.c  .generated_files/flags/sam_c21_xplained_pro/69020e179bed8070d04e4939d12cc7d8a1a97074 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1038944351" 
	@${RM} ${OBJECTDIR}/_ext/1038944351/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1038944351/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1038944351/bsp.o.d" -o ${OBJECTDIR}/_ext/1038944351/bsp.o ../src/config/sam_c21_xplained_pro/bsp/bsp.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/148671750/emulated_eeprom.o: ../src/config/sam_c21_xplained_pro/library/emulated_eeprom/emulated_eeprom.c  .generated_files/flags/sam_c21_xplained_pro/c46fd50298d9babae2a3c36508bb3d2da1cd84c3 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/148671750" 
	@${RM} ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/148671750/emulated_eeprom.o.d" -o ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o ../src/config/sam_c21_xplained_pro/library/emulated_eeprom/emulated_eeprom.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/2142890735/osal_freertos.o: ../src/config/sam_c21_xplained_pro/osal/osal_freertos.c  .generated_files/flags/sam_c21_xplained_pro/6dfb4d5d583cc92cab52d46d04412245c165922c .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2142890735" 
	@${RM} ${OBJECTDIR}/_ext/2142890735/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/2142890735/osal_freertos.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2142890735/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/2142890735/osal_freertos.o ../src/config/sam_c21_xplained_pro/osal/osal_freertos.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1818098789/plib_clock.o: ../src/config/sam_c21_xplained_pro/peripheral/clock/plib_clock.c  .generated_files/flags/sam_c21_xplained_pro/ddb34a24515cdf809797e114d4ea81934658eb96 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1818098789" 
	@${RM} ${OBJECTDIR}/_ext/1818098789/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1818098789/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1818098789/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1818098789/plib_clock.o ../src/config/sam_c21_xplained_pro/peripheral/clock/plib_clock.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/435409140/plib_eic.o: ../src/config/sam_c21_xplained_pro/peripheral/eic/plib_eic.c  .generated_files/flags/sam_c21_xplained_pro/85da654d876d972db70b8c4ce8b1ca8fb4946047 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/435409140" 
	@${RM} ${OBJECTDIR}/_ext/435409140/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/435409140/plib_eic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/435409140/plib_eic.o.d" -o ${OBJECTDIR}/_ext/435409140/plib_eic.o ../src/config/sam_c21_xplained_pro/peripheral/eic/plib_eic.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1815949303/plib_evsys.o: ../src/config/sam_c21_xplained_pro/peripheral/evsys/plib_evsys.c  .generated_files/flags/sam_c21_xplained_pro/487fad75c71bd524187873f16747fb6dc7a1620c .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1815949303" 
	@${RM} ${OBJECTDIR}/_ext/1815949303/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815949303/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1815949303/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1815949303/plib_evsys.o ../src/config/sam_c21_xplained_pro/peripheral/evsys/plib_evsys.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/612500555/plib_nvic.o: ../src/config/sam_c21_xplained_pro/peripheral/nvic/plib_nvic.c  .generated_files/flags/sam_c21_xplained_pro/6052438683ada2592f20bd600d7d17a05d4f04b5 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/612500555" 
	@${RM} ${OBJECTDIR}/_ext/612500555/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/612500555/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/612500555/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/612500555/plib_nvic.o ../src/config/sam_c21_xplained_pro/peripheral/nvic/plib_nvic.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o: ../src/config/sam_c21_xplained_pro/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/sam_c21_xplained_pro/6c6477f613817d23a7f3cbc19d6e978c478b1da7 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1979151395" 
	@${RM} ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o ../src/config/sam_c21_xplained_pro/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/612447404/plib_port.o: ../src/config/sam_c21_xplained_pro/peripheral/port/plib_port.c  .generated_files/flags/sam_c21_xplained_pro/b155ad8d0ce82b29b2f428b75688dea10b3a75b6 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/612447404" 
	@${RM} ${OBJECTDIR}/_ext/612447404/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/612447404/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/612447404/plib_port.o.d" -o ${OBJECTDIR}/_ext/612447404/plib_port.o ../src/config/sam_c21_xplained_pro/peripheral/port/plib_port.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o: ../src/config/sam_c21_xplained_pro/peripheral/rtc/plib_rtc_timer.c  .generated_files/flags/sam_c21_xplained_pro/3696431782e2a8e791b21c3f3a9994e7fcd98159 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/435396306" 
	@${RM} ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o.d" -o ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o ../src/config/sam_c21_xplained_pro/peripheral/rtc/plib_rtc_timer.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o: ../src/config/sam_c21_xplained_pro/peripheral/sercom/spi_master/plib_sercom1_spi_master.c  .generated_files/flags/sam_c21_xplained_pro/b581e2965a1abea3bd23d62fab1708bae4e4f90b .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/30358000" 
	@${RM} ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o.d" -o ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o ../src/config/sam_c21_xplained_pro/peripheral/sercom/spi_master/plib_sercom1_spi_master.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o: ../src/config/sam_c21_xplained_pro/peripheral/sercom/usart/plib_sercom4_usart.c  .generated_files/flags/sam_c21_xplained_pro/8920cb78574895a363776c47f360e235d27df99c .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1122582422" 
	@${RM} ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o.d" -o ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o ../src/config/sam_c21_xplained_pro/peripheral/sercom/usart/plib_sercom4_usart.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/2008830121/xc32_monitor.o: ../src/config/sam_c21_xplained_pro/stdio/xc32_monitor.c  .generated_files/flags/sam_c21_xplained_pro/d7563fb7cc909f5747b53a9f39cfa3f016733476 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2008830121" 
	@${RM} ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2008830121/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o ../src/config/sam_c21_xplained_pro/stdio/xc32_monitor.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/653373664/sys_command.o: ../src/config/sam_c21_xplained_pro/system/command/src/sys_command.c  .generated_files/flags/sam_c21_xplained_pro/7617d7d7eb1b3fe0a995857c2c9f51d02af4e066 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/653373664" 
	@${RM} ${OBJECTDIR}/_ext/653373664/sys_command.o.d 
	@${RM} ${OBJECTDIR}/_ext/653373664/sys_command.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/653373664/sys_command.o.d" -o ${OBJECTDIR}/_ext/653373664/sys_command.o ../src/config/sam_c21_xplained_pro/system/command/src/sys_command.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1110085844/sys_console.o: ../src/config/sam_c21_xplained_pro/system/console/src/sys_console.c  .generated_files/flags/sam_c21_xplained_pro/6cbacb38e698822195b0e5e9d8dae06b8be583 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1110085844" 
	@${RM} ${OBJECTDIR}/_ext/1110085844/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/1110085844/sys_console.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1110085844/sys_console.o.d" -o ${OBJECTDIR}/_ext/1110085844/sys_console.o ../src/config/sam_c21_xplained_pro/system/console/src/sys_console.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1110085844/sys_console_uart.o: ../src/config/sam_c21_xplained_pro/system/console/src/sys_console_uart.c  .generated_files/flags/sam_c21_xplained_pro/6ece6961a1ee22997565479b34eb1bd6c265642 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1110085844" 
	@${RM} ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1110085844/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o ../src/config/sam_c21_xplained_pro/system/console/src/sys_console_uart.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1437254184/sys_debug.o: ../src/config/sam_c21_xplained_pro/system/debug/src/sys_debug.c  .generated_files/flags/sam_c21_xplained_pro/eeb7da03e1131e5230588d3bb7470bcd3802d8c6 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437254184" 
	@${RM} ${OBJECTDIR}/_ext/1437254184/sys_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437254184/sys_debug.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1437254184/sys_debug.o.d" -o ${OBJECTDIR}/_ext/1437254184/sys_debug.o ../src/config/sam_c21_xplained_pro/system/debug/src/sys_debug.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1386091972/sys_int.o: ../src/config/sam_c21_xplained_pro/system/int/src/sys_int.c  .generated_files/flags/sam_c21_xplained_pro/5d69d5362c64c85cd84e113bc9e5fe4301bab143 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1386091972" 
	@${RM} ${OBJECTDIR}/_ext/1386091972/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1386091972/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1386091972/sys_int.o.d" -o ${OBJECTDIR}/_ext/1386091972/sys_int.o ../src/config/sam_c21_xplained_pro/system/int/src/sys_int.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/200569009/sys_reset.o: ../src/config/sam_c21_xplained_pro/system/reset/sys_reset.c  .generated_files/flags/sam_c21_xplained_pro/a82dee0264dd2735ce0c7caea94defe0abb0d24a .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/200569009" 
	@${RM} ${OBJECTDIR}/_ext/200569009/sys_reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/200569009/sys_reset.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/200569009/sys_reset.o.d" -o ${OBJECTDIR}/_ext/200569009/sys_reset.o ../src/config/sam_c21_xplained_pro/system/reset/sys_reset.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1715113378/sys_time.o: ../src/config/sam_c21_xplained_pro/system/time/src/sys_time.c  .generated_files/flags/sam_c21_xplained_pro/3385d2c01fb4681a7440c8974cd5d4161b3efac2 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1715113378" 
	@${RM} ${OBJECTDIR}/_ext/1715113378/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/1715113378/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1715113378/sys_time.o.d" -o ${OBJECTDIR}/_ext/1715113378/sys_time.o ../src/config/sam_c21_xplained_pro/system/time/src/sys_time.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/exceptions.o: ../src/config/sam_c21_xplained_pro/exceptions.c  .generated_files/flags/sam_c21_xplained_pro/d56964dec66c19b3ea970c273696542576433cb3 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/exceptions.o.d" -o ${OBJECTDIR}/_ext/1383211985/exceptions.o ../src/config/sam_c21_xplained_pro/exceptions.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/initialization.o: ../src/config/sam_c21_xplained_pro/initialization.c  .generated_files/flags/sam_c21_xplained_pro/9b3a81b5d5fba0e6e60d03629227f90d2860e21c .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/initialization.o.d" -o ${OBJECTDIR}/_ext/1383211985/initialization.o ../src/config/sam_c21_xplained_pro/initialization.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/interrupts.o: ../src/config/sam_c21_xplained_pro/interrupts.c  .generated_files/flags/sam_c21_xplained_pro/225ce63e6bd864805e95835a4b1e00c5875e0498 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/interrupts.o.d" -o ${OBJECTDIR}/_ext/1383211985/interrupts.o ../src/config/sam_c21_xplained_pro/interrupts.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/libc_syscalls.o: ../src/config/sam_c21_xplained_pro/libc_syscalls.c  .generated_files/flags/sam_c21_xplained_pro/d04857d717edae78be653de70dc6969af57189d6 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o ../src/config/sam_c21_xplained_pro/libc_syscalls.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/startup_xc32.o: ../src/config/sam_c21_xplained_pro/startup_xc32.c  .generated_files/flags/sam_c21_xplained_pro/c5e1589e12b173a64aa1759a6fa0152c753c5a43 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1383211985/startup_xc32.o ../src/config/sam_c21_xplained_pro/startup_xc32.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/freertos_hooks.o: ../src/config/sam_c21_xplained_pro/freertos_hooks.c  .generated_files/flags/sam_c21_xplained_pro/41ae635a4b81a78e39b4ab3c20e1d826f662ab70 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/freertos_hooks.o.d" -o ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o ../src/config/sam_c21_xplained_pro/freertos_hooks.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/tasks.o: ../src/config/sam_c21_xplained_pro/tasks.c  .generated_files/flags/sam_c21_xplained_pro/f2282f23399a27ef19e0ae42cb0f8237c5beb2c6 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/tasks.o.d" -o ${OBJECTDIR}/_ext/1383211985/tasks.o ../src/config/sam_c21_xplained_pro/tasks.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1624415188/port.o: ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c  .generated_files/flags/sam_c21_xplained_pro/dcc90e4d4ec6ca5fb852ddf0ac6c1c19e50a76ff .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1624415188" 
	@${RM} ${OBJECTDIR}/_ext/1624415188/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1624415188/port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1624415188/port.o.d" -o ${OBJECTDIR}/_ext/1624415188/port.o ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1624415188/portasm.o: ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.c  .generated_files/flags/sam_c21_xplained_pro/734b63b45a2d6148c73ea4aaf5730403f0b8ef87 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1624415188" 
	@${RM} ${OBJECTDIR}/_ext/1624415188/portasm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1624415188/portasm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1624415188/portasm.o.d" -o ${OBJECTDIR}/_ext/1624415188/portasm.o ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1665200909/heap_1.o: ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c  .generated_files/flags/sam_c21_xplained_pro/ada82c1bd7399bbfb56fa5fa8571e112d7327b7f .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1665200909" 
	@${RM} ${OBJECTDIR}/_ext/1665200909/heap_1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1665200909/heap_1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1665200909/heap_1.o.d" -o ${OBJECTDIR}/_ext/1665200909/heap_1.o ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/croutine.o: ../src/third_party/rtos/FreeRTOS/Source/croutine.c  .generated_files/flags/sam_c21_xplained_pro/dcfc0934bc65548ed4ade691ee0e0eb1f83c03d9 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/croutine.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/croutine.o.d" -o ${OBJECTDIR}/_ext/404212886/croutine.o ../src/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/list.o: ../src/third_party/rtos/FreeRTOS/Source/list.c  .generated_files/flags/sam_c21_xplained_pro/4ff9852aca832bdd78a1cb05216f938242c8af1c .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/list.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/list.o.d" -o ${OBJECTDIR}/_ext/404212886/list.o ../src/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/queue.o: ../src/third_party/rtos/FreeRTOS/Source/queue.c  .generated_files/flags/sam_c21_xplained_pro/1ddc1b1ffe95dafc4e3ab9da8f658e20bbaf3a40 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/queue.o.d" -o ${OBJECTDIR}/_ext/404212886/queue.o ../src/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o: ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c  .generated_files/flags/sam_c21_xplained_pro/8ba5d6e3f5ae34b09ceed2c6ad1f5f4ec7e96014 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d" -o ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/timers.o: ../src/third_party/rtos/FreeRTOS/Source/timers.c  .generated_files/flags/sam_c21_xplained_pro/35cb3a581d9a73c56cf77ed95ff3ba672bf8c5bc .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/timers.o.d" -o ${OBJECTDIR}/_ext/404212886/timers.o ../src/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/event_groups.o: ../src/third_party/rtos/FreeRTOS/Source/event_groups.c  .generated_files/flags/sam_c21_xplained_pro/d4a271372287cb86ce3edd658abd98ab4c8910da .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/event_groups.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/event_groups.o.d" -o ${OBJECTDIR}/_ext/404212886/event_groups.o ../src/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/stream_buffer.o: ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c  .generated_files/flags/sam_c21_xplained_pro/1219f7b4d4a0cc01b2209e7dbec4258bcfdd9b9e .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/stream_buffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/404212886/stream_buffer.o ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/sam_c21_xplained_pro/9e29e08d874d74187a0a19f412d411155c75ea38 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/sam_c21_xplained_pro/d19fd7fcf291aea3b7bf8f0911ada1ad36d42da4 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/1793397138/command.o: ../src/application/command/command.c  .generated_files/flags/sam_c21_xplained_pro/be278f9f80c700957e1aec2ad86030d84a6f19e4 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1793397138" 
	@${RM} ${OBJECTDIR}/_ext/1793397138/command.o.d 
	@${RM} ${OBJECTDIR}/_ext/1793397138/command.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1793397138/command.o.d" -o ${OBJECTDIR}/_ext/1793397138/command.o ../src/application/command/command.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1794512798/console.o: ../src/application/console/console.c  .generated_files/flags/sam_c21_xplained_pro/3dcfe8e0748d0877d7147ca3fbe2c6842c189aaf .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1794512798" 
	@${RM} ${OBJECTDIR}/_ext/1794512798/console.o.d 
	@${RM} ${OBJECTDIR}/_ext/1794512798/console.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1794512798/console.o.d" -o ${OBJECTDIR}/_ext/1794512798/console.o ../src/application/console/console.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1274956685/rf.o: ../src/application/rf/rf.c  .generated_files/flags/sam_c21_xplained_pro/38b82d8a65f5c96d930e82006e5a5a133705b4fb .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1274956685" 
	@${RM} ${OBJECTDIR}/_ext/1274956685/rf.o.d 
	@${RM} ${OBJECTDIR}/_ext/1274956685/rf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1274956685/rf.o.d" -o ${OBJECTDIR}/_ext/1274956685/rf.o ../src/application/rf/rf.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states.o: ../src/application/states/states.c  .generated_files/flags/sam_c21_xplained_pro/f3866380cc161bfdef9297d2a25d9d820ed02d6b .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states.o.d" -o ${OBJECTDIR}/_ext/1212921563/states.o ../src/application/states/states.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_error.o: ../src/application/states/states_error.c  .generated_files/flags/sam_c21_xplained_pro/5c87fba6224c599bb148b81c05f91a858e86a46 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_error.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_error.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_error.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_error.o ../src/application/states/states_error.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_alarm.o: ../src/application/states/states_alarm.c  .generated_files/flags/sam_c21_xplained_pro/e17507c902bb3d06d43f1960c8492156dca52dc1 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_alarm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_alarm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_alarm.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_alarm.o ../src/application/states/states_alarm.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_learn.o: ../src/application/states/states_learn.c  .generated_files/flags/sam_c21_xplained_pro/c18b531110d650a499af3565a1fa1693196df934 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_learn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_learn.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_learn.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_learn.o ../src/application/states/states_learn.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_keep_alive.o: ../src/application/states/states_keep_alive.c  .generated_files/flags/sam_c21_xplained_pro/c8060ed37ad5f95c02386cf87038ac933f6b1e1f .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_keep_alive.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_keep_alive.o ../src/application/states/states_keep_alive.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_idle.o: ../src/application/states/states_idle.c  .generated_files/flags/sam_c21_xplained_pro/5d3aaa9f0bc3ec50e245b7b621a3901624407ea5 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_idle.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_idle.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_idle.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_idle.o ../src/application/states/states_idle.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_init.o: ../src/application/states/states_init.c  .generated_files/flags/sam_c21_xplained_pro/eb8bce819a0ebb668e831d08e5b8f36f8d615cb7 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_init.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_init.o ../src/application/states/states_init.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_connection_verification.o: ../src/application/states/states_connection_verification.c  .generated_files/flags/sam_c21_xplained_pro/587479b9726fa5e8091d7c12f373115c205affc1 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_connection_verification.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_connection_verification.o ../src/application/states/states_connection_verification.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1212921563/states_update.o: ../src/application/states/states_update.c  .generated_files/flags/sam_c21_xplained_pro/cd59bac668b581f2d45dab784926cbc013bef03d .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1212921563" 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_update.o.d 
	@${RM} ${OBJECTDIR}/_ext/1212921563/states_update.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1212921563/states_update.o.d" -o ${OBJECTDIR}/_ext/1212921563/states_update.o ../src/application/states/states_update.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1167757227/test.o: ../src/application/test/test.c  .generated_files/flags/sam_c21_xplained_pro/9e58e7463e83e81ddeb5db6c12e73acc99667fd0 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1167757227" 
	@${RM} ${OBJECTDIR}/_ext/1167757227/test.o.d 
	@${RM} ${OBJECTDIR}/_ext/1167757227/test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1167757227/test.o.d" -o ${OBJECTDIR}/_ext/1167757227/test.o ../src/application/test/test.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/801483606/application.o: ../src/application/application.c  .generated_files/flags/sam_c21_xplained_pro/91c0ccd08a38cf631080c79d866f212848aefd84 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/application.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/application.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/application.o.d" -o ${OBJECTDIR}/_ext/801483606/application.o ../src/application/application.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1038944351/bsp.o: ../src/config/sam_c21_xplained_pro/bsp/bsp.c  .generated_files/flags/sam_c21_xplained_pro/650a7ae31f48c1928100f4bb057e7fbd4310ca7 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1038944351" 
	@${RM} ${OBJECTDIR}/_ext/1038944351/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1038944351/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1038944351/bsp.o.d" -o ${OBJECTDIR}/_ext/1038944351/bsp.o ../src/config/sam_c21_xplained_pro/bsp/bsp.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/148671750/emulated_eeprom.o: ../src/config/sam_c21_xplained_pro/library/emulated_eeprom/emulated_eeprom.c  .generated_files/flags/sam_c21_xplained_pro/e6355262bd33a9f39660c9b669889124d1876bc1 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/148671750" 
	@${RM} ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/148671750/emulated_eeprom.o.d" -o ${OBJECTDIR}/_ext/148671750/emulated_eeprom.o ../src/config/sam_c21_xplained_pro/library/emulated_eeprom/emulated_eeprom.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/2142890735/osal_freertos.o: ../src/config/sam_c21_xplained_pro/osal/osal_freertos.c  .generated_files/flags/sam_c21_xplained_pro/637203bdad8a4c12f4b3cd5db41ddaaedf83c8f9 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2142890735" 
	@${RM} ${OBJECTDIR}/_ext/2142890735/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/2142890735/osal_freertos.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2142890735/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/2142890735/osal_freertos.o ../src/config/sam_c21_xplained_pro/osal/osal_freertos.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1818098789/plib_clock.o: ../src/config/sam_c21_xplained_pro/peripheral/clock/plib_clock.c  .generated_files/flags/sam_c21_xplained_pro/faafa3c7e5cb69378cd3a4a4a1033539321bba54 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1818098789" 
	@${RM} ${OBJECTDIR}/_ext/1818098789/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1818098789/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1818098789/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1818098789/plib_clock.o ../src/config/sam_c21_xplained_pro/peripheral/clock/plib_clock.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/435409140/plib_eic.o: ../src/config/sam_c21_xplained_pro/peripheral/eic/plib_eic.c  .generated_files/flags/sam_c21_xplained_pro/b9eaa8f89ee56934eb61e10814703ed4e393c3fa .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/435409140" 
	@${RM} ${OBJECTDIR}/_ext/435409140/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/435409140/plib_eic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/435409140/plib_eic.o.d" -o ${OBJECTDIR}/_ext/435409140/plib_eic.o ../src/config/sam_c21_xplained_pro/peripheral/eic/plib_eic.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1815949303/plib_evsys.o: ../src/config/sam_c21_xplained_pro/peripheral/evsys/plib_evsys.c  .generated_files/flags/sam_c21_xplained_pro/b0a3b77f8c5c041be224d30cf8bd5fbb268733b2 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1815949303" 
	@${RM} ${OBJECTDIR}/_ext/1815949303/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1815949303/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1815949303/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1815949303/plib_evsys.o ../src/config/sam_c21_xplained_pro/peripheral/evsys/plib_evsys.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/612500555/plib_nvic.o: ../src/config/sam_c21_xplained_pro/peripheral/nvic/plib_nvic.c  .generated_files/flags/sam_c21_xplained_pro/d1b617abf5e7086fbe8f731da4e7253849371d41 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/612500555" 
	@${RM} ${OBJECTDIR}/_ext/612500555/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/612500555/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/612500555/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/612500555/plib_nvic.o ../src/config/sam_c21_xplained_pro/peripheral/nvic/plib_nvic.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o: ../src/config/sam_c21_xplained_pro/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/sam_c21_xplained_pro/2d4ed3abb4ca7d38ec98d26379980e700ff41f78 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1979151395" 
	@${RM} ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1979151395/plib_nvmctrl.o ../src/config/sam_c21_xplained_pro/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/612447404/plib_port.o: ../src/config/sam_c21_xplained_pro/peripheral/port/plib_port.c  .generated_files/flags/sam_c21_xplained_pro/8dabaca40c16f5b9f1864d82ac5f86d738f791b6 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/612447404" 
	@${RM} ${OBJECTDIR}/_ext/612447404/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/612447404/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/612447404/plib_port.o.d" -o ${OBJECTDIR}/_ext/612447404/plib_port.o ../src/config/sam_c21_xplained_pro/peripheral/port/plib_port.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o: ../src/config/sam_c21_xplained_pro/peripheral/rtc/plib_rtc_timer.c  .generated_files/flags/sam_c21_xplained_pro/83e93ab915333d2ff25222ceae993933db906b2d .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/435396306" 
	@${RM} ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o.d" -o ${OBJECTDIR}/_ext/435396306/plib_rtc_timer.o ../src/config/sam_c21_xplained_pro/peripheral/rtc/plib_rtc_timer.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o: ../src/config/sam_c21_xplained_pro/peripheral/sercom/spi_master/plib_sercom1_spi_master.c  .generated_files/flags/sam_c21_xplained_pro/fe301f671c451c9817484d640b645face201312 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/30358000" 
	@${RM} ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o.d" -o ${OBJECTDIR}/_ext/30358000/plib_sercom1_spi_master.o ../src/config/sam_c21_xplained_pro/peripheral/sercom/spi_master/plib_sercom1_spi_master.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o: ../src/config/sam_c21_xplained_pro/peripheral/sercom/usart/plib_sercom4_usart.c  .generated_files/flags/sam_c21_xplained_pro/9c28e8e28124d40d57311d512cd849aeff30c431 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1122582422" 
	@${RM} ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o.d" -o ${OBJECTDIR}/_ext/1122582422/plib_sercom4_usart.o ../src/config/sam_c21_xplained_pro/peripheral/sercom/usart/plib_sercom4_usart.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/2008830121/xc32_monitor.o: ../src/config/sam_c21_xplained_pro/stdio/xc32_monitor.c  .generated_files/flags/sam_c21_xplained_pro/2a82c9c2a18797008f21c18de9106d2e19448f44 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2008830121" 
	@${RM} ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2008830121/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/2008830121/xc32_monitor.o ../src/config/sam_c21_xplained_pro/stdio/xc32_monitor.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/653373664/sys_command.o: ../src/config/sam_c21_xplained_pro/system/command/src/sys_command.c  .generated_files/flags/sam_c21_xplained_pro/9a430d02719ece0862cfd16fd3c996aae127a84e .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/653373664" 
	@${RM} ${OBJECTDIR}/_ext/653373664/sys_command.o.d 
	@${RM} ${OBJECTDIR}/_ext/653373664/sys_command.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/653373664/sys_command.o.d" -o ${OBJECTDIR}/_ext/653373664/sys_command.o ../src/config/sam_c21_xplained_pro/system/command/src/sys_command.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1110085844/sys_console.o: ../src/config/sam_c21_xplained_pro/system/console/src/sys_console.c  .generated_files/flags/sam_c21_xplained_pro/f7f94a91ffa293480b5b0afe074fa8b68c0689ad .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1110085844" 
	@${RM} ${OBJECTDIR}/_ext/1110085844/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/1110085844/sys_console.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1110085844/sys_console.o.d" -o ${OBJECTDIR}/_ext/1110085844/sys_console.o ../src/config/sam_c21_xplained_pro/system/console/src/sys_console.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1110085844/sys_console_uart.o: ../src/config/sam_c21_xplained_pro/system/console/src/sys_console_uart.c  .generated_files/flags/sam_c21_xplained_pro/333432c39138e81bd1e1d4f47f49e4b920d6f2c .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1110085844" 
	@${RM} ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1110085844/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/1110085844/sys_console_uart.o ../src/config/sam_c21_xplained_pro/system/console/src/sys_console_uart.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1437254184/sys_debug.o: ../src/config/sam_c21_xplained_pro/system/debug/src/sys_debug.c  .generated_files/flags/sam_c21_xplained_pro/d6b498c2ccea61c503c8e1bcaa8f8d06d3e5ac88 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437254184" 
	@${RM} ${OBJECTDIR}/_ext/1437254184/sys_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437254184/sys_debug.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1437254184/sys_debug.o.d" -o ${OBJECTDIR}/_ext/1437254184/sys_debug.o ../src/config/sam_c21_xplained_pro/system/debug/src/sys_debug.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1386091972/sys_int.o: ../src/config/sam_c21_xplained_pro/system/int/src/sys_int.c  .generated_files/flags/sam_c21_xplained_pro/99946e83cffd0129364b3bdf508628668a00026b .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1386091972" 
	@${RM} ${OBJECTDIR}/_ext/1386091972/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1386091972/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1386091972/sys_int.o.d" -o ${OBJECTDIR}/_ext/1386091972/sys_int.o ../src/config/sam_c21_xplained_pro/system/int/src/sys_int.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/200569009/sys_reset.o: ../src/config/sam_c21_xplained_pro/system/reset/sys_reset.c  .generated_files/flags/sam_c21_xplained_pro/92ff45ea72535e07bdc0026fdb6014d404ae7846 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/200569009" 
	@${RM} ${OBJECTDIR}/_ext/200569009/sys_reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/200569009/sys_reset.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/200569009/sys_reset.o.d" -o ${OBJECTDIR}/_ext/200569009/sys_reset.o ../src/config/sam_c21_xplained_pro/system/reset/sys_reset.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1715113378/sys_time.o: ../src/config/sam_c21_xplained_pro/system/time/src/sys_time.c  .generated_files/flags/sam_c21_xplained_pro/8245480def6ce160302291cb0df38f0b17fb7d97 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1715113378" 
	@${RM} ${OBJECTDIR}/_ext/1715113378/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/1715113378/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1715113378/sys_time.o.d" -o ${OBJECTDIR}/_ext/1715113378/sys_time.o ../src/config/sam_c21_xplained_pro/system/time/src/sys_time.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/exceptions.o: ../src/config/sam_c21_xplained_pro/exceptions.c  .generated_files/flags/sam_c21_xplained_pro/33d38675e1d28096185f090884fb6b320c4ad639 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/exceptions.o.d" -o ${OBJECTDIR}/_ext/1383211985/exceptions.o ../src/config/sam_c21_xplained_pro/exceptions.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/initialization.o: ../src/config/sam_c21_xplained_pro/initialization.c  .generated_files/flags/sam_c21_xplained_pro/372ab9b2888407bace32271ebf0e18c318f15ea8 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/initialization.o.d" -o ${OBJECTDIR}/_ext/1383211985/initialization.o ../src/config/sam_c21_xplained_pro/initialization.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/interrupts.o: ../src/config/sam_c21_xplained_pro/interrupts.c  .generated_files/flags/sam_c21_xplained_pro/4de4c48932f88e7d68367aaec9679422ee3d7ca9 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/interrupts.o.d" -o ${OBJECTDIR}/_ext/1383211985/interrupts.o ../src/config/sam_c21_xplained_pro/interrupts.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/libc_syscalls.o: ../src/config/sam_c21_xplained_pro/libc_syscalls.c  .generated_files/flags/sam_c21_xplained_pro/206216a982f26f1c04736e942902421c2bdb5eb6 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1383211985/libc_syscalls.o ../src/config/sam_c21_xplained_pro/libc_syscalls.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/startup_xc32.o: ../src/config/sam_c21_xplained_pro/startup_xc32.c  .generated_files/flags/sam_c21_xplained_pro/2565a6dcbcde46d7e5f4e43d701a307f9b589c8f .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1383211985/startup_xc32.o ../src/config/sam_c21_xplained_pro/startup_xc32.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/freertos_hooks.o: ../src/config/sam_c21_xplained_pro/freertos_hooks.c  .generated_files/flags/sam_c21_xplained_pro/938e6974451b7ae56756f091cf94c4c411618538 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/freertos_hooks.o.d" -o ${OBJECTDIR}/_ext/1383211985/freertos_hooks.o ../src/config/sam_c21_xplained_pro/freertos_hooks.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1383211985/tasks.o: ../src/config/sam_c21_xplained_pro/tasks.c  .generated_files/flags/sam_c21_xplained_pro/1002c740dfaff795a411c8b96daf752e86e6786e .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1383211985" 
	@${RM} ${OBJECTDIR}/_ext/1383211985/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1383211985/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1383211985/tasks.o.d" -o ${OBJECTDIR}/_ext/1383211985/tasks.o ../src/config/sam_c21_xplained_pro/tasks.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1624415188/port.o: ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c  .generated_files/flags/sam_c21_xplained_pro/80e02f50d7ad8513406544020314d5866908884b .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1624415188" 
	@${RM} ${OBJECTDIR}/_ext/1624415188/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1624415188/port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1624415188/port.o.d" -o ${OBJECTDIR}/_ext/1624415188/port.o ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1624415188/portasm.o: ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.c  .generated_files/flags/sam_c21_xplained_pro/78e865817a723719dd8f36e053fc98baafed3eec .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1624415188" 
	@${RM} ${OBJECTDIR}/_ext/1624415188/portasm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1624415188/portasm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1624415188/portasm.o.d" -o ${OBJECTDIR}/_ext/1624415188/portasm.o ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0/portasm.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1665200909/heap_1.o: ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c  .generated_files/flags/sam_c21_xplained_pro/791f9a5767a850e72f37ac0200c84f0ef512d346 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1665200909" 
	@${RM} ${OBJECTDIR}/_ext/1665200909/heap_1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1665200909/heap_1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1665200909/heap_1.o.d" -o ${OBJECTDIR}/_ext/1665200909/heap_1.o ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/croutine.o: ../src/third_party/rtos/FreeRTOS/Source/croutine.c  .generated_files/flags/sam_c21_xplained_pro/cfdbc15791f7de6189071730636136b1dbac76b4 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/croutine.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/croutine.o.d" -o ${OBJECTDIR}/_ext/404212886/croutine.o ../src/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/list.o: ../src/third_party/rtos/FreeRTOS/Source/list.c  .generated_files/flags/sam_c21_xplained_pro/b583db21fbaa7eeb971961197a7a131847292177 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/list.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/list.o.d" -o ${OBJECTDIR}/_ext/404212886/list.o ../src/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/queue.o: ../src/third_party/rtos/FreeRTOS/Source/queue.c  .generated_files/flags/sam_c21_xplained_pro/f9fca171b1a9cfa34d59d50a8cef64080b4d67e0 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/queue.o.d" -o ${OBJECTDIR}/_ext/404212886/queue.o ../src/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o: ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c  .generated_files/flags/sam_c21_xplained_pro/42681c690e55a457cc0783d5b85f1aa26a161f6a .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d" -o ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/timers.o: ../src/third_party/rtos/FreeRTOS/Source/timers.c  .generated_files/flags/sam_c21_xplained_pro/bb14fa12acdba3091c7c0b36eaeb5168d737cdbb .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/timers.o.d" -o ${OBJECTDIR}/_ext/404212886/timers.o ../src/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/event_groups.o: ../src/third_party/rtos/FreeRTOS/Source/event_groups.c  .generated_files/flags/sam_c21_xplained_pro/f665596003c5716f87dae564f1c721ab06f20437 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/event_groups.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/event_groups.o.d" -o ${OBJECTDIR}/_ext/404212886/event_groups.o ../src/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/404212886/stream_buffer.o: ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c  .generated_files/flags/sam_c21_xplained_pro/b04577b1a57a9559ca5dcf574e2498a1e6baa670 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/stream_buffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/404212886/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/404212886/stream_buffer.o ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/sam_c21_xplained_pro/3c7485174a34949334fb64b49d75a6b3116b32ba .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/sam_c21_xplained_pro/6677085a71c2445bb47890286057a74307fb6d92 .generated_files/flags/sam_c21_xplained_pro/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -DPROJ_SAM_C21_XPLAINED_PRO -I"../src" -I"../src/config/sam_c21_xplained_pro" -I"../src/packs/ATSAMC21J18A_DFP" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/ARM_CM0" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/samc21" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/sam_c21_xplained_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/sam_c21_xplained_pro/ATSAMC21J18A.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -mno-device-startup-code -o ${DISTDIR}/sam_c21_xplained_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DROM_LENGTH=0x3fe00,--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/samc21"
	
else
${DISTDIR}/sam_c21_xplained_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/sam_c21_xplained_pro/ATSAMC21J18A.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -mno-device-startup-code -o ${DISTDIR}/sam_c21_xplained_pro.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_sam_c21_xplained_pro=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",-DROM_LENGTH=0x3fe00,--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/samc21"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/sam_c21_xplained_pro.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
