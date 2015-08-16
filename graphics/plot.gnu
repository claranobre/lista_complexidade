set boxwidth 0.5
set terminal png
set output "linear.png"
set style fill solid
set logscale y 2
set key on inside left top
set xlabel 'quantidade de elementos'
set ylabel 'log2(tempo)'
set grid
plot "data.txt" using 1:3:xtic(2) with boxes title 'tempo'
