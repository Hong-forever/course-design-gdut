ws = -6*pi; dw = 0.01; we = 6*pi;
w = ws:dw:we;       

N   = length(w);
F   = zeros(1, N);

A   = 1;    %amplitude
tau = 1;    %signal width
T0  = 0;    %timing right shift
w0  = 0;    %frequence right shift

%timing shifting
T0  = 1;

F = zeros(1, N);
for k=1:N
    r = @(t)rectpuls_para(t, w(k), A, tau, T0, w0);    %handle
    F(k) = integral(r, -0.5*tau+T0, 0.5*tau+T0);       %scaling result
end

subplot(2, 1, 1);
plot(w, real(F));
title('figure1: f(t-t0)');
grid on;

%timing shifting prove
T0  = 0;

for k=1:N
    r = @(t)rectpuls_para(t, w(k), A, tau, T0, w0);    %handle
    F(k) = integral(r, -0.5*tau+T0, 0.5*tau+T0);       %scaling result
end

T0  = 1;
F = F.*exp(-j*w*T0);

subplot(2, 1, 2);
plot(w, real(F));
title('figure2: F(jw)e**(-jwt0)');
grid on;

%frequence shifting
T0  = 0;
w0  = 5;

for k=1:N
    r = @(t)rectpuls_para(t, w(k), A, tau, T0, w0);    %handle
    F(k) = integral(r, -0.5*tau+T0, 0.5*tau+T0);       %scaling result
end

figure;
subplot(2, 1, 1);
plot(w, real(F));
title('figure3: f(t)e**(jw0t)');
grid on;

%frequence shifting prove
w0  = 0;

for k=1:N
    r = @(t)rectpuls_para(t, w(k), A, tau, T0, w0);    %handle
    F(k) = integral(r, -0.5*tau+T0, 0.5*tau+T0);       %scaling result
end

subplot(2, 1, 2);
plot(w, real(F));
title('figure4: F(j(w))');
grid on;
