# List of all the board related files.
BOARDCPPSRC = $(BOARD_DIR)/board_configuration.cpp
DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::B14

# Enable ethernet
LWIP = yes
ALLOW_SHADOW = yes
DDEFS += -DCH_CFG_USE_DYNAMIC=TRUE
DDEFS += -DEFI_ETHERNET=TRUE

# This is an F429!
IS_STM32F429 = yes

BUNDLE_OPENOCD = yes

DDEFS += -DFIRMWARE_ID=\"nucleo_f429\"
DDEFS += -DDEFAULT_ENGINE_TYPE=engine_type_e::MINIMAL_PINS
DDEFS += -DSTATIC_BOARD_ID=STATIC_BOARD_ID_NUCLEO_F429
DDEFS += -DRAM_UNUSED_SIZE=10000
