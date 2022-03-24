#!/bin/bash

TARGETS="atom bbc bbcmaster commodore dragon_coco dragon_beta electron spectrum trs80 zx81"

for TARGET in $TARGETS
do
  make TARGET=$TARGET clean
done