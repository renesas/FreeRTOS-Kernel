# FreeRTOS package for RL78

## Summary

* The package gives us a simple Blinky demo projects that combines FreeRTOS kernel and application.
* Supported boards are RL78/G14 FPB and RL78/G23-128p FPB.

## Guide

* See the [FreeRTOS Blinky Demo(R20AN0819EJ0100)](https://www.renesas.com/products/rl78-g23)
* See the [wiki](https://github.com/renesas/FreeRTOS-Kernel/wiki).

## Repository structure

* FreeRTOS package for RL78 is under `RL78` folder.
  * The `./RL78/rl78g14_fpb_blinky` directory contains blinky demo projects for RL78/G14.
  * The `./RL78/rl78g23_fpb_blinky` directory contains blinky demo projects for RL78/G23.

* The root of this repository contains FreeRTOS kernel, application code, and FreeRTOS startup codes.
```
rl78g14_fpb_blinky 
├─.settings       : Settings for Code Generator.
│  └─CodeGenerator
├─generate        : Board startup.
└─src
    ├─application : Application codes.
    │  ├─app     : Application codes for a blinky demo.
    │  ├─config  : Configuration file for FreeRTOS. (FreeRTOSConfig.h)
    │  └─startup : FreeRTOS startup codes.
    └─kernel      : FreeRTOS kernel as submodule.

rl78g23_fpb_blinky 
└─src
    ├─application : Application codes.
    │  ├─app     : Application codes for a blinky demo.
    │  ├─config  : Configuration file for FreeRTOS. (FreeRTOSConfig.h)
    │  └─startup : FreeRTOS startup codes.
    ├─smg_gen     : Driver codes by Smart Configurator.
    └─kernel      : FreeRTOS kernel as submodule.
```