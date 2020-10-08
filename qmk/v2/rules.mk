MCU = atmega32u4
F_CPU = 8000000
ARCH = AVR8
F_USB = $(F_CPU)
BOOTLOADER = caterina
SPLIT_KEYBOARD = yes

# DEFAULT_FOLDER = fissure/master
# NRF_DEBUG = no
# MCU_FAMILY = NRF52
# MCU  = cortex-m4
# ARMV = 7
# MCU_LDSCRIPT = nrf52840
# MCU_SERIES = NRF52840
# NRFSDK_ROOT := $(NRFSDK15_ROOT) #Path to nRF SDK v15.0.0
# CUSTOM_MATRIX = yes

MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = yes
