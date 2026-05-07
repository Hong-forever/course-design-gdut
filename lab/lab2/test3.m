t = -3:0.01:3;

%example
ftri = tripuls(t, 4, 0.5); 
subplot(3, 1, 1);
plot(t, ftri);
title('Example');

%addition
fa = ftri + 5;
subplot(3, 1, 2);
plot(t, fa);
title('addition');

%multiplication
fm = ftri .* ftri;
subplot(3, 1, 3);
plot(t, fm);
title('multiplication');