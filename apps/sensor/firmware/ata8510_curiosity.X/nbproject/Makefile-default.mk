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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../src/interrupt_vectors.c ../src/wrap.c ../src/wrap_thunk.c ../src/ata8510_curiosity.c ../src/startup.s ../src/keep_alive.c ../src/child_learn.c ../src/parent_learn.c ../src/common.c ../src/update.c ../src/rtc.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o ${OBJECTDIR}/_ext/1360937237/wrap.o ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o ${OBJECTDIR}/_ext/1360937237/startup.o ${OBJECTDIR}/_ext/1360937237/keep_alive.o ${OBJECTDIR}/_ext/1360937237/child_learn.o ${OBJECTDIR}/_ext/1360937237/parent_learn.o ${OBJECTDIR}/_ext/1360937237/common.o ${OBJECTDIR}/_ext/1360937237/update.o ${OBJECTDIR}/_ext/1360937237/rtc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o.d ${OBJECTDIR}/_ext/1360937237/wrap.o.d ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o.d ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o.d ${OBJECTDIR}/_ext/1360937237/startup.o.d ${OBJECTDIR}/_ext/1360937237/keep_alive.o.d ${OBJECTDIR}/_ext/1360937237/child_learn.o.d ${OBJECTDIR}/_ext/1360937237/parent_learn.o.d ${OBJECTDIR}/_ext/1360937237/common.o.d ${OBJECTDIR}/_ext/1360937237/update.o.d ${OBJECTDIR}/_ext/1360937237/rtc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o ${OBJECTDIR}/_ext/1360937237/wrap.o ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o ${OBJECTDIR}/_ext/1360937237/startup.o ${OBJECTDIR}/_ext/1360937237/keep_alive.o ${OBJECTDIR}/_ext/1360937237/child_learn.o ${OBJECTDIR}/_ext/1360937237/parent_learn.o ${OBJECTDIR}/_ext/1360937237/common.o ${OBJECTDIR}/_ext/1360937237/update.o ${OBJECTDIR}/_ext/1360937237/rtc.o

