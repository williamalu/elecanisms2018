## Hardware Setup

You will need:
* 1 PIC24 "Braduino" board
* 1 breadboard
* 1 normally open button
* 1 10k ohm resistor
* 3 jumper wires

1. Insert the button into the breadboard, making sure that the leads are in two separate (i.e. not connected) rows.
2. Using a jumper wire, connect one lead of the button to the Vdd pin on your Braduino.
3. Using another jumper wire, connect the second lead of the button to the D0 pin on your Braduino.
4. Take your 10k ohm resistor and connect the lead of the button that is connected to the D0 pin on your Braduino to an adjacent, unused row on your breadboard.
5. Connect the unconnected leg of your 10k ohm resistor and connect it to ground.

## Firmware/Software Setup

1. Follow the instructions in [http://elecanisms.olin.edu/handouts/1.1_BuildTools.pdf] to install the XC16 compiler from Microchip and the SCons build system.
2. Follow the instructions in [https://github.com/williamalu/elecanisms2018/blob/master/bootloader/README.txt] to install all the host software that allows you to program your Braduino.
3. Clone this repository to your computer by typing this into a terminal:
``` 
git clone https://github.com/williamalu/elecanisms2018.git
```
4. In your terminal, navigate to "/elecanisms2018/blinkint".
5. Run the `scons` command. This will compile the firmware and generate a .hex file that you can upload to your Braduino.
6. Run the bootloadergui interface that allows you to program your Braduino by typing this:
```
python ../bootloader/software/bootloadergui.py
```
7. While holding the SW1 button on the Braduino, plug it into your computer.
8. Press the Connect button on the bootloadergui interface.
9. Go to the File menu at the top and click Import Hex... and use the Open File dialog to choose the .hex file you just generated in Step 5. Click Open to open the .hex file.
10. Press the Write button to program your Braduino with the .hex file you just selected.
11. Press the Disconnect/Run button to allow the Braduino to run the .hex file you just programmed.

## Using blinkint

Blinkint displays counting in binary up to the number 7 on the 3 LEDs on the Braduino. If you press the button you connected to your Braduino, it should increment the 3 LEDs as if you were counting in binary.
