set term png size 800,800
set output "./temp.png"

#set view map
#set dgrid3d
#set pm3d interpolate 16,16

#splot "./temp.dat" u 1:2:3 with pm3d
#plot "./temp.dat" u 1:2:3 with points pointtype 7 palette

set hidden3d
set dgrid3d 60,60 qnorm 5
splot "./temp.dat" with lines
