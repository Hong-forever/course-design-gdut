syms s t;

a2 = 1; a1 = 4; a0 = 3;     %Y
a = a2*s^2 + a1*s + a0

b1 = 2; b0 = 1;             %F
b = (b1*s + b0);

Hs = a/b;                   %H

f = heaviside(t);
Fs = laplace(f, t, s);

figure;

Ys_s = Fs*Hs;
yt_s = ilaplace(Ys_s, s, t);
subplot(3, 1, 1);
ezplot(yt_s, [0, 10]);
title('Zero state response');

cond = [1 2];   %initial condition
Ys_i = (cond(1)*s*a2 + cond(2)*a2 + cond(1)*a1)/a;
yt_i = ilaplace(Ys_i, s, t);
subplot(3, 1, 2);
ezplot(yt_i, [0, 10]);
title('Zero input response');

Ys = Ys_s + Ys_i;
yt = ilaplace(Ys, s, t);
yt = simplify(yt)
subplot(3, 1, 3);
ezplot(yt, [0, 10]);
title('Complete response');
