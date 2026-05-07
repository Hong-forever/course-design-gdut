%symbolic
syms t s tau

%function
f(t) = heaviside(t) - heaviside(t-1);   %u(t)-u(t-1)
g(s) = heaviside(s) - heaviside(s-2);   %u(t)-u(t-2)

%conv
h(t) = int(f(tau) * g(t - tau), tau, 0, t);

%simplification
h = simplify(h);

subplot(3, 1, 1);
ezplot(f, [-1, 4]);
title('u(t)-u(t-1)');

subplot(3, 1, 2);
ezplot(g, [-1, 4]);
title('u(t)-u(t-2)');

subplot(3, 1, 3);
ezplot(h, [-1, 4]);
title('convolution');
