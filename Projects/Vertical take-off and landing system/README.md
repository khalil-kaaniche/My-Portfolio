## Configuration

![](./media/image9.png)

*Communication configuration blocks*

[For the configuration part, we use the VISA configure Serial Port
block, having downloaded the necessary drivers beforehand.]{.mark}

[Then we create the control blocks and/or constants necessary for its
proper functioning: in our case we will specify]{.mark}

-   [The Visa Resource Name (to choose the appropriate COM port)]{.mark}

-   [The activation of a termination character to separate the different
    > messages during reception]{.mark}

-   [The baud rate which will be identical to the one used by the
    > microcontroller.]{.mark}

-   [The existence or not of a parity bit]{.mark}

-   [As well as the size of the UART payload]{.mark}

## Writing from LabVIEW

![](./media/image1.png)

*LabVIEW to STM32 write blocks*

[In our case, we have several variables to transmit from LabVIEW to the
microcontroller used:]{.mark}

-   [A boolean variable indicating the start or stop of the
    > system]{.mark}

-   [Real numbers containing the constants Kp, Ki and Kd of our
    > implemented PID.]{.mark}

-   [A float containing the instruction for tests.]{.mark}

[Therefore, it is necessary to separate the variables with \" \\n \" to
break up the message when receiving.]{.mark}

[So our frame of data to be sent is a character string containing the
variables to be sent separated by a predefined character \" \\n \" where
from the necessity to convert the variables into character strings and
to carry out a concatenation before sending it.]{.mark}

[It is necessary to implement on microcontroller an algorithm of
decomposition of the sent frame to be able to extract the data.]{.mark}

## Reading from LabVIEW

![](./media/image4.png)

*Blocks for reading data received from STM32*

[LabVIEW is used in our case to receive the measured angular position on
microcontroller.]{.mark}

[To solve communication problems, we have deliberately sent the measured
angle with an offset of + 90 degrees to ensure that the number is always
positive.]{.mark}

[This angle is processed in LabVIEW to be corrected and displayed on a
graph.]{.mark}

[From the received angles we drift twice to obtain respectively a speed
and an angular acceleration.]{.mark}

[We also perform a filtering on the calculated velocity to smooth the
obtained curve.]{.mark}

[Moreover, we use the angular position and the angular velocity to plot
the phase plane in real time by designating them respectively as X and
Y.]{.mark}

## Final result

### **Interfaces**

![](./media/image13.png)

*Screenshot of the control panel*

²![](./media/image2.png)

*PID control tab and angular position curve*

![](./media/image12.png)

*Filtered and unfiltered speed panel*

![](./media/image8.png)

*Acceleration panel*

![](./media/image11.png)

*Phase plan tab*

### **[Real time plot]{.mark}**

![](./media/image5.png)

*Angular position time plot*

![](./media/image3.png)

*Angular velocity curve*

![](./media/image10.png)

*Curve of the filtered angular velocity*

![](./media/image6.png)

*Angular acceleration*

![](./media/image7.png)

*Phase Diagram*
