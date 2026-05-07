A = 1;
w0 = 2*pi;
phi = pi/3;
t = -1:0.01:1;

%Asin(w0t+φ)
F1 = A*sin(w0*t+phi);
subplot(2, 1, 1);
plot(t, F1);
title('F1: sin');

%Acos(w0t+φ)
F2 = A*cos(w0*t+phi);
subplot(2, 1, 2);
plot(t, F2);
title('F2: cos');
