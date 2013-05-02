pwm 9 (base),10 (pitch),11 (claw)
the left side of the breadboard is signal and the right is power.
he left side is powered by the arduino 5V pin, so it is regulated 5V.
the right size is powered by the power supply at 6V without amperage limit.  This bus powers the Arduino into its Vin pin.

The fancy servos (with the threaded wires) are Hitec HS-7955TG
The other servos are Hextronik  hx12k.


Set the power supply to 6V. DO NOT USE MORE POWER!!!
Set the amps to the max. Set the voltage to 6v.

Range on the Servos:

const int clawClosedAngle = 110;
const int clawOpenedAngle =70;

const int armLowAngle=20;
const int armHiAngle=80;

const int baseClockWiseAngle=120;
const int baseCClockWiseAngle=70;

I will post a circut diagram.