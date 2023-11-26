<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC8/blob/main/img/setup.png" >

# DIY Flash Reader: SOIC8
Instructions for building a homemade flash chip reader/programmer for SOIC8/SOP8 packages. Chip-on connection via "chip clip" with attached breakout; arduino-based microcontroller uses bit-banging to read from or program chip via Serial Peripheral Interface (SPI).

## Hardware
* Arduino-compatible microcontroller
* SOIC8 Clip + DIP Breakout
* Jumpers/wires
* Breadboard (optional)
  
## Software
* **RDID.ino**: reads out manufacturer ID code
* **RDOTP.ino**: read One Time Programmable (OTP) memory *(example hardcoded for GigaDevice)*
* **FASTREAD.ino**: dump flash conecnts *(example hardcoded for GigaDevice)*
* Other commands/manufacturers can be quickly implemented with slight modification...

## Setup
### Hardware Setup
Pin layout:
<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC8/blob/main/img/soic8_pinout.png" width=200>

Connection Diagram:
<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC8/blob/main/img/soic8_connections.png" width=600>

### Uploading code via Arduino
1. Connect microcontroller via USB, configure in Arduino
2. Paste code for desired command (RDID, etc.)
3. Verify & Upload when ready

### Running commands
Once uploaded, the code can be run using either:
* Arduino's built-in Serial Monitor (good for quick test)
* Other serial comm. utilities: screen, minicom, PuTTY, etc. (*note: project has not been tested on Windows*)
<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC8/blob/main/img/soic8_running.png" >
