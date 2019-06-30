# Lightning tracker STM32 (WIP)
SPLAT board version 

### Project to implement timestamped ADC samples and stream interesting 'detections' to downstream server to work out triangulation etc.

Target BSP STM32F767ZI  STM Nucleo-144 
Samples ADC at approx 2.68Msps and streams ADC readings and GPS to LAN using IPv4 UDP for downstream analysis

Unlike my9 project this has a daughter board:-
Uses experimental daughterboard "Splat1" to filter/amplify/attenuate input signal and assist with experimental breadboard design

#### Hardware configuration, GPS pinout etc

- GPS: Neo7M, uses async serial port

- GPS Tx -> STM32 USART6 Rx, D0/PG9 on STM32 board
- GPS Rx -> STM32 USART6 Tx, D16/PC6 on STM32 Board
- GPS 1PPS -> STM32 Timer2 CH3 Capture input, D36/PB10 on STM32, also to D13/PA5 on STM (2 connections)

- ADC Input (Antenna / LowPass etc) -> ADC PA3/A0 on STM32 - Should really bias half way to 3.3V and use a simple front-end

- DAC Output (used for test signal generation)  STM32 PA4/D24 Out -> Posible ADC input as above, should be disabled if unused to reduce ADC noise.

### Debug 
- Serial port debug output @ 115Kbaud, no flow control through the USB virtual serial port 
-- CN5 Tx -> D52/PD6
-- CN5 Rx -> D53/PD5


### The server side processing is another github project (WIP)

 
