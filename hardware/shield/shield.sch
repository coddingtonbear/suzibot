EESchema Schematic File Version 2
LIBS:shield
LIBS:74xgxx
LIBS:74xx
LIBS:ac-dc
LIBS:actel
LIBS:adc-dac
LIBS:allegro
LIBS:Altera
LIBS:analog_devices
LIBS:analog_switches
LIBS:atmel
LIBS:audio
LIBS:battery_management
LIBS:bbd
LIBS:brooktre
LIBS:cmos_ieee
LIBS:cmos4000
LIBS:conn
LIBS:contrib
LIBS:cypress
LIBS:dc-dc
LIBS:device
LIBS:digital-audio
LIBS:diode
LIBS:display
LIBS:dsp
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:intel
LIBS:interface
LIBS:ir
LIBS:Lattice
LIBS:linear
LIBS:logo
LIBS:maxim
LIBS:mechanical
LIBS:memory
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:microchip
LIBS:microcontrollers
LIBS:motor_drivers
LIBS:motorola
LIBS:motors
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:onsemi
LIBS:opto
LIBS:Oscillators
LIBS:philips
LIBS:Power_Management
LIBS:power
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:regul
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:silabs
LIBS:siliconi
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:texas
LIBS:transf
LIBS:transistors
LIBS:ttl_ieee
LIBS:valves
LIBS:video
LIBS:wiznet
LIBS:Worldsemi
LIBS:Xicor
LIBS:xilinx
LIBS:zetex
LIBS:Zilog
LIBS:shield-cache
EELAYER 26 0
EELAYER END
$Descr A0 46811 33110
encoding utf-8
Sheet 1 1
Title "shield.sch"
Date "16 DEC 2016"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 10118193-0001LF_10118193-0001LF J10
U 1 1 58543665
P 9000 6550
F 0 "J10" H 8990 6540 65  0001 L TNN
F 1 "10118193-0001LF" H 8990 6440 65  0001 L TNN
F 2 "shield:10118193-0001LF_10118193-0001LF" H 8990 6340 65  0001 L TNN
F 3 "" H 9000 6550 60  0001 C CNN
	1    9000 6550
	0    -1   -1   0   
$EndComp
$Comp
L CH340G_CH340G U$1
U 1 1 5854453D
P 9900 7850
F 0 "U$1" H 9890 7840 65  0001 L TNN
F 1 "CH340G" H 9701 8350 70  0000 L BNN
F 2 "shield:CH340G_SOIC16" H 9890 7640 65  0001 L TNN
F 3 "" H 9900 7850 60  0001 C CNN
	1    9900 7850
	1    0    0    -1  
$EndComp
$Comp
L TEXAS_TXS0101DBVR U$2
U 1 1 58544605
P 11900 5250
F 0 "U$2" H 11890 5240 65  0001 L TNN
F 1 "TXS0101DBVR" H 11890 5140 65  0001 L TNN
F 2 "shield:TEXAS_SOT-23-6" H 11890 5040 65  0001 L TNN
F 3 "" H 11900 5250 60  0001 C CNN
	1    11900 5250
	-1   0    0    1   
$EndComp
$Comp
L TEXAS_TXS0101DBVR U$3
U 1 1 585446CD
P 14000 8650
F 0 "U$3" H 13990 8640 65  0001 L TNN
F 1 "TXS0101DBVR" H 13990 8540 65  0001 L TNN
F 2 "shield:TEXAS_SOT-23-6" H 13990 8440 65  0001 L TNN
F 3 "" H 14000 8650 60  0001 C CNN
	1    14000 8650
	0    1    1    0   
$EndComp
Wire Wire Line
	11800 6150 11800 8250
Wire Wire Line
	11800 7450 12100 7150
Wire Wire Line
	12100 7150 12700 7150
Wire Wire Line
	12000 8450 12400 8450
Wire Wire Line
	11800 8250 12000 8450
Wire Wire Line
	12000 8450 11800 8650
Wire Wire Line
	11800 8650 11800 9350
Wire Wire Line
	11800 9350 10900 10250
Wire Wire Line
	10900 10250 9700 10250
Wire Wire Line
	9700 10250 9500 10050
Wire Wire Line
	10200 10050 10200 10250
Wire Wire Line
	11800 6150 12000 5950
Wire Wire Line
	12000 5950 12600 5950
Wire Wire Line
	12600 5950 12800 5750
