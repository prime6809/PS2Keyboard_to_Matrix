#
# Makefile for PS2 keboard
#

all: atom trs80 dragon zx81 spectrum bbc

atom: FORCE
	make -f Makefile.main TARGET=atom 
	
trs80: FORCE	
	make -f Makefile.main TARGET=trs80
	
dragon: FORCE
	make -f Makefile.main TARGET=DragonCoCo
	
coco: FORCE
	make -f Makefile.main TARGET=DragonCoCo

zx81: FORCE
	make -f Makefile.main TARGET=zx81
	
spectrum: FORCE
	make -f Makefile.main TARGET=spectrum
	
bbc: FORCE
	make -f Makefile.main TARGET=bbc
	
bbcmaster: FORCE
	make -f Makefile.main TARGET=bbcmaster

electron: FORCE
	make -f Makefile.main TARGET=electron

clean:
	

#	make -f Makefile.main TARGET=atom clean
#	make -f Makefile.main TARGET=trs80 clean
#	make -f Makefile.main TARGET=dragon clean

FORCE: