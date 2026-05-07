R = 10; k = 0:R-1;

a = [1, -1/4];
b = [1];

h = impz(b, a, k);    
subplot(2, 1, 1);
stem(k, h);
title('h[k]');

%standard answer
h_ref = (0.25).^k;
subplot(2, 1, 2);
stem(k, h_ref);
title('href[k]');