Wire Wire Line
	12800 5750 12600 5550
Wire Wire Line
	12400 8450 12600 8250
Wire Wire Line
	12600 8250 13700 8250
Wire Wire Line
	13700 8250 14200 7750
Wire Wire Line
	14200 7750 14300 7750
Wire Wire Line
	14300 7750 14300 7950
Connection ~ 12300 8450
Connection ~ 12000 8450
Connection ~ 10200 10250
Connection ~ 11800 7450
Connection ~ 12400 8450
Wire Wire Line
	9300 8950 9000 8650
Wire Wire Line
	9000 8650 9000 7750
Wire Wire Line
	9000 7750 9600 7150
Wire Wire Line
	10100 6750 10600 7250
Wire Wire Line
	10600 7250 10600 7350
Wire Wire Line
	10600 7350 10500 7450
Wire Wire Line
	10500 7450 10400 7450
Wire Wire Line
	9600 7150 10500 7150
Wire Wire Line
	10300 7150 10100 6950
Wire Wire Line
	11400 8850 11400 6050
Wire Wire Line
	12000 9050 13800 9050
Wire Wire Line
	11900 8950 12000 9050
Wire Wire Line
	9300 8950 11900 8950
Wire Wire Line
	11300 8950 11400 8850
Wire Wire Line
	11400 6050 11300 5950
Wire Wire Line
	11300 5950 11300 5750
Wire Wire Line
	11300 5750 11500 5550
Wire Wire Line
	11400 4850 11300 4750
Wire Wire Line
	11300 4750 11200 4850
Wire Wire Line
	11200 4850 11200 5650
Wire Wire Line
	11200 5650 11300 5750
Wire Wire Line
	13800 9050 14000 9250
Wire Wire Line
	14000 9250 14300 9250
Wire Wire Line
	14300 9250 14300 9050
Wire Wire Line
	13400 8750 13100 9050
Connection ~ 10300 7150
Connection ~ 10500 7150
Connection ~ 11300 8950
Connection ~ 11000 8950
Connection ~ 10700 8950
Connection ~ 10400 8950
Connection ~ 10100 8950
Connection ~ 11300 5750
Connection ~ 12300 9050
Connection ~ 13100 9050
Wire Wire Line
	10100 9250 13800 9250
Wire Wire Line
	10400 7750 10500 7750
Wire Wire Line
	10500 7750 10600 7850
Wire Wire Line
	10600 7850 10600 8150
Wire Wire Line
	10600 8150 10400 8350
Wire Wire Line
	10400 8350 10000 8350
Wire Wire Line
	10000 8350 9900 8450
Wire Wire Line
	9900 8450 9900 9050
Wire Wire Line
	9900 9050 10100 9250
Wire Wire Line
	13800 9250 13900 9350
Wire Wire Line
	13900 9350 14400 9350
Wire Wire Line
	14400 9350 14400 9050
Connection ~ 11000 9250
Connection ~ 10700 9250
Wire Wire Line
	9300 8750 9200 8650
Wire Wire Line
	9200 8650 9200 7850
Wire Wire Line
	9200 7850 9300 7750
Wire Wire Line
	9300 7750 9300 7550
Wire Wire Line
	9300 7550 9400 7450
Wire Wire Line
	8000 8050 7900 8150
Wire Wire Line
	7900 8150 7900 8650
Wire Wire Line
	7900 8650 8200 8950
Wire Wire Line
	8200 8950 8900 8950
Wire Wire Line
	8900 8950 9200 8650
Wire Wire Line
	8000 8450 7900 8550
Wire Wire Line
	9400 7450 9400 7050
Wire Wire Line
	9800 6950 9500 6950
Wire Wire Line
	9500 6950 9400 7050
Wire Wire Line
	9800 6750 9700 6750
Wire Wire Line
	9700 6750 9500 6950
Wire Wire Line
	9300 8750 11100 8750
Wire Wire Line
	11100 8750 11300 8550
Wire Wire Line
	11300 8550 11800 8550
Wire Wire Line
	12100 7250 12700 7250
Wire Wire Line
	11900 7450 12500 6850
Wire Wire Line
	11900 7450 11900 8450
Wire Wire Line
	11900 8450 11800 8550
Wire Wire Line
	12600 8750 12700 8650
Wire Wire Line
	12700 8650 12700 8550
Wire Wire Line
	12700 8550 12200 8050
Wire Wire Line
	12200 8050 11900 8050
