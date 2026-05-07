k0 = 0; k1 = -50; k2 = 50; A = 1;

figure;
[f, k] = stepseq(k0, k1, k2, A);
subplot(3, 1, 1);
stem(k, f);
axis([-50 50 -0.25 1.25]);
title('u[k]');

kn = 10;
[ft, k] = stepseq(k0+kn, k1, k2, A);
subplot(3, 1, 2);
stem(k, ft);
axis([-50 50 -0.25 1.25]);
title('u[k-kn]');

fr= f - ft;
subplot(3, 1, 3);
stem(k, fr);
axis([-50 50 -0.25 1.25]);
title('r[k]');