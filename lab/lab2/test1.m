
t = -3:0.01:3;

%example
ftri = tripuls(t, 4, 0.5); 
subplot(2, 2, 1);
plot(t, ftri);
title('figure1: example');

%scaling
ft1 = tripuls(2*t, 4, 0.5); 
subplot(2, 2, 2);
plot(t, ft1);
title('figure2: scaling');

%flipping
ft2 = tripuls(-t, 4, 0.5); 
subplot(2, 2, 3);
plot(t, ft2);
title('figure3: flipping');

%time shifting
ft3 = tripuls(t-1, 4, 0.5); 
subplot(2, 2, 4);
plot(t, ft3);
title('figure4: time shifting');