Wire Wire Line
	12500 6850 12500 5850
Wire Wire Line
	12500 5850 12800 5550
Wire Wire Line
	12800 5550 12600 5350
Wire Wire Line
	14100 7950 13900 7950
Wire Wire Line
	13900 7950 13700 8150
Wire Wire Line
	13700 8150 12300 8150
Wire Wire Line
	9100 7150 9400 7150
Connection ~ 9400 7450
Connection ~ 9200 8650
Connection ~ 7900 8550
Connection ~ 9500 6950
Connection ~ 10100 8750
Connection ~ 10400 8750
Connection ~ 10700 8750
Connection ~ 11000 8750
Connection ~ 11900 8050
Connection ~ 12100 7250
Connection ~ 12300 8150
Connection ~ 9400 7150
Wire Wire Line
	12700 6150 12400 6150
Wire Wire Line
	12400 6150 12300 6050
Wire Wire Line
	12300 6050 12300 5950
Wire Wire Line
	12300 5950 12400 5850
Wire Wire Line
	12400 5850 12600 5850
Wire Wire Line
	12600 5850 12700 5750
Wire Wire Line
	12700 5750 12600 5650
Wire Wire Line
	10500 9950 10500 9050
Wire Wire Line
	10300 10150 10500 9950
Wire Wire Line
	9700 10050 9800 10150
Wire Wire Line
	9800 10150 10300 10150
Wire Wire Line
	10700 8850 11000 8850
Wire Wire Line
	10500 9050 10700 8850
Connection ~ 10400 10050
Connection ~ 10700 8850
Wire Wire Line
	8300 8050 9400 8050
Wire Wire Line
	9400 7850 9000 7450
Wire Wire Line
	9000 7450 9000 6150
Wire Wire Line
	8300 8450 9300 8450
Wire Wire Line
	9300 8450 9400 8350
Wire Wire Line
	9400 8350 9400 8150
Wire Wire Line
	8300 9550 11000 9550
Wire Wire Line
	8800 6150 8700 6050
Wire Wire Line
	8700 6050 8600 6050
Wire Wire Line
	8600 6050 7500 7150
Wire Wire Line
	7500 7150 7500 8750
Wire Wire Line
	7500 8750 8300 9550
Connection ~ 10700 9550
Wire Wire Line
	8900 6150 8900 7450
Wire Wire Line
	8900 7450 9400 7950
Wire Wire Line
	9400 7750 9100 7450
Wire Wire Line
	10700 8450 11000 8450
Wire Wire Line
	11000 8350 10700 8350
Wire Wire Line
	10700 8250 11000 8250
Wire Wire Line
	11000 8150 10700 8150
Wire Wire Line
	10700 8050 11000 8050
Wire Wire Line
	11000 7950 10700 7950
Wire Wire Line
	10700 7850 11000 7850
Wire Wire Line
	11000 7750 10700 7750
Wire Wire Line
	11000 7450 10700 7450
Wire Wire Line
	10700 7350 11000 7350
Wire Wire Line
	11000 7250 10700 7250
Wire Wire Line
	10700 9650 11000 9650
Wire Wire Line
	11000 7050 10700 7050
Wire Wire Line
	10700 6950 11000 6950
Wire Wire Line
	11000 6850 10700 6850
Wire Wire Line
	10700 6750 11000 6750
Wire Wire Line
	11000 6450 10700 6450
Wire Wire Line
	10700 6350 11000 6350
Wire Wire Line
	11000 6250 10700 6250
Wire Wire Line
	10700 6150 11000 6150
Wire Wire Line
	11000 6050 10700 6050
Wire Wire Line
	10700 5950 11000 5950
Wire Wire Line
	11000 5850 10700 5850
Wire Wire Line
	10700 5750 11000 5750
Wire Wire Line
	11000 5450 10700 5450
Wire Wire Line
	10700 5350 11000 5350
Wire Wire Line
	11000 5250 10700 5250
Wire Wire Line
	10700 5150 11000 5150
Wire Wire Line
	11000 5050 10700 5050
Wire Wire Line
	10700 4950 11000 4950
Wire Wire Line
	11000 4850 10700 4850
Wire Wire Line
	10700 4750 11000 4750
Wire Wire Line
	11000 9750 10700 9750
Wire Wire Line
	9200 6150 8900 5850
Wire Wire Line
	8900 5850 8500 5850
