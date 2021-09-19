#==============================================================================
#
#    makefile
#
#==============================================================================
#==============================================================================
#
# Memory Layout
#
LAYOUT	    = release

#
# some usefull variables
#

SDK         = ../SDK
SDK_LIB     = $(SDK)/INCLUDE/LIB
SDK_BT_LIB  = $(SDK)/BTLIB/LIB
SDK_HDR     = $(SDK)/SOURCES
LIBRARY     = $(SDK)/lib
SCRIPT      = $(SDK)/scripts

LIBATOF     = $(LIBRARY)/atoflib.a
LIBC	    = $(LIBRARY)/libc.a
LIBE	    = $(LIBRARY)/libe.a
LIBBTIC	    = $(LIBRARY)/emvlib.a

APP         = .
APP_LIBs     = $(APP)/lib $(APP)/lib/http $(APP)/lib/json
BUILD       = .
INSTALL     = ../BIN

AS          = sde-gcc -xassembler-with-cpp
ASFLAGS     = -march=4kec -mips32r2 -c -D_32_ -D_ASSEMBLER_ -EL -gstabs+


CC          = sde-gcc
CFLAGS      = -march=4kec -mips32r2 -mno-float -EL -gdwarf-2 \
		     -ffixed-14 -ffixed-15 -G0 -fomit-frame-pointer -fsigned-char \
		     -Wimplicit -Wformat -D_32_ -c -mlong-calls

LD		    = sde-ld
#LDFLAG	    = -EL -T $(SCRIPT)/ic3100_app_$(LAYOUT).ld
LDFLAG	    = -EL -T $(SCRIPT)/ic5100_flash_$(LAYOUT).ld

GDB		    = sde-insight
#GDBFLAGS   = -x $(SCRIPT)/ic3100_app_$(LAYOUT).ini
GDBFLAGS    = -x $(SCRIPT)/ic5100_flash_$(LAYOUT).ini


OBJCOPY	    = sde-objcopy
OBJDUMP	    = sde-objdump
OBJCONV	    = sde-conv
OBJVER	    = sde-strings

#
# Executable file name
#
PROGRAM	    = SUDAN_E15_1.0_$(LAYOUT)

#
# Object file list
#
SRC         = $(wildcard ./*.c)
SRC1        = $(wildcard ./*.S)
SDK_SRC     = $(wildcard $(SDK)/SOURCES/*.c)
LIBs_SRC     = $(wildcard $(patsubst %, %/*.c,$(APP_LIBs)))
OBJECTS     = $(SRC:.c=.o) $(SRC1:.S=.o) $(SDK_SRC:.c=.o) $(LIBs_SRC:.c=.o) 

#
# Assembler compilation
#
%.o: %.S
	@mkdir -p $(BUILD)
	$(AS) $(ASFLAGS) $(patsubst %, -I%,$(SDK_LIB) $(SDK_HDR) $(APP) $(APP_LIBs)) $< \
	-o $(patsubst %, $(BUILD)/%, $@)
%.o: %.s
	@mkdir -p $(BUILD)
	$(AS) $(ASFLAGS) $(patsubst %, -I%,$(SDK_LIB) $(SDK_HDR) $(APP) $(APP_LIBs)) $< \
	-o $(patsubst %, $(BUILD)/%, $@)

#
# C compilation
#
%.o: %.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(patsubst %, -I%,$(SDK_LIB) $(SDK_HDR) $(APP) $(APP_LIBs)) $^ \
	-o $(patsubst %, $(BUILD)/%, $@)


all: $(OBJECTS) $(SDK_BT_LIB)/btutils.o $(SDK_HEADERS)
	 $(LD) $(LDFLAG) -L $(BUILD) -L $(SDK_BT_LIB) \
	-o $(INSTALL)/$(PROGRAM).elf  -Map $(INSTALL)/$(PROGRAM).map  \
	--start-group $(FIRMWARE) $(LIBATOF) $(LIBC) $(LIBE) $(LIBBTIC) \
	$(SDK_BT_LIB)/cstartup.o $(SDK_BT_LIB)/btutils.o \
	$(SDK_BT_LIB)/asmutil.o $(SDK_BT_LIB)/prtutil.o $(SDK_BT_LIB)/prtfont.o \
	$(patsubst %, $(BUILD)/%, $(OBJECTS) \
	$(SDK_BT_LIB)/libc.o \
	$(SDK_BT_LIB)/beeplib.o $(SDK_BT_LIB)/timerlib.o $(SDK_BT_LIB)/lcdlib.o $(SDK_BT_LIB)/commlib.o \
	$(SDK_BT_LIB)/keylib.o $(SDK_BT_LIB)/rtclib.o $(SDK_BT_LIB)/msrlib.o $(SDK_BT_LIB)/sysinfo.o $(SDK_BT_LIB)/bitel_tl.o \
	$(SDK_BT_LIB)/hdlcfcs.o $(SDK_BT_LIB)/hdlc.o $(SDK_BT_LIB)/hsmodem.o $(SDK_BT_LIB)/iso8583.o \
	$(SDK_BT_LIB)/des_ecb.o $(SDK_BT_LIB)/frmwri.o $(SDK_BT_LIB)/printf.o )  --end-group


image: all
	$(OBJCONV) -v -l $(INSTALL)/$(PROGRAM).elf
ifeq ($(LAYOUT),release)
	$(OBJCONV) -v -x 1,2,3 -o $(INSTALL)/$(PROGRAM).s19 $(INSTALL)/$(PROGRAM).elf
endif

debug:
	$(GDB) $(GDBFLAGS) $(INSTALL)/$(PROGRAM).elf


clean:
	rm -f $(OBJECTS) $(INSTALL)/$(PROGRAM).elf $(INSTALL)/$(PROGRAM).map

# EOF #
