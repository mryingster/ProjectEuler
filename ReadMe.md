Project Euler
=============

Description
-----------
Project Euler is a series of challenging mathematical/computer programming problems that will require more than just mathematical insights to solve. Although mathematics will help you arrive at elegant and efficient methods, the use of a computer and programming skills will be required to solve most problems.

This repository contains a collection of programmatic solutions to some of the problems posed by [Project Euler](http://projecteuler.net).

Most of the solutions will be in C or Python.

Dependencies
------------
  * math - Some solutions require the math lib.

Compiling
---------
C, C++, and Swift based solutions can be compiled directly in emacs using the `M^x compile` command.

Table of Results
----------------
The following table shows solution times for the first 100 solutions in this repository.

| Problem        | C/C++          | Swift          | Python         | Perl           | Lua            | Rust           | Bash           |
| -------------- | -------------- | -------------- | -------------- | -------------- | -------------- | -------------- | -------------- |
| 001            | 0:00:00.023700 | 0:00:00.022145 | 0:00:00.036175 | 0:00:00.014125 | 0:00:00.006909 | 0:00:00.004600 | 0:00:00.045782 |
| 002            | 0:00:00.021320 | 0:00:00.023298 | 0:00:00.066459 | 0:00:00.050276 | 0:00:00.032810 | 0:00:00.004513 | 0:00:00.005196 |
| 003            | 0:00:00.015521 | 0:00:00.026744 | 0:00:00.071715 | 0:00:00.047873 | 0:00:00.017318 | 0:00:00.008033 | 0:00:00.220436 |
| 004            | 0:00:00.053282 | 0:00:00.027583 | 0:00:00.672572 | 0:00:00.947137 | 0:00:01.010225 | 0:00:00.147732 | 0:00:17.803932 |
| 005            | 0:00:00.202865 | 0:00:00.951799 | 0:00:00.036577 | 0:00:00.014752 | 0:00:02.939756 | 0:00:01.486230 | 0:00:00.023822 |
| 006            | 0:00:00.016310 | 0:00:00.026484 | 0:00:00.087101 | 0:00:00.034411 | 0:00:00.057354 | 0:00:00.071757 | 0:00:00.008297 |
| 007            | 0:00:00.039729 | 0:00:00.057680 | 0:00:00.434027 | 0:00:00.349381 | 0:00:00.088811 | 0:00:00.149443 | 0:01:36.418176 |
| 008            | 0:00:00.024648 | 0:00:00.176265 | 0:00:00.076607 | 0:00:00.025188 | 0:00:00.041690 | 0:00:00.041268 | 0:00:00.362007 |
| 009            | 0:00:00.020563 | 0:00:00.035303 | 0:00:00.154119 | 0:00:00.102630 | 0:00:00.067331 | 0:00:00.027587 | 0:05:43.567932 |
| 010            | 0:00:00.278203 | 0:00:01.416638 | 0:00:03.070483 | 0:00:24.628949 | 0:00:04.021126 | 0:00:06.025021 | 0:03:16.035233 |
| 011            | 0:00:00.002740 | 0:00:00.058874 | 0:00:00.019406 |                |                |                |                |
| 012            | 0:00:00.116175 | 0:00:00.048960 | 0:00:00.318192 |                | 0:00:02.464054 |                |                |
| 013            | 0:00:00.002619 | 0:00:00.060091 | 0:00:00.011859 |                |                |                |                |
| 014            | 0:00:00.078174 | 0:00:00.319065 | 0:00:05.660329 |                |                |                |                |
| 015            | 0:00:00.002527 | 0:00:00.024859 | 0:00:00.013979 |                |                |                |                |
| 016            | 0:00:00.006863 | 0:00:00.052554 | 0:00:00.011291 |                |                |                |                |
| 017            | 0:00:00.002290 | 0:00:00.026859 | 0:00:00.015913 |                |                |                |                |
| 018            | 0:00:00.002568 | 0:00:00.041671 | 0:00:00.014107 |                |                |                |                |
| 019            | 0:00:00.002870 | 0:00:00.030209 | 0:00:00.111018 |                |                |                |                |
| 020            | 0:00:00.003553 | 0:00:00.232329 | 0:00:00.011232 |                |                |                |                |
| 021            | 0:00:00.202949 | 0:00:00.651905 | 0:00:05.411643 |                |                |                |                |
| 022            | 0:00:00.006091 |                | 0:00:00.033456 |                |                |                |                |
| 023            | 0:00:01.599429 | 0:00:11.638328 | 0:00:14.347456 |                | 0:00:12.166444 |                |                |
| 024            | 0:02:10.358997 | 0:00:01.680871 | 0:00:01.607859 |                |                |                |                |
| 025            | 0:00:00.117813 | 0:00:02.440728 | 0:00:01.108789 |                |                |                |                |
| 026            | 0:00:00.216526 | 0:00:00.408809 | 0:00:02.610010 |                |                |                |                |
| 027            | 0:00:00.091880 | 0:00:00.228419 | 0:00:06.280078 |                |                |                |                |
| 028            | 0:00:00.002220 | 0:00:00.038519 | 0:00:00.035450 |                |                |                |                |
| 029            | 0:00:05.373987 | 0:00:00.031027 | 0:00:01.643259 |                |                |                |                |
| 030            | 0:00:00.024765 | 0:00:00.166017 | 0:00:00.874295 |                |                |                |                |
| 031            | 0:00:00.617835 |                | 0:00:00.560910 |                |                |                |                |
| 032            | 0:00:00.479682 | 0:00:01.871179 | 0:00:00.253120 |                |                |                |                |
| 033            | 0:00:00.022361 |                | 0:00:00.455147 |                |                |                |                |
| 034            | 0:00:00.178932 | 0:00:00.427583 | 0:00:00.237060 |                |                |                |                |
| 035            | 0:00:00.180962 | 0:00:00.671565 | 0:00:06.386922 |                |                |                |                |
| 036            | 0:00:00.146492 | 0:00:00.422807 | 0:00:01.497447 |                |                |                |                |
| 037            | 0:00:00.118991 | 0:00:00.591754 | 0:00:46.532001 |                |                |                |                |
| 038            | 0:00:00.029732 | 0:00:00.049483 | 0:00:00.068089 |                |                |                |                |
| 039            | 0:00:00.032912 | 0:00:00.082862 | 0:00:00.609893 |                |                |                |                |
| 040            | 0:00:00.063484 |                | 0:00:00.152899 |                |                |                |                |
| 041            | 0:00:00.018994 |                |                |                |                |                |                |
| 042            | 0:00:00.006188 |                |                |                |                |                |                |
| 043            | 0:02:14.071139 |                |                |                |                |                |                |
| 044            | 0:00:00.100103 |                |                |                |                |                |                |
| 045            | 0:00:00.021272 |                |                |                |                |                |                |
| 046            | 0:00:00.257181 |                |                |                |                |                |                |
| 047            | 0:00:00.327025 |                |                |                |                |                |                |
| 048            | 0:00:00.023826 |                |                |                |                |                |                |
| 049            | 0:00:00.126521 |                |                |                |                |                |                |
| 050            | 0:00:00.019945 |                |                |                |                |                |                |
| 051            | 0:00:00.040634 |                |                |                |                |                |                |
| 052            | 0:00:00.109129 |                |                |                |                |                |                |
| 053            | 0:00:00.051840 |                | 0:00:00.098956 |                |                |                |                |
| 054            | 0:00:00.038027 |                | 0:00:00.179419 |                |                |                |                |
| 055            | 0:00:00.089322 |                | 0:00:00.361829 |                |                |                |                |
| 056            | 0:00:02.295887 |                |                |                |                |                |                |
| 057            | 0:00:00.045334 |                |                |                |                |                |                |
| 058            | 0:00:06.572859 |                |                |                |                |                |                |
| 059            | 0:00:00.034743 |                |                |                |                |                |                |
| 060            | 0:00:01.592703 |                | 0:02:38.230711 |                |                |                |                |
| 061            | 0:00:00.029174 |                |                |                |                |                |                |
| 062            | 0:00:00.157508 |                | 0:00:00.557340 |                |                |                |                |
| 063            | 0:00:00.022325 |                | 0:00:00.126408 |                |                |                |                |
| 064            | 0:00:00.033439 |                |                |                |                |                |                |
| 065            | 0:00:00.040305 |                | 0:00:00.053426 |                |                |                |                |
| 066            |                |                | 0:00:00.071403 |                |                |                |                |
| 067            | 0:00:00.056913 |                |                |                |                |                |                |
| 068            | 0:00:00.010274 |                |                |                |                |                |                |
| 069            | 0:00:00.032145 |                | 0:00:00.064356 |                |                |                |                |
| 070            | 0:00:00.821101 |                |                |                |                |                |                |
| 071            | 0:00:00.092790 |                | 0:00:18.216635 |                |                |                |                |
| 072            | 0:00:00.058104 |                |                |                |                |                |                |
| 073            | 0:00:16.214891 |                | 0:00:18.179356 |                |                |                |                |
| 074            |                |                | 0:00:08.004184 |                |                |                |                |
| 075            | 0:00:00.833407 |                |                |                |                |                |                |
| 076            | 0:01:34.226529 |                |                |                |                |                |                |
| 077            | 0:00:00.028811 |                |                |                |                |                |                |
| 078            |                |                | 0:00:22.240010 |                |                |                |                |
| 079            |                |                | 0:00:00.071690 |                |                |                |                |
| 080            |                |                | 0:00:00.056804 |                |                |                |                |
| 081            | 0:00:00.024156 |                |                |                |                |                |                |
| 082            | 0:00:00.053518 |                |                |                |                |                |                |
| 083            | 3:10:30.644403 |                |                |                |                |                |                |
| 084            | 0:00:00.020586 |                |                |                |                |                |                |
| 085            |                |                | 0:00:15.484017 |                |                |                |                |
| 086            | 0:05:05.740156 |                |                |                |                |                |                |
| 087            |                |                | 0:00:02.475497 |                |                |                |                |
| 088            | 0:00:05.736287 |                |                |                |                |                |                |
| 089            |                |                | 0:00:00.116556 |                |                |                |                |
| 090            | 0:00:00.028009 |                |                |                |                |                |                |
| 091            |                |                | 0:00:00.162818 |                |                |                |                |
| 092            | 0:00:03.869686 |                |                |                |                |                |                |
| 093            | 0:00:00.043686 |                |                |                |                |                |                |
| 094            |                |                | 0:00:00.046959 |                |                |                |                |
| 095            | 0:00:00.273689 |                |                |                |                |                |                |
| 096            | 0:00:01.156366 |                |                |                |                |                |                |
| 097            | 0:00:00.071275 |                |                |                |                |                |                |
| 098            |                |                | 0:00:05.051417 |                |                |                |                |
| 099            |                |                | 0:00:00.093380 |                |                |                |                |
| 100            |                |                | 0:00:00.051333 |                |                |                |                |
