To put things into context , this was my first project I made on STM32 after learning the basics during my first internship.
It consists on implementing a hybrid MIDI keyboard and monophonic Synthesizer. It uses an LCD Screen useful for the user, buttons for configuration and buttons for playing the notes.

Remarks :

- The sound it produces is the combination of 3 oscillators , each one of them has it's own volume and can be either a sine, square, triangle, or sawtooth.
- A simple ADSR envelope was implemented
- DMA is used for the DAC 
- IT is used for UART
- For the midi keyboard, we can change the octave and alternate between chromatic and modal mode with the ability to choose which scale to play.
