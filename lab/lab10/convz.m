clear; clc
x = [-3, 4, 6, 0, -1];
y = [ 1, 1, 1, 1];

z = conv(x, y)

N = length(z);
stem(-1:N-2, z);
title('convz');