Wire Wire Line
	8500 5850 7300 7050
Wire Wire Line
	7300 7050 7300 8850
Wire Wire Line
	7300 8850 9100 10650
Wire Wire Line
	9100 10650 10000 10650
Wire Wire Line
	10000 10650 10600 10050
Wire Wire Line
	10600 10050 10600 9850
Wire Wire Line
	10600 9850 10700 9750
Connection ~ 10700 9750
Wire Wire Line
	14100 6850 14200 6850
Wire Wire Line
	14400 7950 14400 7050
Wire Wire Line
	14400 7050 14200 6850
Wire Wire Line
	9600 10050 9600 9050
Wire Wire Line
	9600 9050 9800 8850
Wire Wire Line
	9800 8850 10100 8850
Wire Wire Line
	10300 10050 10300 8950
Wire Wire Line
	10300 8950 10400 8850
Wire Wire Line
	11500 5350 11400 5250
Wire Wire Line
	14100 9050 13800 8750
Wire Wire Line
	10700 7150 11000 7150
Wire Wire Line
	9500 9350 11300 9350
Wire Wire Line
	9400 7650 9000 7650
Wire Wire Line
	9000 7650 8800 7850
Wire Wire Line
	8800 7850 8800 8650
Wire Wire Line
	8800 8650 9500 9350
Wire Wire Line
	11300 9350 11500 9150
Wire Wire Line
	11500 9150 11500 6050
Wire Wire Line
	11500 6050 11400 5950
Wire Wire Line
	11400 5950 11400 5750
Wire Wire Line
	11400 5750 11500 5650
Connection ~ 11000 9350
Connection ~ 10700 9350
Wire Wire Line
	9700 9450 11300 9450
Wire Wire Line
	9400 7550 8900 8050
Wire Wire Line
	8900 8050 8900 8650
Wire Wire Line
	8900 8650 9700 9450
Wire Wire Line
	12700 6050 12600 6050
Wire Wire Line
	12600 6050 11600 7050
Wire Wire Line
	11600 7050 11600 9150
Wire Wire Line
	11600 9150 11300 9450
