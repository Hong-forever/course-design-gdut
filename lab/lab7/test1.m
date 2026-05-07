ws = 0; dw = 0.001; we = 10;
w = ws:dw:we;

a = [4 0];            %coefficient of output
b = [1 6 8];          %coefficient of input
H = freqs(a, b, w);   %frequence response

subplot(2, 1, 1);
plot(w, abs(H));
set(gca, 'ytick', [0 0.4 0.707 1]);grid on;
xlabel('\omega(rad/s)');ylabel('|H(j\omega)|');

subplot(2, 1, 2);
plot(w, angle(H));
set(gca, 'xtick', [0 1 2 3 4 5]);grid on
xlabel('\omega(rad/s)');ylabel('\phi(\omega)');


