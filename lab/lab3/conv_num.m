%parameter
st = -1; dt = 0.001; en = 3;
t = st:dt:en
T0 = 1; tau = 1;

%u(t)-u(t-1)
ft1 = rectpuls(t-1.5*T0, tau);
subplot(3, 1, 1);
plot(t, ft1);
axis([-1, 7, -0.5, 1.5]);
title('u(t-1)-u(t-2)');

%u(t)-u(t-2)
ft2 = rectpuls(t-T0, 2*tau);
subplot(3, 1, 2);
plot(t, ft2);
axis([-1, 7, -0.5, 1.5]);
title('u(t)-u(t-2)');

% %convolution
% h = conv(ft1, ft2);
% h = h.*dt;
% N = length(h);
% subplot(3, 1, 3);
% plot(st-1:dt:2*en, h);
% axis([-1, 7, -0.5, 1.5]);
% title('conv');

%convolution
h = conv(ft1, ft2);
%h = h.*dt;
N = length(h);
subplot(3, 1, 3);
plot(st-1:dt:2*en, h);
axis([-1, 7, -500, 1500]);
title('mistake value');
