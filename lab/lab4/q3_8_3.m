syms y(t) f(t) 
%input
f(t) = exp(-t).*heaviside(t);

%parameter
Df  = diff(f, t);
Dy  = diff(y, t);
D2y = diff(y, t, 2);

%initialcondition
Y0i = 5; DY0i = 2;    %Yzi
Y0s = 0; DY0s = 0;    %Yzs

%Output: Yzi
eqi = D2y + 4*Dy + 8*y == 0;
cond = [y(0)==Y0i, Dy(0)==DY0i];
yzi= dsolve(eqi, cond);
yzi= simplify(yzi)

%Output: Yzs      这里有问题。Df求导出错？
eqs = D2y + 4*Dy + 8*y == 15*Df + 5*f;
cond = [y(0)==Y0s, Dy(0)==DY0s];
yzs= dsolve(eqs, cond);
yzs= simplify(yzs)

