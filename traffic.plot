#!/usr/bin/env gnuplot

set terminal png
set output 'traffic.png'

set grid
set style data lines
set terminal png size 640,480
set timefmt "%s"
set xdata time
set xlabel " "
set ylabel ""

#
# Initialize a running sum
#
init(x) = (back1 = back2 = back3 = back4 = back5 = back6 = back7 = back8 = back9 = back10 = sum = 0)

sum10(x) = (shift10(x), (back1+back2+back3+back4+back5+back6+back7+back8+back9+back10))
shift10(x) = (back10 = back9, back9 = back8, back8 = back7, back7 = back6, back6 = back5, back5 = back4, back4 = back3, back3 = back2, back2 = back1, back1 = x)

#
# Plot data, running average and cumulative average
#

plot sum = init(0), "traffic.dat" using 1:(sum10($2)) title "Kringlan, northbound, 10-min moving sum"
