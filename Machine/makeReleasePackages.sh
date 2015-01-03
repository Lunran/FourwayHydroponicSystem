#!/bin/bash
git archive --format=zip HEAD Float.stl > 1_FloatOnly_stl.zip
git archive --format=zip HEAD Cup.stl Float.stl > 2_FloatAndCup_stl.zip
git archive --format=zip HEAD Ceiling_can.stl Float.stl Pillar110.stl Pillar130.stl Pillar90.stl > 3_CanWithLED_stl.zip
git archive --format=zip HEAD Ceiling.stl Cup.stl Plate110.stl Plate90.stl Cover_slit.stl Float.stl Plate130.stl > 4_AllPrintedWithLED_stl.zip
git archive --format=zip HEAD *.rsdoc > DesignSparkMechanical_rsdoc.zip
git archive --format=zip HEAD *.gcode > Solidoodle2_gcode.zip
