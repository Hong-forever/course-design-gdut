
%Lap parameter
num = [1 0 0];
den = conv([1 1], [1 5 25]);    %convolution to multiply

[r p k] = residue(num, den)

ampr = abs(r)
angr = angle(r)
