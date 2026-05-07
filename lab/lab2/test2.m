
t0 = 0.001;
st = -3; en = 3;
t = st:t0:en;

%example
ftri = tripuls(t, 4, 0.5); 
subplot(3, 1, 1);
plot(t, ftri);
title('Example');

%differentiation
yd = diff(mytri(t))/t0;
subplot(3, 1, 2);
plot(t(1:length(t)-1), yd);
title('differentiation');

%integration
for x = 1:length(t)
    yq(x) = quad(@mytri, st, t(x));
end
subplot(3, 1, 3);
plot(t, yq);
title('integration');