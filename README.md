# FreeRTOS package for RX

## Summary

* The package gives us a minimal project that combines FreeRTOS kernel and application.
* Supported devices for FreeRTOS kernel demo are shown in the following table:

| CPU Core Type | FPU (Single Precision) | FPU (Double Precision) | Port Layer (CCRX) | Port Layer (GCC) | Port Layer (ICCRX) | RX MCU Group |
|:---:|:---:|:---:|:---:|:---:|:---:|:---|
| RXv1 | No | No | Renesas/RX100 | GCC/RX100 | IAR/RX100 | • RX130 |
| RXv2 | Yes | No | Renesas/RX600v2 | GCC/RX600v2 | IAR/RXv2 | • RX14T<br>• RX140<br>• RX230, RX231<br>• RX23E-A<br>• RX23E-B<br>• RX23W<br>• RX24T<br>• RX64M<br>• RX651, RX65N<br>• RX71M |
| RXv3 | Yes | No | Renesas/RX600v2 | GCC/RX600v2 | IAR/RXv2 | • RX260<br>• RX261<br>• RX26T<br>• RX66T<br>• RX660<br>• RX72T |
| RXv3 | Yes | Yes | Renesas/RX700v3 | GCC/RX700v3 | IAR/RXvRX700v3 | • RX66N<br>• RX671<br>• RX72M<br>• RX72N |


## Guide

See the [wiki](https://github.com/renesas/FreeRTOS-Kernel/wiki).

## Repository structure

* The root of this repository contains FreeRTOS kernel and Renesas tool collaboration files.
```
freertos-11.1.0-rx-x.x.x
+---configuration           : Renesas tool collaboration files. (xml, mdf)
|   +---config_files        : Configuration file for FreeRTOS. (FreeRTOSConfig.h)
|   +---patch_files         : Patch files to modify or fix FreeRTOS behavior or integration.
|   |   +---portable
|   |   \---RXv3
|   \---startup             : FreeRTOS startup codes.
\---kernel                  : FreeRTOS kernel as submodule.
```