Connection ~ 11000 9450
Connection ~ 10700 9450
Text Label 12700 7150 2    10   ~ 0
3V3
Text Label 12300 8450 1    10   ~ 0
3V3
Text Label 12400 8450 1    10   ~ 0
3V3
Text Label 9500 10050 3    10   ~ 0
3V3
Text Label 10200 10050 3    10   ~ 0
3V3
Text Label 12600 5550 0    10   ~ 0
3V3
Text Label 14300 7950 1    10   ~ 0
3V3
Text Label 10400 7450 0    10   ~ 0
5V
Text Label 10100 6950 0    10   ~ 0
5V
Text Label 10100 6750 0    10   ~ 0
5V
Text Label 12300 9050 3    10   ~ 0
5V
Text Label 11000 8950 2    10   ~ 0
5V
Text Label 10700 8950 2    10   ~ 0
5V
Text Label 10400 8950 2    10   ~ 0
5V
Text Label 10100 8950 2    10   ~ 0
5V
Text Label 11500 5550 2    10   ~ 0
5V
Text Label 11400 4850 1    10   ~ 0
5V
Text Label 14300 9050 3    10   ~ 0
5V
Text Label 13400 8750 2    10   ~ 0
5V
Text Label 11000 9250 2    10   ~ 0
DTR
Text Label 10400 7750 0    10   ~ 0
DTR
Text Label 10700 9250 2    10   ~ 0
DTR
Text Label 14400 9050 3    10   ~ 0
DTR
Text Label 9400 7450 2    10   ~ 0
GND
Text Label 8000 8050 2    10   ~ 0
GND
Text Label 8000 8450 2    10   ~ 0
GND
Text Label 9800 6950 2    10   ~ 0
GND
Text Label 9800 6750 2    10   ~ 0
GND
Text Label 10100 8750 2    10   ~ 0
GND
Text Label 10400 8750 2    10   ~ 0
GND
Text Label 10700 8750 2    10   ~ 0
GND
Text Label 11000 8750 2    10   ~ 0
GND
Text Label 12700 7250 2    10   ~ 0
GND
Text Label 12600 8750 0    10   ~ 0
GND
Text Label 12600 5350 0    10   ~ 0
GND
Text Label 14100 7950 1    10   ~ 0
GND
Text Label 9100 7150 1    10   ~ 0
GND
Text Label 12700 6150 2    10   ~ 0
N$1
Text Label 12600 5650 0    10   ~ 0
N$1
Text Label 10400 10050 3    10   ~ 0
N$2
Text Label 9700 10050 3    10   ~ 0
N$2
Text Label 10700 8850 2    10   ~ 0
N$2
Text Label 11000 8850 2    10   ~ 0
N$2
Text Label 9400 8050 2    10   ~ 0
N$3
Text Label 8300 8050 0    10   ~ 0
N$3
Text GLabel 9400 7850 0    10   UnSpc ~ 0
N$4
Text GLabel 9000 6150 1    10   UnSpc ~ 0
N$4
Text Label 9400 8150 2    10   ~ 0
N$5
Text Label 8300 8450 0    10   ~ 0
N$5
Text Label 11000 9550 2    10   ~ 0
N$6
Text Label 10700 9550 2    10   ~ 0
N$6
Text Label 8800 6150 1    10   ~ 0
N$6
Text Label 8900 6150 1    10   ~ 0
N$7
Text Label 9400 7950 2    10   ~ 0
N$7
Text Label 9400 7750 2    10   ~ 0
N$8
Text Label 9100 7450 3    10   ~ 0
N$8
Text Label 10700 8450 2    10   ~ 0
N$9
Text Label 11000 8450 2    10   ~ 0
N$9
Text Label 11000 8350 2    10   ~ 0
N$10
Text Label 10700 8350 2    10   ~ 0
N$10
Text Label 10700 8250 2    10   ~ 0
N$11
Text Label 11000 8250 2    10   ~ 0
N$11
Text Label 11000 8150 2    10   ~ 0
N$12
Text Label 10700 8150 2    10   ~ 0
N$12
Text Label 10700 8050 2    10   ~ 0
N$13
Text Label 11000 8050 2    10   ~ 0
N$13
Text Label 11000 7950 2    10   ~ 0
N$14
Text Label 10700 7950 2    10   ~ 0
N$14
Text Label 10700 7850 2    10   ~ 0
N$15
Text Label 11000 7850 2    10   ~ 0
N$15
Text Label 11000 7750 2    10   ~ 0
N$16
Text Label 10700 7750 2    10   ~ 0
N$16
Text Label 11000 7450 2    10   ~ 0
N$17
Text Label 10700 7450 2    10   ~ 0
N$17
Text Label 10700 7350 2    10   ~ 0
N$18
Text Label 11000 7350 2    10   ~ 0
N$18
Text Label 11000 7250 2    10   ~ 0
N$19
Text Label 10700 7250 2    10   ~ 0
N$19
Text Label 10700 9650 2    10   ~ 0
N$20
Text Label 11000 9650 2    10   ~ 0
N$20
Text Label 11000 7050 2    10   ~ 0
N$21
Text Label 10700 7050 2    10   ~ 0
N$21
Text Label 10700 6950 2    10   ~ 0
N$22
Text Label 11000 6950 2    10   ~ 0
N$22
Text Label 11000 6850 2    10   ~ 0
N$23
Text Label 10700 6850 2    10   ~ 0
N$23
Text Label 10700 6750 2    10   ~ 0
N$24
Text Label 11000 6750 2    10   ~ 0
N$24
Text Label 11000 6450 2    10   ~ 0
N$25
Text Label 10700 6450 2    10   ~ 0
N$25
Text Label 10700 6350 2    10   ~ 0
N$26
Text Label 11000 6350 2    10   ~ 0
N$26
Text Label 11000 6250 2    10   ~ 0
N$27
Text Label 10700 6250 2    10   ~ 0
N$27
Text Label 10700 6150 2    10   ~ 0
N$28
Text Label 11000 6150 2    10   ~ 0
N$28
Text Label 11000 6050 2    10   ~ 0
N$29
Text Label 10700 6050 2    10   ~ 0
N$29
Text Label 10700 5950 2    10   ~ 0
N$30
Text Label 11000 5950 2    10   ~ 0
N$30
Text Label 11000 5850 2    10   ~ 0
N$31
Text Label 10700 5850 2    10   ~ 0
N$31
Text Label 10700 5750 2    10   ~ 0
N$32
Text Label 11000 5750 2    10   ~ 0
N$32
Text Label 11000 5450 2    10   ~ 0
N$33
Text Label 10700 5450 2    10   ~ 0
N$33
Text Label 10700 5350 2    10   ~ 0
N$34
Text Label 11000 5350 2    10   ~ 0
N$34
Text Label 11000 5250 2    10   ~ 0
N$35
Text Label 10700 5250 2    10   ~ 0
N$35
Text Label 10700 5150 2    10   ~ 0
N$36
Text Label 11000 5150 2    10   ~ 0
N$36
Text Label 11000 5050 2    10   ~ 0
N$37
Text Label 10700 5050 2    10   ~ 0
N$37
Text Label 10700 4950 2    10   ~ 0
N$38
Text Label 11000 4950 2    10   ~ 0
N$38
Text Label 11000 4850 2    10   ~ 0
N$39
Text Label 10700 4850 2    10   ~ 0
N$39
Text Label 10700 4750 2    10   ~ 0
N$40
Text Label 11000 4750 2    10   ~ 0
N$40
Text Label 11000 9750 2    10   ~ 0
N$41
Text Label 10700 9750 2    10   ~ 0
N$41
Text Label 9200 6150 1    10   ~ 0
N$41
Text Label 14100 6850 0    10   ~ 0
N$43
Text Label 14400 7950 1    10   ~ 0
N$43
Text Label 9600 10050 3    10   ~ 0
N$44
Text Label 10100 8850 2    10   ~ 0
N$44
Text Label 10300 10050 3    10   ~ 0
N$45
Text Label 10400 8850 2    10   ~ 0
N$45
Text Label 11500 5350 2    10   ~ 0
N$46
Text Label 11400 5250 3    10   ~ 0
N$46
Text Label 14100 9050 3    10   ~ 0
N$49
Text Label 13800 8750 0    10   ~ 0
N$49
Text Label 10700 7150 2    10   ~ 0
PB
Text Label 11000 7150 2    10   ~ 0
PB
Text Label 11000 9350 2    10   ~ 0
RXD
Text Label 9400 7650 2    10   ~ 0
RXD
Text Label 10700 9350 2    10   ~ 0
RXD
Text Label 11500 5650 2    10   ~ 0
RXD
Text Label 11000 9450 2    10   ~ 0
TXD
Text Label 9400 7550 2    10   ~ 0
TXD
Text Label 10700 9450 2    10   ~ 0
TXD
Text Label 12700 6050 2    10   ~ 0
TXD
$Comp
L JNHUAMAO_HM-10 E1
U 1 1 5858EFC0
P 12900 5650
F 0 "E1" H 13400 5726 45  0000 C CNN
F 1 "JNHUAMAO_HM-10" V 12900 5650 45  0001 L BNN
F 2 "shield:JNHUAMAO_26.9X13X2.2_BOARD" H 12900 5650 60  0001 C CNN
F 3 "" H 12900 5650 60  0001 C CNN
	1    12900 5650
	1    0    0    -1  
