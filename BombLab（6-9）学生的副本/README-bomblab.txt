#######################################################
# CS:APP Bomb Lab
# Directions to Instructors
#
# Copyright (c) 2002-2013, R. Bryant and D. O'Hallaron
#
#######################################################

This directory contains the files that you will use to build and run
the CS:APP Bomb Lab. The Bomb Lab teaches students principles of
machine-level programs, as well as general debugger and reverse
engineering skills.

***********
1. Overview
***********

----
1.1. Binary Bombs
----
A "binary bomb" is a Linux executable C program that consists of six
"phases." Each phase expects the student to enter a particular string
on stdin.  If the student enters the expected string, then that phase
is "defused."  Otherwise the bomb "explodes" by printing "BOOM!!!".
The goal for the students is to defuse as many phases as possible.


----
1.2. Solving Binary Bombs
----
In order to defuse the bomb, students must use a debugger, typically
gdb or ddd, to disassemble the binary and single-step through the
machine code in each phase. The idea is to understand what each
assembly statement does, and then use this knowledge to infer the
defusing string.  Students earn points for defusing phases, and they
lose points (configurable by the instructor, but typically 1/2 point)
for each explosion. Thus, they quickly learn to set breakpoints before
each phase and the function that explodes the bomb. It's a great
lesson and forces them to learn to use a debugger.


