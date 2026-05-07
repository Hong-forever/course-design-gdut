clear; clc;
ts = 0; dt = 0.001; te = 5;
t = ts:dt:te;

%input
w0 = 3;
f = cos(w0*t).*heaviside(t);

%frequence response
Hw0 = j*4*w0/((j*w0)^2+(j*6*w0)+8)

%output
y = abs(Hw0).*cos(w0*t+angle(Hw0));

subplot(2, 1, 1);
plot(t, f);
grid on;
xlabel('t/s');
ylabel('f');

subplot(2, 1, 2);
plot(t, y);
grid on;
xlabel('t/s');
ylabel('y');