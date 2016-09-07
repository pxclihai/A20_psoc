# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\GIT\A20_CANfestival\posoc\Design01.cydsn\Design01.cyprj
# Date: Thu, 01 Sep 2016 09:35:38 GMT
#set_units -time ns
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.151515151515152 -waveform {0 7.57575757575758} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 15.151515151515152 -waveform {0 7.57575757575758} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 15.151515151515152 -waveform {0 7.57575757575758} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 67 133} -nominal_period 1000 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 73 145} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 7 11} -nominal_period 90.9090909090909 [list [get_pins {ClockBlock/dclk_glb_0}]]


# Component constraints for D:\GIT\A20_CANfestival\posoc\Design01.cydsn\TopDesign\TopDesign.cysch
# Project: D:\GIT\A20_CANfestival\posoc\Design01.cydsn\Design01.cyprj
# Date: Thu, 01 Sep 2016 09:35:31 GMT
