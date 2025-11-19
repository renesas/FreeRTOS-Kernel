The following table shows the available ports for your device:

----------------------------------------
RL78 MCU Group  CPU Core    Port Layer
                Type        CC-RL
----------------------------------------
RL78/G14        RL78-S3     Renesas/RL78
RL78/G23        RL78-S3     Renesas/RL78
----------------------------------------


For more information about Renesas RL78 MCUs, please visit the following URL:

https://www.renesas.com/products/microcontrollers-microprocessors/rl78-low-power-8-16-bit-mcus

--------------------------------------------------------------------------------

Limitation of the port Renesas/RL78

* Interrupt nesting is not supported.
* Only the register bank that was selected immediately before the kernel scheduler starts is used. 
  After the scheduler has started, do not change the register bank.
* The tickless idle mode is not supported.
  https://www.freertos.org/Documentation/02-Kernel/02-Kernel-features/07-Lower-power-support
