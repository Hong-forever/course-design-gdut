num = [1 2];
den = [1 2 2 1];

sys = tf(num, den);

%poles
poles = roots(den)

figure(1);
pzmap(sys);
grid;

t = 0:0.01:20;

figure(2);

%impulse response
h = impulse(sys, t);
subplot(2, 1, 1);
plot(t, h); grid;
title('Impulse Response');

%step response
u = step(sys, t);
subplot(2, 1, 2);
plot(t, u); grid;
title('Step Response');

figure(3);

%frequence response
[H, w] = freqs(num, den);
subplot(2, 1, 1);
plot(w, abs(H)); grid;    %amplitude
title('Amplitude Response');
subplot(2, 1, 2);
plot(w, angle(H)); grid;  %phase
title('Phase Response');
