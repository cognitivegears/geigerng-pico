# Geigerng-pico

## Overview

This is a simple project to create a TRNG (True Random Number Generator) using the PICO microcontroller. This uses the output of a Geiger counter to generate random numbers. The Geiger counter is connected to the PICO via GPIO pins, and the PICO reads the output of the Geiger counter to generate random numbers. This is based on the [MightOhm Geiger Counter](https://mightohm.com/products/geiger-counter-kit). The Geiger counter is a simple circuit that uses a Geiger-Muller tube to detect ionizing radiation. The output of the Geiger counter is a pulse that is generated each time a particle of radiation is detected. The PICO microcontroller reads the output of the Geiger counter and uses the timing of the pulses to generate random numbers.

## Hardware
- Raspberry Pi PICO
- Geiger counter (MightOhm Geiger Counter Kit)

## Project Structure

```plaintext
geigerng-pico.c - C code for the PICO microcontroller
CMakeLists.txt - CMake file for the PICO microcontroller
README.md - This file
LICENSE - License file for the project
build/ - Directory for the build files
```

## Building the Project

To build the project, you will need to have CMake installed on your system from the Pico SDK. See the [Pico SDK documentation](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) for instructions on how to set up the Pico SDK and CMake. Verify that you have the Pico Cmake toolchain installed and in your PATH.

You can build the project by running the following commands in your terminal:

```shell
cd build && cmake .. && make; cd ..
```

## Instructions

1. Connect the Geiger counter to the PICO microcontroller.
2. Connect the PICO microcontroller to your computer via USB.
3. Build the project using the instructions above.
4. Upload the compiled code to the PICO microcontroller.
5. Open a serial terminal to the PICO microcontroller to see the output of the random number generator.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
