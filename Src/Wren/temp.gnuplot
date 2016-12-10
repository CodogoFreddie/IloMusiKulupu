set term png
set output "./temp.png"

set view map
set dgrid3d
set pm3d interpolate 16,16

splot "./temp.dat" u 1:2:3 with pm3d
