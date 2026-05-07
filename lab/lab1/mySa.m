t = -4.5*pi:pi/100:4.5*pi;

%Sa(t)
FSa = sinc(t/pi);
plot(t, FSa);
title('FSa: Sa');
