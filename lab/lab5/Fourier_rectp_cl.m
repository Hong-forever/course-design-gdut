clear; clc;
%parameter
N = 10;

n1 = -N:N;
cn = -4*j*sin(n1*pi/2)/pi^2./n1.^2

figure;
subplot(2, 1, 1);
stem(n1, abs(cn));   %amplitude
title('amplitude');
subplot(2, 1, 2);
stem(n1, angle(cn)); %phase
title('phase');