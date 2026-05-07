k = 0:100

a = 0; w0 = 0.1*pi;
e = exp((j*w0)*k);

subplot(3, 1, 1);
stem(k, e);
title('exp((j0.1\pi)k)');

a = 0.03;
e = exp((a+j*w0)*k);
subplot(3, 1, 2);
stem(k, e);
title('exp((0.03+j0.1\pi)k)');

a = -0.03;
e = exp((a+j*w0)*k);
subplot(3, 1, 3);
stem(k, e);
title('exp((-0.03+j0.1\pi)k)');