# Source Files
SOURCEFILES=../src/interrupt_vectors.c ../src/wrap.c ../src/wrap_thunk.c ../src/ata8510_curiosity.c ../src/startup.s ../src/keep_alive.c ../src/child_learn.c ../src/parent_learn.c ../src/common.c ../src/update.c ../src/rtc.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATA5831
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o: ../src/interrupt_vectors.c  .generated_files/flags/default/24cea891ee1d667cf8d490d615fb62929d7833c5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o.d" -MT "${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o.d" -MT ${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o -o ${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o ../src/interrupt_vectors.c 
	
${OBJECTDIR}/_ext/1360937237/wrap.o: ../src/wrap.c  .generated_files/flags/default/2a835d61fa9fcad149e6a89aca729b9b7bca1619 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wrap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wrap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/wrap.o.d" -MT "${OBJECTDIR}/_ext/1360937237/wrap.o.d" -MT ${OBJECTDIR}/_ext/1360937237/wrap.o -o ${OBJECTDIR}/_ext/1360937237/wrap.o ../src/wrap.c 
	
${OBJECTDIR}/_ext/1360937237/wrap_thunk.o: ../src/wrap_thunk.c  .generated_files/flags/default/b141c604c267f08ae3a494b886fd35890e0a3a1c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/wrap_thunk.o.d" -MT "${OBJECTDIR}/_ext/1360937237/wrap_thunk.o.d" -MT ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o -o ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o ../src/wrap_thunk.c 
	
${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o: ../src/ata8510_curiosity.c  .generated_files/flags/default/974ac2ed25e2e08a2e71859500fc347370261aa8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o.d" -MT "${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o.d" -MT ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o -o ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o ../src/ata8510_curiosity.c 
	
${OBJECTDIR}/_ext/1360937237/keep_alive.o: ../src/keep_alive.c  .generated_files/flags/default/b99c377cf0981e0844e15a363c3b065a2f459464 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/keep_alive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/keep_alive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/keep_alive.o.d" -MT "${OBJECTDIR}/_ext/1360937237/keep_alive.o.d" -MT ${OBJECTDIR}/_ext/1360937237/keep_alive.o -o ${OBJECTDIR}/_ext/1360937237/keep_alive.o ../src/keep_alive.c 
	
${OBJECTDIR}/_ext/1360937237/child_learn.o: ../src/child_learn.c  .generated_files/flags/default/3daef3c0c286658bcf68c0ec34bbf9a9b09975ab .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/child_learn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/child_learn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/child_learn.o.d" -MT "${OBJECTDIR}/_ext/1360937237/child_learn.o.d" -MT ${OBJECTDIR}/_ext/1360937237/child_learn.o -o ${OBJECTDIR}/_ext/1360937237/child_learn.o ../src/child_learn.c 
	
${OBJECTDIR}/_ext/1360937237/parent_learn.o: ../src/parent_learn.c  .generated_files/flags/default/d88635529074089f7aad9dd4dff3cee45d932d54 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/parent_learn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/parent_learn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/parent_learn.o.d" -MT "${OBJECTDIR}/_ext/1360937237/parent_learn.o.d" -MT ${OBJECTDIR}/_ext/1360937237/parent_learn.o -o ${OBJECTDIR}/_ext/1360937237/parent_learn.o ../src/parent_learn.c 
	
${OBJECTDIR}/_ext/1360937237/common.o: ../src/common.c  .generated_files/flags/default/57282529afa4f10f82b4b5fc3440059923857e06 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/common.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/common.o.d" -MT "${OBJECTDIR}/_ext/1360937237/common.o.d" -MT ${OBJECTDIR}/_ext/1360937237/common.o -o ${OBJECTDIR}/_ext/1360937237/common.o ../src/common.c 
	
${OBJECTDIR}/_ext/1360937237/update.o: ../src/update.c  .generated_files/flags/default/82b5c006ece5bea06da5c6557852c30027afe0f5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/update.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/update.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/update.o.d" -MT "${OBJECTDIR}/_ext/1360937237/update.o.d" -MT ${OBJECTDIR}/_ext/1360937237/update.o -o ${OBJECTDIR}/_ext/1360937237/update.o ../src/update.c 
	
${OBJECTDIR}/_ext/1360937237/rtc.o: ../src/rtc.c  .generated_files/flags/default/9cab1ec2245d1bb86183fb33031d2c9fbc0cb6e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/rtc.o.d" -MT "${OBJECTDIR}/_ext/1360937237/rtc.o.d" -MT ${OBJECTDIR}/_ext/1360937237/rtc.o -o ${OBJECTDIR}/_ext/1360937237/rtc.o ../src/rtc.c 
	
else
${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o: ../src/interrupt_vectors.c  .generated_files/flags/default/584372b7bbc669d58d10785b6fce9c7f1c204b57 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o.d" -MT "${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o.d" -MT ${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o -o ${OBJECTDIR}/_ext/1360937237/interrupt_vectors.o ../src/interrupt_vectors.c 
	
${OBJECTDIR}/_ext/1360937237/wrap.o: ../src/wrap.c  .generated_files/flags/default/b3945d6d830bbe9b840d36f8ff53bcaebaf96730 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wrap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wrap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/wrap.o.d" -MT "${OBJECTDIR}/_ext/1360937237/wrap.o.d" -MT ${OBJECTDIR}/_ext/1360937237/wrap.o -o ${OBJECTDIR}/_ext/1360937237/wrap.o ../src/wrap.c 
	
${OBJECTDIR}/_ext/1360937237/wrap_thunk.o: ../src/wrap_thunk.c  .generated_files/flags/default/8c3a556bc4740ad3893b8e87edfb6aa9e7ec9a43 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/wrap_thunk.o.d" -MT "${OBJECTDIR}/_ext/1360937237/wrap_thunk.o.d" -MT ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o -o ${OBJECTDIR}/_ext/1360937237/wrap_thunk.o ../src/wrap_thunk.c 
	
${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o: ../src/ata8510_curiosity.c  .generated_files/flags/default/74078dac11f2cd98bc2715393ffe897b64a9a5c2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o.d" -MT "${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o.d" -MT ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o -o ${OBJECTDIR}/_ext/1360937237/ata8510_curiosity.o ../src/ata8510_curiosity.c 
	
${OBJECTDIR}/_ext/1360937237/keep_alive.o: ../src/keep_alive.c  .generated_files/flags/default/8a7601cce1fca072c256c1128d0bbbc20079e13e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/keep_alive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/keep_alive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/keep_alive.o.d" -MT "${OBJECTDIR}/_ext/1360937237/keep_alive.o.d" -MT ${OBJECTDIR}/_ext/1360937237/keep_alive.o -o ${OBJECTDIR}/_ext/1360937237/keep_alive.o ../src/keep_alive.c 
	
${OBJECTDIR}/_ext/1360937237/child_learn.o: ../src/child_learn.c  .generated_files/flags/default/c59694610f8c312114cf525738bebf2383bd9f76 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/child_learn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/child_learn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/child_learn.o.d" -MT "${OBJECTDIR}/_ext/1360937237/child_learn.o.d" -MT ${OBJECTDIR}/_ext/1360937237/child_learn.o -o ${OBJECTDIR}/_ext/1360937237/child_learn.o ../src/child_learn.c 
	
${OBJECTDIR}/_ext/1360937237/parent_learn.o: ../src/parent_learn.c  .generated_files/flags/default/249a91d62c61bbe739f81a64ce1bad355548944a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/parent_learn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/parent_learn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/parent_learn.o.d" -MT "${OBJECTDIR}/_ext/1360937237/parent_learn.o.d" -MT ${OBJECTDIR}/_ext/1360937237/parent_learn.o -o ${OBJECTDIR}/_ext/1360937237/parent_learn.o ../src/parent_learn.c 
	
${OBJECTDIR}/_ext/1360937237/common.o: ../src/common.c  .generated_files/flags/default/d25e1ea4d22cab11ac9a8545ed273fd5357746ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/common.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/common.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/common.o.d" -MT "${OBJECTDIR}/_ext/1360937237/common.o.d" -MT ${OBJECTDIR}/_ext/1360937237/common.o -o ${OBJECTDIR}/_ext/1360937237/common.o ../src/common.c 
	
${OBJECTDIR}/_ext/1360937237/update.o: ../src/update.c  .generated_files/flags/default/5098c8e6870e26230099757c08af3a07bf5e6cff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/update.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/update.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/update.o.d" -MT "${OBJECTDIR}/_ext/1360937237/update.o.d" -MT ${OBJECTDIR}/_ext/1360937237/update.o -o ${OBJECTDIR}/_ext/1360937237/update.o ../src/update.c 
	
${OBJECTDIR}/_ext/1360937237/rtc.o: ../src/rtc.c  .generated_files/flags/default/31b5255bae737d321a958af3ed69cb296da4fa5c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst       -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/rtc.o.d" -MT "${OBJECTDIR}/_ext/1360937237/rtc.o.d" -MT ${OBJECTDIR}/_ext/1360937237/rtc.o -o ${OBJECTDIR}/_ext/1360937237/rtc.o ../src/rtc.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/startup.o: ../src/startup.s  .generated_files/flags/default/4947bfe80b2ebf61c6007e738d4370403327e216 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/startup.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/startup.o 
	${MP_CC} -c $(MP_EXTRA_AS_PRE) -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x assembler-with-cpp -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) -gdwarf-3 -mno-const-data-in-progmem -Wa,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst     -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/startup.o.d" -MT "${OBJECTDIR}/_ext/1360937237/startup.o.d" -MT ${OBJECTDIR}/_ext/1360937237/startup.o -o ${OBJECTDIR}/_ext/1360937237/startup.o  ../src/startup.s 
	
else
${OBJECTDIR}/_ext/1360937237/startup.o: ../src/startup.s  .generated_files/flags/default/f927c8bd740bcbcc350c7160dd9bb433dd524aa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/startup.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/startup.o 
	${MP_CC} -c $(MP_EXTRA_AS_PRE) -mcpu=$(MP_PROCESSOR_OPTION)  -x assembler-with-cpp -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall -DXPRJ_default=$(CND_CONF)  $(ADD_LINKER_FLAGS) -gdwarf-3 -mno-const-data-in-progmem -Wa,--defsym=__MPLAB_BUILD=1 -D__XC8_CC__ -ffixed-r15 -ffixed-r14 -ffixed-r13 -ffixed-r12 -Wa,-a=$(basename $<).lst     -MD -MP -MF "${OBJECTDIR}/_ext/1360937237/startup.o.d" -MT "${OBJECTDIR}/_ext/1360937237/startup.o.d" -MT ${OBJECTDIR}/_ext/1360937237/startup.o -o ${OBJECTDIR}/_ext/1360937237/startup.o  ../src/startup.s 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ata8510_curiosity.xn
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -O0 -Og -mext=cci -Wall $(ADD_LINKER_FLAGS) -D__XC8_CC__ -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ata8510_curiosity.xn
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -O0 -Og -mext=cci -Wall $(ADD_LINKER_FLAGS) -D__XC8_CC__ -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/ata8510_curiosity.X.${IMAGE_TYPE}.hex"
	
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
