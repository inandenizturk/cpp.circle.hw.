#!/bin/sh
gnuplot --persist << 'EOF'

set ticslevel 0
set size 0.80,1.00

plot "circle.dat" using 1:($3==1?$2:1/0) w p pt 3
replot "circle.dat" using 1:($3==0?$2:1/0) w p pt 7

#plot "circle.dat" using 1:2 w p pt 7

EOF
