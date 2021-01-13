#!/bin/bash

TARGETS="atom bbc bbcmaster dragon_coco electron trs80 zx81 zx spectrum"

for TARGET in $TARGETS
do
  make TARGET=$TARGET clean
done