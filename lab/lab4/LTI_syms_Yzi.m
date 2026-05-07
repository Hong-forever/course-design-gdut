%from 3-8(3) Yzi

syms y(t) f(t) 

%input
f(t) = exp(-t);%.*heaviside(t);

%parameter
Dy  = diff(y, t);
D2y = diff(y, t, 2);

%initialcondition
Y0i = 5; DY0i = 2;    %Yzi

%Output: Yzi
eqi = D2y + 4*Dy + 8*y == 0;
cond = [y(0)==Y0i, Dy(0)==DY0i];
yzi= dsolve(eqi, cond);
disp('3-8(3)')
yzi= simplify(yzi);

ezplot(t, yzi);
title('Yzi');