R = 30; k = 0:R-1;

f = (-1).^k;
a = [1, -1/4];
b = [1];

y = filter(b, a, f);    
subplot(2, 1, 1);
stem(k, y);
title('Yzs[k]');

%standard answer
y_ref = (0.2.*((0.25).^k) + 0.8.*((-1).^k));
subplot(2, 1, 2);
stem(k, y_ref);
title('Yref[k]');