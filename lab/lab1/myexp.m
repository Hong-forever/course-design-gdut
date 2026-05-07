A = 1;
a = -0.2;
t = 0:0.01:10;

%Ae^(at)
Fe = A*exp(a*t)
plot(t, Fe);
title('Fe: exp');
