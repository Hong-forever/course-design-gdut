%from 3-7(5) Yzs

syms y(t) f(t) 

%input
f(t) = exp(-2*t);%.*heaviside(t);

%parameter
Dy  = diff(y, t);
D2y = diff(y, t, 2);

%initialcondition
Y0s = 0; DY0s = 0;    %Yzs

%Output: Yzi
eqs = D2y + 4*Dy + 3*y == f;
conds = [y(0)==Y0s, Dy(0)==DY0s];
yzs= dsolve(eqs, conds);
disp('3-7(5)')
yzs= simplify(yzs)

ezplot(t, yzs);
grid on;
title('Yzs');