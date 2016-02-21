################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/asettl010/Downloads/Arduino\ 2.app/Contents/Java/libraries/SD/src/utility/Sd2Card.cpp \
/Users/asettl010/Downloads/Arduino\ 2.app/Contents/Java/libraries/SD/src/utility/SdFile.cpp \
/Users/asettl010/Downloads/Arduino\ 2.app/Contents/Java/libraries/SD/src/utility/SdVolume.cpp 

CPP_DEPS += \
./Libraries/SD/src/utility/Sd2Card.cpp.d \
./Libraries/SD/src/utility/SdFile.cpp.d \
./Libraries/SD/src/utility/SdVolume.cpp.d 

LINK_OBJ += \
./Libraries/SD/src/utility/Sd2Card.cpp.o \
./Libraries/SD/src/utility/SdFile.cpp.o \
./Libraries/SD/src/utility/SdVolume.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/SD/src/utility/Sd2Card.cpp.o: /Users/asettl010/Downloads/Arduino\ 2.app/Contents/Java/libraries/SD/src/utility/Sd2Card.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/cores/arduino" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/variants/standard" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/libraries/SD" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/libraries/SD/src" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/SPI" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/SoftwareSerial" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/Wire" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/Wire/utility" -I"/Users/asettl010/arduino/Fishino/Libs/Fishino" -I"/Users/asettl010/arduino/Fishino/Libs/Fishino/src" -I"/Users/asettl010/arduino/Rtc_by_Makuna" -I"/Users/asettl010/arduino/Rtc_by_Makuna/src" -I"/Users/asettl010/arduino/Fishino/Libs/Flash" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/SD/src/utility/SdFile.cpp.o: /Users/asettl010/Downloads/Arduino\ 2.app/Contents/Java/libraries/SD/src/utility/SdFile.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/cores/arduino" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/variants/standard" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/libraries/SD" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/libraries/SD/src" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/SPI" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/SoftwareSerial" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/Wire" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/Wire/utility" -I"/Users/asettl010/arduino/Fishino/Libs/Fishino" -I"/Users/asettl010/arduino/Fishino/Libs/Fishino/src" -I"/Users/asettl010/arduino/Rtc_by_Makuna" -I"/Users/asettl010/arduino/Rtc_by_Makuna/src" -I"/Users/asettl010/arduino/Fishino/Libs/Flash" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/SD/src/utility/SdVolume.cpp.o: /Users/asettl010/Downloads/Arduino\ 2.app/Contents/Java/libraries/SD/src/utility/SdVolume.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/cores/arduino" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/variants/standard" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/libraries/SD" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/libraries/SD/src" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/SPI" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/SoftwareSerial" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/Wire" -I"/Users/asettl010/Downloads/Arduino 2.app/Contents/Java/hardware/arduino/avr/libraries/Wire/utility" -I"/Users/asettl010/arduino/Fishino/Libs/Fishino" -I"/Users/asettl010/arduino/Fishino/Libs/Fishino/src" -I"/Users/asettl010/arduino/Rtc_by_Makuna" -I"/Users/asettl010/arduino/Rtc_by_Makuna/src" -I"/Users/asettl010/arduino/Fishino/Libs/Flash" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


