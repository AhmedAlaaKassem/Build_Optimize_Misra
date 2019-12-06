-RAM_Consumption
we reduced the RAM consumption by using PROGMEM Attribute for all global arrays defined in the program 
Reduced the ram consumption from 750 bytes to 48 bytes
_IMP NOTE_ 
when initialize the local arrays in main with its size, the size of Static RAM reach 0% , as all variables pushed on stack.


-MISRA requirment
we reduced Misra warnings to 6 warnings , but 5 of them were about the target chosen in codecomposser as we should use atmega AVR target
the last Misra warning about the data type definition.
All warnings about pointer arithmetic were discarded as we consider them as justification for the project.