$EndComp
$Comp
L SPARKFUN-POWERIC_V_REG_LM1117 U1
U 1 1 5858F24B
P 12300 8750
F 0 "U1" V 12342 8878 45  0000 L CNN
F 1 "LM1117" V 12258 8878 45  0000 L CNN
F 2 "shield:SPARKFUN-POWERIC_SOT223" H 12300 8750 60  0001 C CNN
F 3 "" H 12300 8750 60  0001 C CNN
	1    12300 8750
	0    -1   -1   0   
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X08 PA1
U 1 1 5858F7D1
P 10700 5050
F 0 "PA1" H 10909 5000 45  0000 L CNN
F 1 "PA1" H 10700 5050 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X8" H 10700 5050 60  0001 C CNN
F 3 "" H 10700 5050 60  0001 C CNN
	1    10700 5050
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X08 PA0
U 1 1 5858FA8B
P 11000 5050
F 0 "PA0" H 11209 5000 45  0000 L CNN
F 1 "PA0" H 11000 5050 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X8" H 11000 5050 60  0001 C CNN
F 3 "" H 11000 5050 60  0001 C CNN
	1    11000 5050
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X08 PB0
U 1 1 5858FE3B
P 11000 6050
F 0 "PB0" H 11209 6000 45  0000 L CNN
F 1 "PB0" H 11000 6050 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X8" H 11000 6050 60  0001 C CNN
F 3 "" H 11000 6050 60  0001 C CNN
	1    11000 6050
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X08 PB1
U 1 1 5858FEC7
P 10700 6050
F 0 "PB1" H 10909 6000 45  0000 L CNN
F 1 "PB1" H 10700 6050 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X8" H 10700 6050 60  0001 C CNN
F 3 "" H 10700 6050 60  0001 C CNN
	1    10700 6050
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X08 PC0
U 1 1 5858FFDE
P 11000 7050
F 0 "PC0" H 11209 7000 45  0000 L CNN
F 1 "PC0" H 11000 7050 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X8" H 11000 7050 60  0001 C CNN
F 3 "" H 11000 7050 60  0001 C CNN
	1    11000 7050
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X08 PC1
U 1 1 58590054
P 10700 7050
F 0 "PC1" H 10909 7000 45  0000 L CNN
F 1 "PC1" H 10700 7050 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X8" H 10700 7050 60  0001 C CNN
F 3 "" H 10700 7050 60  0001 C CNN
	1    10700 7050
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X08 PD0
U 1 1 58590192
P 11000 8050
F 0 "PD0" H 11209 8000 45  0000 L CNN
F 1 "PD0" H 11000 8050 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X8" H 11000 8050 60  0001 C CNN
F 3 "" H 11000 8050 60  0001 C CNN
	1    11000 8050
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X08 PD1
U 1 1 5859020A
P 10700 8050
F 0 "PD1" H 10909 8000 45  0000 L CNN
F 1 "PD1" H 10700 8050 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X8" H 10700 8050 60  0001 C CNN
F 3 "" H 10700 8050 60  0001 C CNN
	1    10700 8050
	1    0    0    -1  
