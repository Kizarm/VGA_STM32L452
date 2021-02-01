RM := rm -rf
C_SRCS := cim.c
OBJS := cim.o

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

%.o: %.c
	@echo 'Building file: $<'
	gcc -Os -Wall -c -fmessage-length=0 -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

all: cim

cim: $(OBJS)
	@echo 'Linking target: $@'
	gcc -s -o"cim" $(OBJS)
	@echo 'Finished linking target: $@'
	@echo ' '

clean:
	-$(RM) $(OBJS)$(EXECUTABLES) cim
	-@echo ' '

.PHONY: all clean
.SECONDARY:

