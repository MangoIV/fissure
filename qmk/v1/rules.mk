MCU = atmega32u4
F_CPU = 16000000
ARCH = AVR8
F_USB = $(F_CPU)
BOOTLOADER = caterina

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes
NKRO_ENABLE = yes
USE_I2C = yes
SPLIT_KEYBOARD = yes