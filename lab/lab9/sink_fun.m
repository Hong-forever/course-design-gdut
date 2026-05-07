k = 0:40;
subplot(2, 1, 1);
stem(k, cos(0.1*pi*k));
title('cos(0.1\pik)');

subplot(2, 1, 2);
stem(k, sin(0.1*pi*k));
title('sin(0.1\pik)');