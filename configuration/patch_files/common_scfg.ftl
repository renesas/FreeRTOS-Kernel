<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<smc>
    <general version="2.0.0.0">
        <configuration active="true" id="com.renesas.smc.toolchain.rxc.configuration.release">
            <property id="com.renesas.smc.service.project.buildArtefactType" values="com.renesas.smc.service.project.buildArtefactType.exe"/>
            <toolchain id="com.renesas.smc.toolchain.rxc.toolchain.rxc">
                <option id="com.renesas.smc.toolchain.option.language" key="com.renesas.smc.toolchain.option.language.c"/>
                <option id="com.renesas.smc.toolchain.option.buildArtefactType" key="com.renesas.smc.toolchain.option.buildArtefactType.exe"/>
                <option id="com.renesas.smc.toolchain.option.rtos" key="com.renesas.smc.toolchain.option.rtos.freertos.kernel">
                    <item id="com.renesas.smc.toolchain.option.rtos.freertos.kernel" value="10.4.3-rx-1.0.8"/>
                </option>
                <option id="com.renesas.smc.toolchain.option.dual" key="com.renesas.smc.toolchain.option.dual.false"/>
            </toolchain>
        </configuration>
        <platform id="${targetDevice}"/>
    </general>
    <tool id="SWComponent" version="1.0.0.0">
        <configuration inuse="true" name="r_bsp">
            <component description="Dependencies : None&#10;The r_bsp package provides a foundation for code to be built on top of. It provides startup code, iodefines, and MCU information for different boards. There are 2 folders that make up the r_bsp package. The 'mcu' folder contains files that are common to a MCU group. These files provide functionality such as easy register access, CPU functions, and a file named 'mcu_info.h' for each MCU group. The 'mcu_info.h' file has information about the MCU on the board and is configured based on the information given in r_bsp_config.h. The information in 'mcu_info.h' is used to help configure Renesas middleware that uses the r_bsp package. The 'board' folder has a folder with startup code for each supported board.  Which MCU and board is chosen is decided by the settings in 'platform.h'. The user can choose which board they are using by uncommenting the include path that applies to their board. For example, if you are using the RSK+RX64M then you would uncomment the #include &quot;./board/generic_rx64m/r_bsp.h&quot; include path. Users are encouraged to add their own boards to the 'board' directory. BSPs are configured by using the r_bsp_config.h file. Each board will have a reference configuration file named r_bsp_config_reference.h. The user should copy this file to their project, rename it to r_bsp_config.h, and use the options inside the file to configure the BSP for their project." detailDescription="Board Support Packages." display="r_bsp" id="r_bsp7.41" version="7.41"/>
            <source description="Components supporting Firmware Integration Technology" display="Firmware Integration Technology" id="com.renesas.smc.tools.swcomponent.fit.source"/>
        </configuration>
        <configuration enable="true" exclude="false" id="8ccb1927-571f-4edb-b61c-d5beefbf1ab7" inuse="true" name="FreeRTOS_Kernel">
            <component description="This component is a part of RTOS Configurator feature that allow user to use the GUI to configure kernel setting of FreeRTOS." detailDescription="" display="FreeRTOS_Kernel" id="com.renesas.smc.tools.swcomponent.rtosconfigurator.freertos.kernel" version="1.0.120"/>
            <source description="Code generator for Real-time OS" display="RTOS Configurator" id="com.renesas.smc.tools.swcomponent.rtosconfigurator.source"/>
        </configuration>
        <configuration enable="true" exclude="false" inuse="true" name="FreeRTOS Object">
            <allocatable id="" name="" type="">
                <allocatable id="TASK" name="TASK" type="">
                    <allocatable id="TASKOBJECTLINK1" name="TASK" type="" readonly="true">
                        <option defaultValue="1" id="Initialize" value="0"/>
                        <option defaultValue="task_[X]" id="TaskCode" value="main_task"/>
                        <option defaultValue="task_[X]" id="TaskName" value="MAIN_TASK"/>
                        <option defaultValue="512" id="StackSize" value="512"/>
                        <option defaultValue="NULL" id="TaskHandler" value="NULL"/>
                        <option defaultValue="NULL" id="Parameter" value="NULL"/>
                        <option defaultValue="1" id="Priority" value="3"/>
                    </allocatable>
                    <option defaultValue="0" id="LinkNum" value="1"/>
                </allocatable>
                <allocatable id="QUEUE" name="QUEUE" type="">
                    <option defaultValue="0" id="LinkNum" value=""/>
                </allocatable>
                <allocatable id="SEMAPHORE" name="SEMAPHORE" type="">
                    <option defaultValue="0" id="LinkNum" value=""/>
                </allocatable>
                <allocatable id="SWTIMER" name="SWTIMER" type="">
                    <option defaultValue="0" id="LinkNum" value=""/>
                </allocatable>
                <allocatable id="EVENTGROUP" name="EVENTGROUP" type="">
                    <option defaultValue="0" id="LinkNum" value=""/>
                </allocatable>
                <allocatable id="STREAMBUFFER" name="STREAMBUFFER" type="">
                    <option defaultValue="0" id="LinkNum" value=""/>
                </allocatable>
                <allocatable id="MESSAGEBUFFER" name="MESSAGEBUFFER" type="">
                    <option defaultValue="0" id="LinkNum" value=""/>
                </allocatable>
            </allocatable>			  
            <component description="This component is a part of RTOS Configurator feature that allow user to use the GUI to create and configure new object of FreeRTOS." detailDescription="" display="FreeRTOS_Object" id="com.renesas.smc.tools.swcomponent.rtosconfigurator.freertos.object" version="1.0.121"/>
            <source description="Code generator for Real-time OS" display="RTOS Configurator" id="com.renesas.smc.tools.swcomponent.rtosconfigurator.source"/>
        </configuration>
    </tool>
</smc>
