#!/bin/sh
perl -p fixups.re SOS13Src.orig.txt > SOS13Src.txt
python3 clipper.py