$EndComp
$Comp
L SPARKFUN-PASSIVES_RESISTOR R2
U 1 1 58590547
P 13600 8750
F 0 "R2" H 13600 8944 45  0000 C CNN
F 1 "10k" H 13600 8860 45  0000 C CNN
F 2 "shield:SPARKFUN-PASSIVES_0603-RES" H 13600 8750 60  0001 C CNN
F 3 "" H 13600 8750 60  0001 C CNN
	1    13600 8750
	1    0    0    -1  
$EndComp
$Comp
L SPARKFUN-PASSIVES_RESISTOR R1
U 1 1 585907DE
P 11400 5050
F 0 "R1" V 11358 5118 45  0000 L CNN
F 1 "10k" V 11442 5118 45  0000 L CNN
F 2 "shield:SPARKFUN-PASSIVES_0603-RES" H 11400 5050 60  0001 C CNN
F 3 "" H 11400 5050 60  0001 C CNN
	1    11400 5050
	0    1    1    0   
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X06 PROG0
U 1 1 58590BB9
P 11000 9450
F 0 "PROG0" H 11209 9400 45  0000 L CNN
F 1 "PROG0" H 11000 9450 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X6" H 11000 9450 60  0001 C CNN
F 3 "" H 11000 9450 60  0001 C CNN
	1    11000 9450
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X06 PROG1
U 1 1 58590C2F
P 10700 9450
F 0 "PROG1" H 10909 9400 45  0000 L CNN
F 1 "PROG1" H 10700 9450 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X6" H 10700 9450 60  0001 C CNN
F 3 "" H 10700 9450 60  0001 C CNN
	1    10700 9450
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X03 PWR0
U 1 1 58590F10
P 11000 8850
F 0 "PWR0" H 11209 8850 45  0000 L CNN
F 1 "PWR0" H 11000 8850 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X3" H 11000 8850 60  0001 C CNN
F 3 "" H 11000 8850 60  0001 C CNN
	1    11000 8850
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X03 PWR1
U 1 1 58590F7A
P 10700 8850
F 0 "PWR1" H 10909 8850 45  0000 L CNN
F 1 "PWR1" H 10700 8850 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X3" H 10700 8850 60  0001 C CNN
F 3 "" H 10700 8850 60  0001 C CNN
	1    10700 8850
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X03 PWR2
U 1 1 58590FF4
P 10400 8850
F 0 "PWR2" H 10609 8850 45  0000 L CNN
F 1 "PWR2" H 10400 8850 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X3" H 10400 8850 60  0001 C CNN
F 3 "" H 10400 8850 60  0001 C CNN
	1    10400 8850
	1    0    0    -1  
