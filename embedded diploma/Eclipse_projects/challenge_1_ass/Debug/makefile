################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
challenge_1_ass.lss \

FLASH_IMAGE += \
challenge_1_ass.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: challenge_1_ass.elf secondary-outputs

# Tool invocations
challenge_1_ass.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,challenge_1_ass.map -mmcu=atmega32 -o "challenge_1_ass.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

challenge_1_ass.lss: challenge_1_ass.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S challenge_1_ass.elf  >"challenge_1_ass.lss"
	@echo 'Finished building: $@'
	@echo ' '

challenge_1_ass.hex: challenge_1_ass.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex challenge_1_ass.elf  "challenge_1_ass.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: challenge_1_ass.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 challenge_1_ass.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) challenge_1_ass.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
