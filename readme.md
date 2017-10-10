# Saleae SPI Analyzer With CS Results Field

This project is a fork of Saleae's SimpleAnalyzer which copies the [SpiAnalyzer](http://downloads.saleae.com/betas/1.1.32/SaleaeAnalyzerSdk-1.1.32.zip) 
and adds the functionality of a new result field. This modified analyzer adds 
a Chip Select (CS) field to the result file which is used as a CS active delimiter. 
When CS goes active, a "1" is written to the first frame and a "0" is added to all 
subsiquent frames results for that active period. This added field is used to help 
with the reconstruction of an SPI command, since most write operations and read 
opperations are terminated by CS going to an inactive state.