$EndComp
$Comp
L DP_DEVICES.V6_CON_HEADER_1X03 PWR3
U 1 1 58591062
P 10100 8850
F 0 "PWR3" H 10309 8850 45  0000 L CNN
F 1 "PWR3" H 10100 8850 45  0001 L BNN
F 2 "shield:DP_DEVICES.V6_M1X3" H 10100 8850 60  0001 C CNN
F 3 "" H 10100 8850 60  0001 C CNN
	1    10100 8850
	1    0    0    -1  
$EndComp
$Comp
L SPARKFUN-CAPACITORS_CAP C3
U 1 1 58591362
P 9100 7350
F 0 "C3" H 9208 7442 45  0000 L CNN
F 1 "0.01u" H 9208 7358 45  0000 L CNN
F 2 "shield:SPARKFUN-CAPACITORS_0603-CAP" H 9100 7350 60  0001 C CNN
F 3 "" H 9100 7350 60  0001 C CNN
	1    9100 7350
	1    0    0    -1  
$EndComp
$Comp
L SPARKFUN-CAPACITORS_CAP C5
U 1 1 58591677
P 9900 6950
F 0 "C5" V 9666 7000 45  0000 C CNN
F 1 "0.1u" V 9750 7000 45  0000 C CNN
F 2 "shield:SPARKFUN-CAPACITORS_0603-CAP" H 9900 6950 60  0001 C CNN
F 3 "" H 9900 6950 60  0001 C CNN
	1    9900 6950
	0    1    1    0   
$EndComp
$Comp
L SPARKFUN-CAPACITORS_CAP C1
U 1 1 58591C34
P 8100 8050
F 0 "C1" V 7866 8100 45  0000 C CNN
F 1 "22p" V 7950 8100 45  0000 C CNN
F 2 "shield:SPARKFUN-CAPACITORS_0603-CAP" H 8100 8050 60  0001 C CNN
F 3 "" H 8100 8050 60  0001 C CNN
	1    8100 8050
	0    1    1    0   
$EndComp
$Comp
L SPARKFUN-CAPACITORS_CAP C2
U 1 1 58591CC3
P 8100 8450
F 0 "C2" V 7866 8500 45  0000 C CNN
F 1 "22p" V 7950 8500 45  0000 C CNN
F 2 "shield:SPARKFUN-CAPACITORS_0603-CAP" H 8100 8450 60  0001 C CNN
F 3 "" H 8100 8450 60  0001 C CNN
	1    8100 8450
	0    1    1    0   
$EndComp
$Comp
L SPARKFUN-CAPACITORS_CAP C4
U 1 1 58591758
P 9900 6750
F 0 "C4" V 9666 6800 45  0000 C CNN
F 1 "22u" V 9750 6800 45  0000 C CNN
F 2 "shield:SPARKFUN-CAPACITORS_AXIAL-5MM" H 9900 6750 60  0001 C CNN
F 3 "" H 9900 6750 60  0001 C CNN
	1    9900 6750
	0    1    1    0   
$EndComp
$Comp
L SPARKFUN-RETIRED_JUMPER-3 JP1
U 1 1 5859228A
P 9500 9950
F 0 "JP1" H 9753 9986 45  0000 L CNN
F 1 "3v3Src1" H 9753 9902 45  0000 L CNN
F 2 "shield:SPARKFUN-RETIRED_SJ_3" H 9500 9950 60  0001 C CNN
F 3 "" H 9500 9950 60  0001 C CNN
	1    9500 9950
	1    0    0    -1  
$EndComp
$Comp
L SPARKFUN-RETIRED_JUMPER-3 JP2
U 1 1 58592301
P 10200 9950
F 0 "JP2" H 10453 9986 45  0000 L CNN
F 1 "3v3Src2" H 10453 9902 45  0000 L CNN
F 2 "shield:SPARKFUN-RETIRED_SJ_3" H 10200 9950 60  0001 C CNN
F 3 "" H 10200 9950 60  0001 C CNN
	1    10200 9950
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 58599F78
P 8500 8250
F 0 "Y1" V 8546 8119 50  0000 R CNN
F 1 "Crystal" V 8455 8119 50  0000 R CNN
F 2 "Crystals:HC-49V" H 8500 8250 50  0001 C CNN
F 3 "" H 8500 8250 50  0000 C CNN
	1    8500 8250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8550 8100 8500 8100
Wire Wire Line
	8550 8050 8550 8100
Wire Wire Line
	8500 8450 8500 8400
Connection ~ 8500 8450
Connection ~ 8550 8050
Text Label 9300 8050 0    60   ~ 0
XI
$EndSCHEMATC
