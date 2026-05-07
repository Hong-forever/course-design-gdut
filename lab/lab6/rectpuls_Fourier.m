%rectpuls Fourier
ws = -6*pi; dw = 0.01; we = 6*pi;
w = ws:dw:we;       

N   = length(w);
F = zeros(1, N);

A   = 1;    %amplitude
tau = 1;    %signal width
T0  = 0;    %timing right shift
w0  = 0;    %frequence right shift

for k=1:N
    r = @(t)rectpuls_para(t, w(k), A, tau, T0, w0);    %handle
    F(k) = integral(r, -0.5*tau+T0, 0.5*tau+T0);       %scaling result
end

subplot(2, 1, 1);
plot(w, real(F));
title('F(jw)');
grid on;

subplot(2, 1, 2);
plot(w, real(F)-sinc(w/2/pi));  %error
title('error');
grid on;
