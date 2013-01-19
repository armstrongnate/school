16.times do |i|
	#puts "Mux(a=a[#{i}], b=b[#{i}], sel=sel, out=out[#{i}]);"
	#puts "Mux(in=in["+i.to_s+"], out=out["+i.to_s+"]);"
	puts 	"Mux16(a=a[#{i}], b=b[#{i}], sel=sel[0], out=xout#{i});\nMux16(a=c[#{i}], b=d[#{i}], sel=sel[0], out=yout#{i});\nMux16(a=xout#{i}, b=yout#{i}, sel=sel[1], out=out#{i});"
	end