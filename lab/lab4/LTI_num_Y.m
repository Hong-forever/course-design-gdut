%from 3-7(6)

ts = 0; dt = 0.01; te = 5;
t = ts:dt:te;

%input
f = exp(-2*t).*heaviside(t);

%equation
a = [1, 4, 3]; b = [2, 1];
sys = tf(b, a);

%num
y_num = lsim(sys, f, t);    %output
subplot(2, 1, 1);
plot(t, y_num);
axis([0, 3, -0.25, 0.5]);
title('Ynum');
grid on;

%conv
h = impulse(sys, t);        %impulse response
y_conv = conv(h, f).*dt;     %output
subplot(2, 1, 2);
plot(ts:dt:2*te, y_conv);
axis([0, 3, -0.25, 0.5]);
title('Yconv');
grid on;