# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\TN02\Desktop\A20_CANfestival\A20Bootload\A66_canfestival_bootload\Workspace01\MOTION-T1-2016-09-18-ver1.0.cydsn\MOTION-T1-2016-09-18-ver1.0.cyprj
# Date: Tue, 20 Sep 2016 11:13:03 GMT
#set_units -time ns
create_clock -name {CyXTAL} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]


# Component constraints for C:\Users\TN02\Desktop\A20_CANfestival\A20Bootload\A66_canfestival_bootload\Workspace01\MOTION-T1-2016-09-18-ver1.0.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\TN02\Desktop\A20_CANfestival\A20Bootload\A66_canfestival_bootload\Workspace01\MOTION-T1-2016-09-18-ver1.0.cydsn\MOTION-T1-2016-09-18-ver1.0.cyprj
# Date: Tue, 20 Sep 2016 11:12:59 GMT
